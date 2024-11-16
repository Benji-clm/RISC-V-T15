module control_unit #(
    parameter DATA_WIDTH = 32
)(  
    /* verilator lint_off UNUSEDSIGNAL */
    input  logic [DATA_WIDTH-1:0] instr,
    /* verilator lint_on UNUSEDSIGNAL */
    input  logic                  zero,
    output logic                  PCSrc,
    output logic                  ResultSrc,
    output logic                  MemWrite,
    output logic [2:0]            ALUctrl,
    output logic                  ALUSrc,
    output logic [1:0]            ImmSrc,
    output logic                  RegWrite                 
);

    // Corrected signal declarations
    logic [6:0] op;
    logic [2:0] funct3;
    logic funct7;
    logic [1:0] ALUOp;
    logic Branch;

    // Assign instruction fields to signals
    assign op = instr[6:0];
    assign funct3 = instr[14:12];
    assign funct7 = instr[30];

    // Instantiate the main decoder
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

    // Instantiate the ALU decoder
    ALU_decoder alu_decoder_ (
        .op(op),
        .funct3(funct3),
        .funct7(funct7),
        .ALUOp(ALUOp),
        .ALUctrl(ALUctrl)
    );

    // Compute PCSrc
    assign PCSrc = zero & Branch;

endmodule
