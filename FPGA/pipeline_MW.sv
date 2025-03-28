module pipeline_MW #(
    DATA_WIDTH = 32
)(
    input  logic                    clk,

    // inputs
    input  logic                    RegWriteM,
    input  logic [1:0]              ResultSrcM,
    input  logic [DATA_WIDTH-1:0]   ALUResultM,
    input  logic [DATA_WIDTH-1:0]   rd,
    input  logic [4:0]              RdM,
    input  logic [DATA_WIDTH-1:0]   PCPlus4M,

    // outputs
    output logic                    RegWriteW,
    output logic [1:0]              ResultSrcW,
    output logic [DATA_WIDTH-1:0]   ALUResultW,
    output logic [DATA_WIDTH-1:0]   ReadDataW,
    output logic [4:0]              RdW,
    output logic [DATA_WIDTH-1:0]   PCPlus4W
);

always_ff @ (posedge clk) begin 
    RegWriteW <= RegWriteM;
    ResultSrcW <= ResultSrcM;
    ALUResultW <= ALUResultM;
    ReadDataW <= rd;
    RdW <= RdM;
    PCPlus4W <= PCPlus4M;
end

endmodule
