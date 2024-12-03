`include "definitions.sv"

module top_memory #(
    parameter   addr_width = 32,
                data_width = 32
) (
    input logic clk,
    input logic [3:0] write_en,            // Write enable (4 bits)
    input logic [2:0] funct3,              // Addressing mode (load/store mode)
    input logic [addr_width-1:0] addr,     // Address
    input logic [data_width-1:0] write_data, // Data to write

    output logic hit,                      // Cache hit signal
    output logic [data_width-1:0] out      // Data read output
);

logic [data_width-1:0] out_cache;
logic [7:0] byte3, byte2, byte1, byte0;

// Extract bytes from the cache output
always_comb begin
    byte3 = out_cache[31:24];
    byte2 = out_cache[23:16];
    byte1 = out_cache[15:8];
    byte0 = out_cache[7:0];

    // Read logic with addressing modes
    case (funct3)
        `W_MODE: begin
            out = out_cache; 
        end
        `B_MODE: begin
            case (addr[1:0])
                2'b00: out = {{24{byte0[7]}}, byte0};
                2'b01: out = {{24{byte1[7]}}, byte1};
                2'b10: out = {{24{byte2[7]}}, byte2};
                2'b11: out = {{24{byte3[7]}}, byte3};
            endcase
        end
        `BU_MODE: begin
            case (addr[1:0])
                2'b00: out = {24'b0, byte0};
                2'b01: out = {24'b0, byte1};
                2'b10: out = {24'b0, byte2};
                2'b11: out = {24'b0, byte3};
            endcase
        end
        // Future modes: H_MODE, HU_MODE
        default: $display("WARNING: Unrecognized funct3 in top_memory.sv");
    endcase
end


DataCache #(addr_width, data_width) data_cache_inst (
    .clk(clk),
    .we(write_en),                 
    .funct3(funct3),               
    .daddr(addr),                  
    .wd_data(write_data),          
    .cache_hit(hit),               
    .rd_data(out_cache)            
);

endmodule