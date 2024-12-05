module execute_mem_pipe #(
    parameter DATA_WIDTH = 32
)(
    input logic clk,           
 
    input logic [DATA_WIDTH-1:0] ALUResult,  // ALU result
    input logic [DATA_WIDTH-1:0] WriteDataE,  // Write data (for store)
    input logic [DATA_WIDTH-1:0] PCPlus4E,       // Data memory address
    input logic MemWriteE,           // Memory write enable
    input logic MemReadE,            // Memory read enable
    input logic [2:0] LS_modeE,        // Function control
    input logic [4:0] RdE,      // Register destination
    input logic RegWriteE,
    input logic [1:0] ResultSrcE,
 
 
    output logic [DATA_WIDTH-1:0] ALUResultM, // ALU result
    output logic [DATA_WIDTH-1:0] WriteDataM,  // Write data
    output logic [DATA_WIDTH-1:0] PCPlus4M,       // Data memory address
    output logic MemWriteM,           // Memory write enable
    output logic MemReadM,            // Memory read enable
    output logic [2:0] LS_modeM,        // Function control
    output logic [4:0] RdM,      // Register destination
    output logic RegWriteM,
    output logic [1:0] ResultSrcM
);
 
     always_ff @(posedge clk) begin
        ALUResultM <= ALUResult;            
        WriteDataM <= WriteDataE;            
        PCPlus4M <= PCPlus4E;                      
        MemWriteM <= MemWriteE;              
        MemReadM <= MemReadE;                
        LS_modeM <= LS_modeE;                    
        RdM <= RdE;
        RegWriteM <= RegWriteE;
        ResultSrcM <= ResultSrcE;               
 
    
    end
 
endmodule
