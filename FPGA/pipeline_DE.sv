`include "definitions.sv"

module pipeline_DE #(
    parameter DATA_WIDTH = 32
)(
    // pipeline control inputs
    input  logic                    clk,
    input  logic                    FlushE,

    // control unit inputs:
    input  logic                    RegWriteD,
    input  logic [1:0]              ResultSrcD,
    input  logic                    MemWriteD,
    input  logic [2:0]              PCsrcD,
    input  logic [3:0]              ALUControlD,
    input  logic                    ALUsrcD,

    // regfile, extend, and PC inputs
    input  logic [DATA_WIDTH-1:0]   rd1,
    input  logic [DATA_WIDTH-1:0]   rd2,
    input  logic [DATA_WIDTH-1:0]   pcD,
    input  logic [4:0]              Rs1D,
    input  logic [4:0]              Rs2D,
    input  logic [4:0]              RdD,
    input  logic [DATA_WIDTH-1:0]   ImmExtD,
    input  logic [DATA_WIDTH-1:0]   PCPlus4D,
    input  logic [2:0]              LS_modeD,
    input  logic                    MemReadD,

    // outputs
    output logic                    RegWriteE,
    output logic [1:0]              ResultSrcE,
    output logic                    MemWriteE,
    output logic [2:0]              PCsrcE,
    output logic [3:0]              ALUControlE,
    output logic                    ALUsrcE,
    output logic [DATA_WIDTH-1:0]   rd1E,
    output logic [DATA_WIDTH-1:0]   rd2E,
    output logic [DATA_WIDTH-1:0]   pcE,
    output logic [4:0]              Rs1E,
    output logic [4:0]              Rs2E,
    output logic [4:0]              RdE,
    output logic [DATA_WIDTH-1:0]   ImmExtE,
    output logic [DATA_WIDTH-1:0]   PCPlus4E,
    output logic [2:0]              LS_modeE,
    output logic                    MemReadE
);

    always_ff @(posedge clk) begin
        if (!FlushE) begin
            // Pass control signals to E stage
            RegWriteE <= RegWriteD;
            MemWriteE <= MemWriteD;
            PCsrcE <= PCsrcD;
        end 
    
        else begin
            // Reset control and data signals during flush
            RegWriteE   <= 0;
            MemWriteE   <= 0;
            PCsrcE      <= `NEXT_PC; 
        end

            // The rest is unaffected by the flush, as they do not trigger parts of the signals
            ResultSrcE  <= ResultSrcD;
            ALUControlE <= ALUControlD;
            ALUsrcE     <= ALUsrcD;
            rd1E        <= rd1;
            rd2E        <= rd2;
            pcE         <= pcD;
            Rs1E        <= Rs1D;
            Rs2E        <= Rs2D;
            RdE         <= RdD;
            ImmExtE     <= ImmExtD;
            LS_modeE    <= LS_modeD;
            MemReadE    <= MemReadD;

            // We also preserve the program state
            PCPlus4E    <= PCPlus4D;

    end

endmodule
