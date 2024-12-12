module decode_execute_pipe #(
    parameter DATA_WIDTH = 32
) (
    // controls
    input  logic                    clk,
    input  logic                    FlushE,
 
    // control unit inputs
    input  logic                    RegWriteD,
    input  logic [1:0]              ResultSrcD,
    input  logic                    MemWriteD,
    input  logic [2:0]              PCsrcD,
    input  logic [3:0]              ALUControlD,
    input  logic                    ALUsrcD,
 
    // regile, extend and PC inputs
    input  logic [DATA_WIDTH-1:0]   rd1,
    input  logic [DATA_WIDTH-1:0]   rd2,
    input  logic [DATA_WIDTH-1:0]   pcD,
    input  logic [DATA_WIDTH-1:0]   PCPlus4D,
    input  logic [31:0]             ImmExtD,   //Imm operand extended from SignExtend.sv ImmExtD in scheme
    input  logic [4:0]              Rs1D,
    input  logic [4:0]              Rs2D,
    input  logic [4:0]              RdD,
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
    output logic [DATA_WIDTH-1:0]   PCPlus4E,
    output logic [DATA_WIDTH-1:0]   ImmExtE,
    output logic [4:0]              Rs1E,
    output logic [4:0]              Rs2E,
    output logic [4:0]              RdE,
    output logic [2:0]              LS_modeE,
    output logic                    MemReadE
);
 
    always_ff @(posedge clk) begin
        if(!FlushE) begin
            RegWriteE <= RegWriteD;
            MemWriteE <= MemWriteD;
            PCsrcE <= PCsrcD;
        end
 
        else begin
            // if flush, reset control and data signals
            RegWriteE <= 0;
            MemWriteE  <= 0;
            PCsrcE    <= `NEXT_PC;
        end
 
            // Pass the data
            rd1E        <= rd1;
            rd2E        <= rd2;
            pcE         <= pcD;
            PCPlus4E    <= PCPlus4D;
            ImmExtE     <= ImmExtD;
            Rs1E        <= Rs1D;
            Rs2E        <= Rs2D;
            RdE         <= RdD;
            ResultSrcE  <= ResultSrcD;
            ALUControlE <= ALUControlD;
            ALUsrcE     <= ALUsrcD;
            LS_modeE    <= LS_modeD;
            MemReadE    <= MemReadD;
 
    end
    
endmodule
