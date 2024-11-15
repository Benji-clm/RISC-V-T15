module top #(
    parameter DATA_WIDTH = 32,
    parameter ADDRESS_WIDTH = 16
) (
    input   logic clk,
    input   logic rst,
    output  logic [DATA_WIDTH-1:0] a0    
);

    assign a0 = 5;


    logic [ADDRESS_WIDTH-1:0]   pc, next_PC;
    logic [DATA_WIDTH-1:0]      ImmOp, instr, ALUop1, regOp2, ALUop2, ALUout;
    logic                       PCsrc, ResultSrc, MemWrite, ALUSrc, RegWrite, eq;
    logic [2:0]                 ALUControl;
    logic [1:0]                 ImmSrc;
    logic [4:0]                 rs1, rs2, rd;

    always_ff @ (posedge clk, posedge rst) begin
        if (rst) 
            pc <= {ADDRESS_WIDTH{1'b0}};
        else 
            pc <= next_PC;
    end
    pc #(ADDRESS_WIDTH) pc_counter(
        .branch_PC(pc + ImmOp),
        .inc_pc(pc + ADDRESS_WIDTH'd4),
        .PCsrc(PCsrc),
        .next_PC(next_PC)
    );

    i_mem #(DATA_WIDTH, ADDRESS_WIDTH) instr_mem(
        .pc(pc),
        .instr(instr)
    );

    // Control Unit
    control_unit #(DATA_WIDTH) ctrl_unit(
        .instr(instr),
        .zero(eq),  
        .PCsrc(PCsrc),
        .ResultSrc(ResultSrc),
        .MemWrite(MemWrite),
        .ALUControl(ALUControl),
        .ALUSrc(ALUSrc),
        .ImmSrc(ImmSrc),
        .RegWrite(RegWrite)
    );

    // Immediate Generator
    extend #(DATA_WIDTH) sign_extend(
        .instr(instr),
        .ImmSrc(ImmSrc),
        .ImmOp(ImmOp)
    );

    // Register File
    assign rs2 = instr[24:20];
    assign rs1 = instr[19:15];
    assign rd = instr[11:7];

    regf #(DATA_WIDTH, ADDRESS_WIDTH) registers(
        .clk(clk),
        .a1(rs1),
        .a2(rs2),
        .a3(rd),
        .we3(RegWrite),
        .wd3(ALUout),
        .rd1(ALUop1),
        .rd2(regOp2)
    );

    // ALU Operand Selection
    mux #(DATA_WIDTH) mux2(
        .in0(regOp2),
        .in1(ImmOp),
        .sel(ALUSrc),
        .out(ALUop2)
    );

    // ALU Logic
    alu #(DATA_WIDTH) alu_(
        .ALUop1(ALUop1),
        .ALUop2(ALUop2),
        .ALUctrl(ALUControl),
        .ALUout(ALUout),
        .eq(eq)
    );

endmodule