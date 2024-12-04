module DataCache #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32
)(
    input logic clk,
    input logic we,                  // Write enable
    input logic [2:0] LS_mode,  
    input logic MemRead,          
    input logic [ADDR_WIDTH-1:0] a,    // Address
    input logic [DATA_WIDTH-1:0] wd,  // Write data

    output logic [DATA_WIDTH-1:0] rd  // Read data
);

typedef struct packed {
    logic valid_bit;
    logic [26:0] tag_bits;
    logic [7:0] byte3;
    logic [7:0] byte2;
    logic [7:0] byte1;
    logic [7:0] byte0;
} cache_line;

cache_line cache_mem [8];

logic [DATA_WIDTH-1:0] temp_rd;
logic [26:0] address_tag;
logic [2:0] cache_index;
logic [1:0] byte_offset;

// Cache read operation
always_comb begin
    address_tag = a[ADDR_WIDTH-1:5];
    cache_index = a[4:2];
    byte_offset = a[1:0];

    if (cache_mem[cache_index].valid_bit && cache_mem[cache_index].tag_bits == address_tag) begin
        rd = {
            cache_mem[cache_index].byte3,
            cache_mem[cache_index].byte2,
            cache_mem[cache_index].byte1,
            cache_mem[cache_index].byte0
        };
    end 
    
    else begin
        rd = temp_rd;
    end

end


// Cache write and memory update logic
always_ff @(posedge clk) begin
    if (we) begin
        cache_mem[cache_index].valid_bit <= 1;
        cache_mem[cache_index].tag_bits <= a[31:5];
        
        case (LS_mode)
            // Word write mode
            `W_MODE: begin
                cache_mem[cache_index].byte3 <= wd[31:24];
                cache_mem[cache_index].byte2 <= wd[23:16];
                cache_mem[cache_index].byte1 <= wd[15:8];
                cache_mem[cache_index].byte0 <= wd[7:0];
            end

            // Byte write mode
            `B_MODE, `UB_MODE: begin
                case (byte_offset)
                    2'b11: cache_mem[cache_index].byte3 <= wd[7:0];
                    2'b10: cache_mem[cache_index].byte2 <= wd[7:0];
                    2'b01: cache_mem[cache_index].byte1 <= wd[7:0];
                    2'b00: cache_mem[cache_index].byte0 <= wd[7:0];
                endcase
            end

            // Halfword write mode
            `H_MODE, `UH_MODE: begin
                case (byte_offset)
                    2'b00: begin
                        cache_mem[cache_index].byte1 <= wd[15:8];
                        cache_mem[cache_index].byte0 <= wd[7:0];
                    end
                    2'b10: begin
                        cache_mem[cache_index].byte3 <= wd[15:8];
                        cache_mem[cache_index].byte2 <= wd[7:0];
                    end
                    default: $error("Misaligned halfword write detected!");
                endcase
            end

            default: $display("WARNING: Unrecognized LS_mode in cache");
        endcase
    end 
    
    else if (MemRead && (!cache_mem[cache_index].valid_bit || cache_mem[cache_index].tag_bits != address_tag)) begin
        // Update cache line with data from main memory
        cache_mem[cache_index].valid_bit <= 1;
        cache_mem[cache_index].tag_bits <= a[31:5];

        cache_mem[cache_index].byte3 <= temp_rd[31:24];
        cache_mem[cache_index].byte2 <= temp_rd[23:16];
        cache_mem[cache_index].byte1 <= temp_rd[15:8];
        cache_mem[cache_index].byte0 <= temp_rd[7:0];
    end


    if (we && (LS_mode[2:1] == 2'b01) && !(cache_mem[cache_index].tag_bits == address_tag)) begin
        case (byte_offset)
            2'b11: begin
                cache_mem[cache_index].byte2 <= temp_rd[23:16];
                cache_mem[cache_index].byte1 <= temp_rd[15:8];
                cache_mem[cache_index].byte0 <= temp_rd[7:0];
            end
            2'b10: begin
                cache_mem[cache_index].byte3 <= temp_rd[31:24];
                cache_mem[cache_index].byte1 <= temp_rd[15:8];
                cache_mem[cache_index].byte0 <= temp_rd[7:0];
            end
            2'b01: begin
                cache_mem[cache_index].byte3 <= temp_rd[31:24];
                cache_mem[cache_index].byte2 <= temp_rd[23:16];
                cache_mem[cache_index].byte0 <= temp_rd[7:0];
            end
            2'b00: begin
                cache_mem[cache_index].byte3 <= temp_rd[31:24];
                cache_mem[cache_index].byte2 <= temp_rd[23:16];
                cache_mem[cache_index].byte1 <= temp_rd[15:8];
            end
        endcase
    end
end


datamem data_memory(
    .clk(clk),
    .we(we),
    .LS_mode(LS_mode),
    .a(a),
    .wd(wd),
    .rd(temp_rd)
);

endmodule
