`ifndef DEFINITIONS_SV 
`define DEFINITIONS_SV


// Associating names to the opcodes understood by the ALU -> will help simplify further desing
`define ALUop_ADD       4'b0000
`define ALUop_SUB       4'b0001
`define ALUop_AND       4'b0010
`define ALUop_OR        4'b0011
`define ALUop_XOR       4'b0100
`define ALUop_LSL       4'b0101
`define ALUop_LSR       4'b0110
`define ALUop_ASR       4'b0111
`define ALUop_SLT       4'b1000
`define ALUop_SLTU      4'b1001
`define ALUop_B         4'b1010

// Defining opcodes for the different branching conditions -> allows for several B-type operations
// The opcode will help us determine how to check whether we branch or not (combined with `eq`).
`define NEXT_PC         3'b000
`define EQ_TRUE         3'b001
`define EQ_FALSE        3'b010
`define UC_JUMP         3'b011
`define JALR            3'b100

// Defining the type of instr for SignExtend to correctly extend Immediate
`define I_TYPE          3'b000
`define S_TYPE          3'b001
`define B_TYPE          3'b010
`define U_TYPE          3'b011
`define J_TYPE          3'b100
`define NE_TYPE         3'b101 // this is specifically for the shifts, where NO EXNTENSION should be performed


// Defining load/store types
`define B_MODE          3'b000
`define H_MODE          3'b001
`define W_MODE          3'b010
`define UB_MODE         3'b011
`define UH_MODE         3'b100

`endif
