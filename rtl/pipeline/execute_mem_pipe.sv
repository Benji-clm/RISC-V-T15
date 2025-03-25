module execute_mem_pipe #(
    parameter DATA_WIDTH = 32
)(
    input logic clk,           
 
    input logic [DATA_WIDTH-1:0] ALUResult,
    input logic [DATA_WIDTH-1:0] WriteDataE,
    input logic [DATA_WIDTH-1:0] PCPlus4E,
    input logic MemWriteE,
    input logic MemReadE,
    input logic [2:0] LS_modeE,
    input logic [4:0] RdE,
    input logic RegWriteE,
    input logic [1:0] ResultSrcE,
 
 
    output logic [DATA_WIDTH-1:0] ALUResultM,
    output logic [DATA_WIDTH-1:0] WriteDataM,
    output logic [DATA_WIDTH-1:0] PCPlus4M,
    output logic MemWriteM,
    output logic MemReadM,
    output logic [2:0] LS_modeM,
    output logic [4:0] RdM,
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
