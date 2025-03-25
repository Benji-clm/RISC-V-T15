module mem_writeback_pipe #(
    parameter DATA_WIDTH = 32
)(
    input logic clk,                                 
 
    // Inputs from MEM stage
    input logic [DATA_WIDTH-1:0] ALUResultM,
    input logic [DATA_WIDTH-1:0] rd,
    input logic [4:0] RdM,
    input logic RegWriteM,
    input logic [DATA_WIDTH-1:0] PCPlus4M,
    input logic [1:0] ResultSrcM,
 
    // Output to WB stage
    output logic [DATA_WIDTH-1:0] ReadDataW,
    output logic [4:0] RdW,
    output logic RegWriteW,
    output logic [DATA_WIDTH-1:0] PCPlus4W,
    output logic [DATA_WIDTH-1:0] ALUResultW,
    output logic [1:0] ResultSrcW
);
 
    always_ff @(posedge clk) begin
        ReadDataW <= rd;
        RdW <= RdM;       
        RegWriteW <= RegWriteM;
        ALUResultW <= ALUResultM;
        PCPlus4W <= PCPlus4M;
        ResultSrcW <= ResultSrcM;
        
    end
 
endmodule
