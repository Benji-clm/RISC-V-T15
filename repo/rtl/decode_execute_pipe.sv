module decode_execute_pipe #(
    parameters
) (
    input logic [DATA_WIDTH-1:0]  rd1,
    input logic [DATA_WIDTH-1:0]  rd2,
    input logic [DATA_WIDTH-1:0] PCounterD, 
    input logic [DATA_WIDTH-1:0] PCPlus4D,
    input logic [31:0] ImmOp, 
    //opcode etc how they will come as input

    output logic [DATA_WIDTH-1:0]  rd1E,
    output logic [DATA_WIDTH-1:0]  rd2E,
    output logic [DATA_WIDTH-1:0] PCPlus4E,
    output logic [31:0] ImmOpE, 

);
    
endmodule