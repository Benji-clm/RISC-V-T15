module control_unit #(
    parameter DATA_WIDTH = 32
)(
    input  logic [DATA_WIDTH-1:0] instr,
    input  logic                  zero,
    output logic                  PCSrc,
    output logic                  ResultSrc,
    output logic                  MemWrite,
    output logic [2:0]            ALUControl,
    output logic                  ALUSrc,
    output logic [1:0]            ImmSrc,
    output logic                  RegWrite                 
);

    logic op [6:0];
    logic funct3 [2:0];
    logic funct7;
    logic ALUOp [1:0];
    logic Branch

    assign op = instr[6:0];
    assign funct3 = instr[14:12];
    assign funct7 = instr[30];


main_decoder main_decoder_ (
    .op(op),
    .ResultSrc(ResultSrc),
    .MemWrite(MemWrite),
    .ALUSrc(ALUSrc),
    .ImmSrc(ImmSrc),
    .RegWrite(RegWrite),
    .Branch(Branch),
    .ALUOp(ALUOp)
);

ALU_decoder alu_decoder_ (
    .op(op),
    .funct3(funct3),
    .funct7(funct7),
    .ALUOp(ALUOp),
    .ALUControl(ALUControl)
);

assign PCSrc = zero & Branch;

endmodule
