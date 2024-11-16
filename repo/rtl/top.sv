module top #(
    parameter DATA_WIDTH = 32,
    parameter ADDRESS_WIDTH = 16
) (
    input   logic clk,
    input   logic rst,
    output  logic [DATA_WIDTH-1:0] a0    
);

    assign a0 = 5;

    /* verilator lint_off UNUSEDSIGNAL */
    logic [ADDRESS_WIDTH-1:0]   pc, next_PC;
    logic [DATA_WIDTH-1:0]      ImmOp, instr, ALUop1, regOp2, ALUop2, ALUout;
    logic                       PCsrc, ResultSrc, MemWrite, ALUSrc, RegWrite, eq;
    logic [2:0]                 ALUctrl;
    logic [1:0]                 ImmSrc;
    logic [4:0]                 rs1, rs2, rd;
    /* verilator lint_on UNUSEDSIGNAL */

    always_comb begin
        next_PC = pc + 16'h1; // Increment PC by 1
    end


    always_ff @(posedge clk) begin
        if (rst)
            pc <= {ADDRESS_WIDTH{1'b0}};  // Reset pc to zero
        else if (PCsrc)
            pc <= pc + ImmOp[ADDRESS_WIDTH-1:0];             // Branch address computation directly
        else
            pc <= next_PC;                // Default behavior: Increment PC
    end


    counter #(ADDRESS_WIDTH) pc_counter (
        .clk(clk),              // Connect the clock signal
        .rst(rst),              // Connect the reset signal
        .next_PC(next_PC),      // Provide the next program counter value
        .p_count(pc)            // Capture the output program counter value
    );


    i_mem #(DATA_WIDTH, ADDRESS_WIDTH) instr_mem(
        .pc(pc),
        .instr(instr)
    );

    // Control Unit
    control_unit #(DATA_WIDTH) ctrl_unit(
        .instr(instr),
        .zero(eq),  
        .PCSrc(PCsrc),
        .ResultSrc(ResultSrc),
        .MemWrite(MemWrite),
        .ALUctrl(ALUctrl),
        .ALUSrc(ALUSrc),
        .ImmSrc(ImmSrc),
        .RegWrite(RegWrite)
    );

    // Immediate Generator
    SignExtend sign_extend (
        .instr(instr),    // Connect the instruction signal
        .ImmSrc(ImmSrc),  // Connect the immediate source signal
        .ImmOp(ImmOp)     // Connect the immediate operand output
    );


    // Register File
    assign rs2 = instr[24:20];
    assign rs1 = instr[19:15];
    assign rd = instr[11:7];

    regfile #(32, DATA_WIDTH) reg_instance (
        .clk(clk),             // Connect clock signal
        .rst(rst),             // Connect reset signal
        .rs1(rs1),             // Source register 1 address
        .rs2(rs2),             // Source register 2 address
        .rd(rd),               // Destination register address
        .regwrite(RegWrite),   // Register write enable
        .ALUout(ALUout),       // Write data
        .rd1(ALUop1),          // Read data 1
        .rd2(regOp2)           // Read data 2
    );


    // ALU Operand Selection
    mux #(DATA_WIDTH) mux2(
        .in0(regOp2),
        .in1(ImmOp),
        .sel(ALUSrc),
        .out(ALUop2)
    );

    // ALU Logic
    ALU #(DATA_WIDTH) alu_ (
        .clk(clk),                // Clock signal
        .in1(ALUop1),             // Operand 1
        .in2(ALUop2),             // Operand 2
        .ALUctrl(ALUctrl),        // ALU control signals
        .ALUout(ALUout),          // ALU result
        .eq(eq)                   // Equality output
    );


endmodule
