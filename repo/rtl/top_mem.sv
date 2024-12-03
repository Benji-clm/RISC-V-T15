`include "definitions.sv"

module top_memory #(
    parameter addr_width = 32,
              data_width = 32
) (
    input logic clk,
    input logic [3:0] we,            
    input logic [2:0] funct3,              
    input logic [addr_width-1:0] daddr,    
    input logic [data_width-1:0] wd_data, 

    output logic cache_hit,                    
    output logic [data_width-1:0] out   
);

logic [data_width-1:0] ocache;
logic [7:0] selected_byte;

always_comb begin
    case (addr[1:0])
        2'b00: selected_byte = oache[7:0];
        2'b01: selected_byte = ocache[15:8];
        2'b10: selected_byte = ocache[23:16];
        2'b11: selected_byte = ocache[31:24];
        default: selected_byte = 8'b0;
    endcase
end

// Output generation logic based on funct3
always_comb begin
    case (funct3)
        `W_MODE: begin
            out = out_cache;
        end
        `B_MODE: begin
            out = {{24{selected_byte[7]}}, selected_byte};
        end
        `BU_MODE: begin
            out = {24'b0, selected_byte};
        end
        default: begin
            out = 32'b0; 
            $display("WARNING");
        end
    endcase
end

DataCache #(addr_width, data_width) data_cache_inst (
    .clk(clk),
    .we(we),                 
    .funct3(funct3),               
    .daddr(daddr),                  
    .wd_data(wd_data),          
    .cache_hit(cache_hit),               
    .rd_data(rd_data)            
);

endmodule
