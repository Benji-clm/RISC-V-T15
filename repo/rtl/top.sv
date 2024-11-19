module top #(
    DATA_WIDTH = 32,
    ADDRESS_WIDTH = 16
) (
    input   logic clk,
    input   logic rst,
    output  logic [DATA_WIDTH-1:0] a0    
);
    assign a0 = 0;

logic [ADDRESS_WIDTH-1:0]   pc;
logic [ADDRESS_WIDTH-1:0]   ImmOp;
logic                       PCsrc;
logic [ADDRESS_WIDTH-1:0]   next_PC;
logic [DATA_WIDTH-1:0]      instr;
logic                       ResultSrc;
logic                       MemWrite;
logic [2:0]                 ALUControl;
logic                       ALUSrc;
logic [1:0]                 ImmSrc;
logic                       RegWrite;

logic [4:0]                 rs1;
logic [4:0]                 rs2;
logic [4:0]                 rd;

logic [DATA_WIDTH-1:0]      ALUop1;
logic [DATA_WIDTH-1:0]      regOp2;
logic [DATA_WIDTH-1:0]      ALUop2;

logic                       eq;
logic [DATA_WIDTH-1:0]      ALUout;

pc #(ADDRESS_WIDTH) pc_counter(
    .clk(clk),
    .rst(rst),
    .branch_PC(pc + ImmOp),
    .inc_pc(pc + 4),
    .PCsrc(PCsrc),
    .next_PC(next_PC)
);

assign pc = next_PC;

i_mem #(DATA_WIDTH, ADDRESS_WIDTH) instr_mem(
    .pc(pc),
    .instr(instr)
);


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

signextend #(DATA_WIDTH) signextend(
    .instr(instr),
    .ImmSrc(ImmSrc),
    .ImmOp(ImmOp)
);

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
    .rd2(regOp2),
    .a0(a0)
);

mux #(DATA_WIDTH) mux2(
    .in0(regOp2),
    .in1(ImmOp),
    .sel(ALUSrc),
    .out(ALUop2)
);

alu #(DATA_WIDTH) alu_(
    .ALUop1(ALUop1),
    .ALUop2(ALUop2),
    .ALUctrl(ALUControl),
    .ALUout(ALUout),
    .eq(eq)
);



endmodule
