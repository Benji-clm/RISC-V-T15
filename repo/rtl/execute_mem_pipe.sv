// EX/MEM Pipeline Module
module execute_mem_pipe #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 32
)(
    input logic clk,
    input logic flush,               

    // Inputs from EX stage
    input logic [DATA_WIDTH-1:0] alu_result,  // ALU result
    input logic [DATA_WIDTH-1:0] write_data,  // Write data (for store)
    input logic [ADDR_WIDTH-1:0] daddr,       // Data memory address
    input logic mem_write,           // Memory write enable
    input logic mem_read,            // Memory read enable
    input logic [2:0] funct3,        // Function control 
    input logic [4:0] reg_dest,      // Register destination

    // Outputs to MEM stage
    output logic [DATA_WIDTH-1:0] mem_alu_result, // ALU result 
    output logic [DATA_WIDTH-1:0] mem_write_data,  // Write data
    output logic [ADDR_WIDTH-1:0] mem_daddr,       // Data memory address 
    output logic mem_mem_write,           // Memory write enable
    output logic mem_mem_read,            // Memory read enable
    output logic [2:0] mem_funct3,        // Function control
    output logic [4:0] mem_reg_dest      // Register destination 
);

     always_ff @(posedge clk) begin
        if (flush) begin
            mem_mem_write <= 0;     
            mem_mem_read <= 0;      
            mem_funct3 <= 0;          
            mem_reg_dest <= 0;       

        end 
        
        else begin
            mem_alu_result <= alu_result;            
            mem_write_data <= write_data;            
            mem_daddr <= daddr;                      
            mem_mem_write <= mem_write;              
            mem_mem_read <= mem_read;                
            mem_funct3 <= funct3;                    
            mem_reg_dest <= reg_dest;                

        end
    end

endmodule
