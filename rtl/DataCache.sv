module DataCache #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32
)(
    input logic clk,
    input logic we,                     // Write enable
    input logic [2:0] LS_mode,
    input logic MemRead,
    input logic [ADDR_WIDTH-1:0] a,     // Address
    input logic [DATA_WIDTH-1:0] wd,    // Write data

    output logic [DATA_WIDTH-1:0] rd    // Read data
);

typedef struct packed {
    logic valid_bit;
    logic [27:0] tag_bits;   // 28-bit tag for a[31:4]
    logic [7:0]  byte3;
    logic [7:0]  byte2;
    logic [7:0]  byte1;
    logic [7:0]  byte0;
} cache_line;

// Two-way set associative:
// 2 ways, with 4 sets total
cache_line cache_mem[2][4];  // cache_mem[way][index]

logic [DATA_WIDTH-1:0] temp_rd;
logic [27:0] address_tag;
logic [1:0]  cache_index;    
logic [1:0]  byte_offset;

logic hit_way0, hit_way1;
logic hit_way;   // Which way hit: 0 or 1
logic hit;       // Did we get a hit in any way?

// Calculate tag, index, offset
always_comb begin
    address_tag = a[31:4];    // 28-bit tag
    cache_index = a[3:2];     // 4 sets => 2 bits
    byte_offset = a[1:0];     // 4-byte line => 2 offset bits

    // Check both ways for a hit
    hit_way0 = cache_mem[0][cache_index].valid_bit && (cache_mem[0][cache_index].tag_bits == address_tag);
    hit_way1 = cache_mem[1][cache_index].valid_bit && (cache_mem[1][cache_index].tag_bits == address_tag);

    hit = hit_way0 || hit_way1;

    // Determine which way is hit
    // If both hit (shouldn't happen if tags are unique), choose way0
    hit_way = hit_way0 ? 1'b0 : (hit_way1 ? 1'b1 : 1'b0);

    // If hit, read from the hit way, else read temp_rd from memory
    if (hit) begin
        rd = {
            cache_mem[hit_way][cache_index].byte3,
            cache_mem[hit_way][cache_index].byte2,
            cache_mem[hit_way][cache_index].byte1,
            cache_mem[hit_way][cache_index].byte0
        };
    end else begin
        rd = temp_rd;
    end
end


// Write or allocate line
always_ff @(posedge clk) begin
    if (we) begin
        // On a write, if hit, update that line
        if (hit) begin
            case (LS_mode)
                `W_MODE: begin
                    cache_mem[hit_way][cache_index].byte3 <= wd[31:24];
                    cache_mem[hit_way][cache_index].byte2 <= wd[23:16];
                    cache_mem[hit_way][cache_index].byte1 <= wd[15:8];
                    cache_mem[hit_way][cache_index].byte0 <= wd[7:0];
                end

                `B_MODE, `UB_MODE: begin
                    case (byte_offset)
                        2'b11: cache_mem[hit_way][cache_index].byte3 <= wd[7:0];
                        2'b10: cache_mem[hit_way][cache_index].byte2 <= wd[7:0];
                        2'b01: cache_mem[hit_way][cache_index].byte1 <= wd[7:0];
                        2'b00: cache_mem[hit_way][cache_index].byte0 <= wd[7:0];
                    endcase
                end

                `H_MODE, `UH_MODE: begin
                    case (byte_offset)
                        2'b00: begin
                            cache_mem[hit_way][cache_index].byte1 <= wd[15:8];
                            cache_mem[hit_way][cache_index].byte0 <= wd[7:0];
                        end
                        2'b10: begin
                            cache_mem[hit_way][cache_index].byte3 <= wd[15:8];
                            cache_mem[hit_way][cache_index].byte2 <= wd[7:0];
                        end
                        default: $error("Misaligned halfword write detected!");
                    endcase
                end

                default: $display("WARNING: Unrecognized LS_mode in cache");
            endcase

        end else begin
            // Miss on write: Write-allocate
            // Choose a way to allocate
            logic allocated_way;
            if (!cache_mem[0][cache_index].valid_bit) begin
                allocated_way = 0;
            end else if (!cache_mem[1][cache_index].valid_bit) begin
                allocated_way = 1;
            end else begin
                // Simple replacement policy: overwrite way0
                allocated_way = 0;
            end

            // Bring the line from memory (temp_rd) into cache
            cache_mem[allocated_way][cache_index].valid_bit <= 1;
            cache_mem[allocated_way][cache_index].tag_bits  <= address_tag;

            cache_mem[allocated_way][cache_index].byte3 <= temp_rd[31:24];
            cache_mem[allocated_way][cache_index].byte2 <= temp_rd[23:16];
            cache_mem[allocated_way][cache_index].byte1 <= temp_rd[15:8];
            cache_mem[allocated_way][cache_index].byte0 <= temp_rd[7:0];

            // Now perform the requested write
            case (LS_mode)
                `W_MODE: begin
                    cache_mem[allocated_way][cache_index].byte3 <= wd[31:24];
                    cache_mem[allocated_way][cache_index].byte2 <= wd[23:16];
                    cache_mem[allocated_way][cache_index].byte1 <= wd[15:8];
                    cache_mem[allocated_way][cache_index].byte0 <= wd[7:0];
                end

                `B_MODE, `UB_MODE: begin
                    case (byte_offset)
                        2'b11: cache_mem[allocated_way][cache_index].byte3 <= wd[7:0];
                        2'b10: cache_mem[allocated_way][cache_index].byte2 <= wd[7:0];
                        2'b01: cache_mem[allocated_way][cache_index].byte1 <= wd[7:0];
                        2'b00: cache_mem[allocated_way][cache_index].byte0 <= wd[7:0];
                    endcase
                end

                `H_MODE, `UH_MODE: begin
                    case (byte_offset)
                        2'b00: begin
                            cache_mem[allocated_way][cache_index].byte1 <= wd[15:8];
                            cache_mem[allocated_way][cache_index].byte0 <= wd[7:0];
                        end
                        2'b10: begin
                            cache_mem[allocated_way][cache_index].byte3 <= wd[15:8];
                            cache_mem[allocated_way][cache_index].byte2 <= wd[7:0];
                        end
                        default: $error("Misaligned halfword write detected!");
                    endcase
                end

                default: $display("WARNING: Unrecognized LS_mode in cache");
            endcase
        end
    end else if (MemRead && !hit) begin
        // Miss on read: bring data from memory into cache
        logic allocated_way;
        if (!cache_mem[0][cache_index].valid_bit) begin
            allocated_way = 0;
        end else if (!cache_mem[1][cache_index].valid_bit) begin
            allocated_way = 1;
        end else begin
            // Simple replacement policy: overwrite way0
            allocated_way = 0;
        end

        cache_mem[allocated_way][cache_index].valid_bit <= 1;
        cache_mem[allocated_way][cache_index].tag_bits  <= address_tag;

        cache_mem[allocated_way][cache_index].byte3 <= temp_rd[31:24];
        cache_mem[allocated_way][cache_index].byte2 <= temp_rd[23:16];
        cache_mem[allocated_way][cache_index].byte1 <= temp_rd[15:8];
        cache_mem[allocated_way][cache_index].byte0 <= temp_rd[7:0];
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
