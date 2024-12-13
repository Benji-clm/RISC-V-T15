module pipeline_EM #(
    parameter DATA_WIDTH = 32
)(
    input  logic                    clk,

    // inputs
    input  logic                    RegWriteE,
    input  logic [1:0]              ResultSrcE,
    input  logic                    MemWriteE,
    input  logic [DATA_WIDTH-1:0]   ALUResult,
    input  logic [DATA_WIDTH-1:0]   WriteDataE,
    input  logic [4:0]              RdE,
    input  logic [DATA_WIDTH-1:0]   PCPlus4E,
    input  logic [2:0]              LS_modeE,
    input  logic                    MemReadE,

    // outputs
    output logic                    RegWriteM,
    output logic [1:0]              ResultSrcM,
    output logic                    MemWriteM,
    output logic [DATA_WIDTH-1:0]   ALUResultM,
    output logic [DATA_WIDTH-1:0]   WriteDataM,
    output logic [4:0]              RdM,
    output logic [DATA_WIDTH-1:0]   PCPlus4M,
    output logic [2:0]              LS_modeM,
    output logic                    MemReadM
);

always_ff @ (posedge clk) begin 
    RegWriteM <= RegWriteE;
    ResultSrcM <= ResultSrcE;
    MemWriteM <= MemWriteE;
    ALUResultM <= ALUResult;
    WriteDataM <= WriteDataE;
    RdM <= RdE;
    PCPlus4M <= PCPlus4E;
    LS_modeM <= LS_modeE;
    MemReadM <= MemReadE;
end

endmodule
