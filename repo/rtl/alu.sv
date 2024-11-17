module ALU #(
    DATA_WIDTH = 32
)(
    input  logic [DATA_WIDTH-1:0] in1, in2,
    input  logic [2:0]            ALUCtrl,
    output logic [DATA_WIDTH-1:0] ALUout,
    output logic                  eq
);

wire signed [DATA_WIDTH-1:0] op1_signed;
wire signed [DATA_WIDTH-1:0] op2_signed;

assign op1_signed = in1;
assign op2_signed = in2;

always_comb begin
    case(ALUCtrl)
        3'b000: ALUout = in1 + in2; // addition
        3'b001: ALUout = in1 - in2; // substraction
        3'b010: ALUout = in1 & in2; // and
        3'b011: ALUout = in1 | in2; // or
        3'b101: ALUout = (op1_signed < op2_signed) ? 1 : 0; // set less than
    endcase

    // If we have a zero result, we set "zero" to 1 for the control unit, so that in the case of BEQ it knows
    // that PCsrc should be equal to the branch (branch if equal). 
    eq = (ALUout == 0'b0) ? 1 : 0;

end

endmodule
