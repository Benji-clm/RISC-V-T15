module decode_execute_pipe #(
    parameter DATA_WIDTH = 16
) (
    input clk,
    input flushE,
    input logic [DATA_WIDTH-1:0]  rd1,
    input logic [DATA_WIDTH-1:0]  rd2,
    input logic [DATA_WIDTH-1:0] PCounterD, 
    input logic [DATA_WIDTH-1:0] PCPlus4D,
    input logic [31:0] ImmOp,   //Imm operand extended from SignExtend.sv
    //opcode etc how they will come as input

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
            PCounterE  <= {DATA_WIDTH{1'b0}};
            PCPlus4E   <= {DATA_WIDTH{1'b0}};
            ImmOpE     <= 32'b0; 
        end

    // Pass the data 
        else begin
            rd1E <= rd1;
            rd2E <= rd2;
            PCounterE <= PCounterD;
            PCPlus4E <= PCPlus4;
            ImmOp <= ImmOpE;        
        end


    end
    
endmodule