`include "definitions.sv"

module alu #(
    parameter DATA_WIDTH = 32
)(
    input  logic [DATA_WIDTH-1:0] ALUop1, ALUop2,
    input  logic [3:0]            ALUctrl,
    output logic [DATA_WIDTH-1:0] ALUout,
    output logic                  eq
);

wire signed [DATA_WIDTH-1:0] op1_signed;
wire signed [DATA_WIDTH-1:0] op2_signed;

assign op1_signed = ALUop1;
assign op2_signed = ALUop2;

always_comb begin

    case(ALUctrl)
        `ALUop_ADD:  ALUout = ALUop1 + ALUop2;                             
        `ALUop_SUB:  ALUout = ALUop1 - ALUop2;                             
        `ALUop_AND:  ALUout = ALUop1 & ALUop2;                             
        `ALUop_OR:   ALUout = ALUop1 | ALUop2;                             
        `ALUop_XOR:  ALUout = ALUop1 ^ ALUop2;                            
        `ALUop_LSL:  ALUout = ALUop1 << ALUop2;                       
        `ALUop_LSR:  ALUout = ALUop1 >> ALUop2;                       
        `ALUop_ASR:  ALUout = op1_signed >>> ALUop2;                  
        `ALUop_SLT:  ALUout = (op1_signed < op2_signed) ? 1 : 0;           
        `ALUop_SLTU: ALUout = (ALUop1 < ALUop2) ? 1 : 0;                   
        `ALUop_B:    ALUout = ALUop2;                                      
        default:     ALUout = 0;                                           
    endcase

    eq = (ALUout == 0'b0) ? 1 : 0;
end

endmodule
