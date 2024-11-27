module decode_execute_pipe #(
    parameter DATA_WIDTH = 16
) (
    input clk,
    input flushE,
    input logic [DATA_WIDTH-1:0]  rd1,
    input logic [DATA_WIDTH-1:0]  rd2,
    input logic [DATA_WIDTH-1:0] PCounterD, 
    input logic [DATA_WIDTH-1:0] PCPlus4D,
    input logic [31:0] ImmOp,   //Imm operand extended from SignExtend.sv ImmExtD in scheme
    
    //??
    input logic [19:15] Rs1D,
    input logic [24:20] Rs2D,
    input logic [11:7] RdD,

    output logic [19:15] Rs1E,
    output logic [24:20] Rs2E,
    output logic [11:7] RdE, 

    output logic [DATA_WIDTH-1:0]  rd1E,
    output logic [DATA_WIDTH-1:0]  rd2E,
    output logic [DATA_WIDTH-1:0] PCPlus4E,
    output logic [DATA_WIDTH-1:0] PCounterE,
    output logic [31:0] ImmOpE
);

    always_ff @(posedge clk) begin

        //Flush
        if(flushE) begin
            rd1E       <= {DATA_WIDTH{1'b0}};
            rd2E       <= {DATA_WIDTH{1'b0}};
            ImmOpE     <= 0; 
        end

    // Pass the data 
        else begin
            rd1E <= rd1;
            rd2E <= rd2;
            PCounterE <= PCounterD;
            PCPlus4E <= PCPlus4;
            ImmOpE <= ImmOp;
            Rs1E <= Rs1D;
            Rs2E <= Rs2D;
            RdE <= RdD;
        end

    end
    
endmodule