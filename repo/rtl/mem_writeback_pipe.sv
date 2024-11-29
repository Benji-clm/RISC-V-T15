module mem_writeback_pipeline #(
    parameter DATA_WIDTH = 32
)(
    input logic clk,                  
    input logic flush,                 

    // Inputs from MEM stage
    input logic [DATA_WIDTH-1:0] mem_alu_result,   // ALU result from MEM stage
    input logic [DATA_WIDTH-1:0] mem_mem_data,     // Data from memory
    input logic [4:0] mem_reg_dest,                // Register destination
    input logic mem_reg_write,                    // Register write enable

    // Output to WB stage
    output logic [DATA_WIDTH-1:0] wb_data,        // Data to write back to register file
    output logic [4:0] wb_reg_dest,               // Register destination
    output logic wb_reg_write                    // Register write enable to WB stage
);

    always_ff @(posedge clk) begin
        if (flush) begin
            // Reset values on flush
            wb_data <= 0;
            wb_reg_dest <= 0;
            wb_reg_write <= 0;
        end else begin
            // Pass control and data signals to WB stage
            wb_data <= (mem_reg_write) ? mem_mem_data : mem_alu_result; 
            wb_reg_dest <= mem_reg_dest;       
            wb_reg_write <= mem_reg_write;       
        end
    end

endmodule
