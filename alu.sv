module ALU#(
    parameter DATA_WIDTH = 32
)(
    input logic clk;
    input logic [DATA_WIDTH-1:0] in1,
    input logic [DATA_WIDTH-1:0] in2,
    input logic [2:0] ALUctrl,
    output logic [DATA_WIDTH-1:0] ALUout,
    output logic eq
);

    logic [DATA_WIDTH-1:0] sub,  
    assign sub = in1 - in2;

always_ff(@posedge clk)
    if (ALUctrl = 0)
        assign ALUout <= in1 + in2;
    elif (sub = 0)
        assign eq <= 1'b1;
        

endmodule
