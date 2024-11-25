`include "definitions.sv"

module alu #(
    parameter DATA_WIDTH = 32
)(
    input  logic [DATA_WIDTH-1:0] ALUop1, ALUop2,
    input  logic [3:0]            ALUctrl, // Updated to 4 bits to match `ALUop` definitions
    output logic [DATA_WIDTH-1:0] ALUout,
    output logic                  eq
);

wire signed [DATA_WIDTH-1:0] op1_signed;
wire signed [DATA_WIDTH-1:0] op2_signed;

assign op1_signed = ALUop1;
assign op2_signed = ALUop2;

always_comb begin
    // Default values for outputs
    ALUout = 0;
    eq = 0;

    case(ALUctrl)
        `ALUop_ADD:  ALUout = ALUop1 + ALUop2;                             // Addition
        `ALUop_SUB:  ALUout = ALUop1 - ALUop2;                             // Subtraction
        `ALUop_AND:  ALUout = ALUop1 & ALUop2;                             // AND
        `ALUop_OR:   ALUout = ALUop1 | ALUop2;                             // OR
        `ALUop_XOR:  ALUout = ALUop1 ^ ALUop2;                             // XOR
        `ALUop_LSL:  ALUout = ALUop1 << ALUop2[4:0];                       // Logical shift left
        `ALUop_LSR:  ALUout = ALUop1 >> ALUop2[4:0];                       // Logical shift right
        `ALUop_ASR:  ALUout = op1_signed >>> ALUop2[4:0];                  // Arithmetic shift right
        `ALUop_SLT:  ALUout = (op1_signed < op2_signed) ? 1 : 0;           // Set less than (signed)
        `ALUop_SLTU: ALUout = (ALUop1 < ALUop2) ? 1 : 0;                   // Set less than (unsigned)
        `ALUop_B:    ALUout = ALUop1;                                      // Pass-through (branch computation)
        default:     ALUout = 0;                                           // Default case
    endcase

    // Zero flag for branch conditions
    eq = (ALUout == 0) ? 1 : 0;
end

endmodule