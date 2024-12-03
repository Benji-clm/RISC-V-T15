module DataCache #(
    parameter addr_width = 32,
    parameter data_width = 32,
    parameter num_cache_lines = 8
)(
    input logic clk,
    input logic we,                  // Write enable
    input logic [2:0] funct3,  
    input logic MemRead,          
    input logic [addr_width-1:0] daddr,    // Address
    input logic [data_width-1:0] wd_data,  // Write data

    output logic cache_hit,                // Cache hit signal
    output logic [data_width-1:0] rd_data  // Read data
);

typedef struct packed {
    logic valid_bit;
    logic [26:0] tag_bits;
    logic [7:0] byte3;
    logic [7:0] byte2;
    logic [7:0] byte1;
    logic [7:0] byte0;
} cache_line;

cache_line cache_mem [num_cache_lines];

logic [data_width-1:0] temp_rd_data;
logic [26:0] address_tag;
logic [2:0] cache_index;
logic [1:0] byte_offset;

// Cache read operation
always_comb begin
    address_tag = daddr[addr_width-1:5];
    cache_index = daddr[4:2];
    byte_offset = daddr[1:0];

    if (cache_mem[cache_index].valid_bit && cache_mem[cache_index].tag_bits == address_tag) begin
        cache_hit = 1;
        rd_data = {
            cache_mem[cache_index].byte3,
            cache_mem[cache_index].byte2,
            cache_mem[cache_index].byte1,
            cache_mem[cache_index].byte0
        };
    end else begin
        cache_hit = 0;
        rd_data = temp_rd_data;
    end
end

// Cache write and memory update logic
always_ff @(posedge clk) begin
    if (we) begin
        cache_mem[cache_index].valid_bit <= 1;
        cache_mem[cache_index].tag_bits <= daddr[31:5];
        
        case (funct3)
            // Byte write operations
            3'b000, 3'b001: begin
                case (byte_offset)
                    2'b11: cache_mem[cache_index].byte3 <= wd_data[7:0];
                    2'b10: cache_mem[cache_index].byte2 <= wd_data[7:0];
                    2'b01: cache_mem[cache_index].byte1 <= wd_data[7:0];
                    2'b00: cache_mem[cache_index].byte0 <= wd_data[7:0];
                endcase
            end
            // Word write operation
            default: begin
                cache_mem[cache_index].byte3 <= wd_data[31:24];
                cache_mem[cache_index].byte2 <= wd_data[23:16];
                cache_mem[cache_index].byte1 <= wd_data[15:8];
                cache_mem[cache_index].byte0 <= wd_data[7:0];
            end
        endcase
    end else if (!cache_mem[cache_index].valid_bit || cache_mem[cache_index].tag_bits != address_tag) begin
        cache_mem[cache_index].valid_bit <= 1;
        cache_mem[cache_index].tag_bits <= daddr[31:5];

        cache_mem[cache_index].byte3 <= temp_rd_data[31:24];
        cache_mem[cache_index].byte2 <= temp_rd_data[23:16];
        cache_mem[cache_index].byte1 <= temp_rd_data[15:8];
        cache_mem[cache_index].byte0 <= temp_rd_data[7:0];
    end
end

// External memory module instantiation
datamem #(
    .addr_width(addr_width),
    .data_width(data_width)
) memory_instance (
    .clk(clk),
    .we(we),
    .funct3(funct3),
    .daddr(daddr),
    .wd_data(wd_data),
    .rd_data(temp_rd_data)
);

endmodule
