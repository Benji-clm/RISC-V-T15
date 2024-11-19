module alu #(
    DATA_WIDTH = 32
)(
    input  logic [DATA_WIDTH-1:0] ALUop1, ALUop2,
    input  logic [2:0]            ALUctrl,
    output logic [DATA_WIDTH-1:0] ALUout,
    output logic                  eq
);

wire signed [DATA_WIDTH-1:0] op1_signed;
wire signed [DATA_WIDTH-1:0] op2_signed;

assign op1_signed = ALUop1;
assign op2_signed = ALUop2;

always_comb begin
    case(ALUctrl)
        3'b000: ALUout = ALUop1 + ALUop2; // addition
        3'b001: ALUout = ALUop1 - ALUop2; // substraction
        3'b010: ALUout = ALUop1 & ALUop2; // and
        3'b011: ALUout = ALUop1 | ALUop2; // or
        3'b101: ALUout = (op1_signed < op2_signed) ? 1 : 0; // set less than
    endcase

    // If we have a zero result, we set "zero" to 1 for the control unit, so that in the case of BEQ it knows
    // that PCsrc should be equal to the branch (branch if equal). 
    eq = (ALUout == 0'b0) ? 0 : 1;

end

endmodule
