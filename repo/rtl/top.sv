module top #(
    DATA_WIDTH = 32,
    ADDRESS_WIDTH = 16
) (
    input   logic clk,
    input   logic rst,
    output  logic [DATA_WIDTH-1:0] a0    
);
    assign a0 = 0;

logic [ADDRESS_WIDTH-1:0]   next_pc;
logic [DATA_WIDTH-1:0]      instr;
logic [2:0]                 LS_mode;

logic [DATA_WIDTH-1:0]      SrcAE;
logic [DATA_WIDTH-1:0]      WriteDataE;
logic [DATA_WIDTH-1:0]      SrcBE;

logic                       eq;
logic [DATA_WIDTH-1:0]      ALUResult;

// pipeline logic

// Fetch stage
logic [ADDRESS_WIDTH-1:0]                   pcF;
logic [ADDRESS_WIDTH-1:0]                   PCPlus4F;

// Decode stage
logic [DATA_WIDTH-1:0]   instrD;
logic                    RegWriteD;
logic [1:0]              ResultSrcD;
logic                    MemWriteD;
logic [2:0]              PCsrcD;
logic [3:0]              ALUControlD;
logic                    ALUsrcD;
logic [2:0]              ImmSrcD;
logic [DATA_WIDTH-1:0]   rd1;
logic [DATA_WIDTH-1:0]   rd2;
logic [DATA_WIDTH-1:0]   pcD;
logic [4:0]              Rs1D;
logic [4:0]              Rs2D;
logic [4:0]              RdD;
logic [DATA_WIDTH-1:0]   ImmExtD;
logic [DATA_WIDTH-1:0]   PCPlus4D;

// Execute stage
logic                    RegWriteE;
logic [1:0]              ResultSrcE;
logic                    MemWriteE;
logic [2:0]              PCsrcE;
logic [3:0]              ALUControlE;
logic                    ALUsrcE;
logic [DATA_WIDTH-1:0]   rd1E;
logic [DATA_WIDTH-1:0]   rd2E;
logic [DATA_WIDTH-1:0]   pcE;
logic [4:0]              Rs1E;
logic [4:0]              Rs2E;
logic [4:0]              RdE;
logic [DATA_WIDTH-1:0]   ImmExtE;
logic [DATA_WIDTH-1:0]   PCPlus4E;

// Memorystage
logic                       RegWriteM;
logic [1:0]                 ResultSrcM;
logic                       MemWriteM;
logic [DATA_WIDTH-1:0]      ALUResultM;
logic [DATA_WIDTH-1:0]      WriteDataM;
logic [4:0]                 RdM;
logic [DATA_WIDTH-1:0]      PCPlus4M;

// WriteBack stage
logic                       RegWriteW;
logic [1:0]                 ResultSrcW;
logic [DATA_WIDTH-1:0]      ALUResultW;
logic [DATA_WIDTH-1:0]      ReadDataW;
logic [4:0]                 RdW;
logic [DATA_WIDTH-1:0]      PCPlus4W;
logic [DATA_WIDTH-1:0]      ResultW;


// Data mem
logic [DATA_WIDTH-1:0]      rd;


// hazard unit logic
logic                       Hazard_PCsrc;
logic                       StallF;
logic                       StallD;
logic                       FlushD;
logic                       FlushE;
logic [1:0]                 ForwardAE;
logic [1:0]                 ForwardBE;


// control unit
logic [6:0]            op;
logic [2:0]            funct3;
logic [6:0]            funct7;

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

fetch_decode_pipe #(DATA_WIDTH) pipeline_FD(
    .clk(clk),

    // controls
    .stallD(stallD),
    .flushD(flushD),

    // inputs
    .PCounterF(pcF),
    .instr(instr),
    .PCPlus4F(PCPlus4F),

    // outputs
    .InstrD(instrD),
    .PCounterD(pcD),
    .PCPlus4D(PCPlus4D)
);

assign op = instrD[6:0];
assign funct3 = instrD[14:12];
assign funct7 = instrD[31:25];

control_unit #(DATA_WIDTH) ctrl_unit(
    .op(op),
    .funct3(funct3),
    .funct7(funct7),
    .PCsrc(PCsrcD),
    .ResultSrc(ResultSrcD),
    .MemWrite(MemWriteD),
    .ALUControl(ALUControlD),
    .ALUsrc(ALUsrcD),
    .ImmSrc(ImmSrcD),
    .RegWrite(RegWriteD),
    .LS_mode(LS_mode)
);

assign instr_ext = instrD[31:7];

SignExtend SignExtend(
    .instr(instr_ext),
    .ImmSrc(ImmSrcD),
    .ImmOp(ImmExtD)
);

assign Rs2D = instrD[24:20];
assign Rs1D = instrD[19:15];
assign RdD = instrD[11:7];

regf #(DATA_WIDTH, ADDRESS_WIDTH) registers(
    .clk(clk),
    .a1(Rs1D),
    .a2(Rs2D),
    .a3(rdW),
    .we3(RegWriteW),
    .wd3(ResultW),
    .rd1(rd1),
    .rd2(rd2),
    .a0(a0)
);

decode_execute_pipe #(DATA_WIDTH) pipeline_DE_inst (
    // Pipeline control inputs
    .clk(clk),
    .FlushE(FlushE),

    // Control unit inputs
    .RegWriteD(RegWriteD),
    .ResultSrcD(ResultSrcD),
    .MemWriteD(MemWriteD),
    .PCsrcD(PCsrcD),
    .ALUControlD(ALUControlD),
    .ALUsrcD(ALUsrcD),

    // Register file, extend, and PC inputs
    .rd1(rd1),
    .rd2(rd2),
    .pcD(pcD),
    .PCPlus4D(PCPlus4D),
    .Rs1D(Rs1D),
    .Rs2D(Rs2D),
    .RdD(RdD),
    .ImmExtD(ImmExtD),    

    // Outputs to the next stage
    .RegWriteE(RegWriteE),
    .ResultSrcE(ResultSrcE),
    .MemWriteE(MemWriteE),
    .PCsrcE(PCsrcE),
    .ALUControlE(ALUControlE),
    .ALUsrcE(ALUsrcE),
    .rd1E(rd1E),
    .rd2E(rd2E),
    .pcE(pcE),
    .PCPlus4E(PCPlus4E),
    .Rs1E(Rs1E),
    .Rs2E(Rs2E),
    .RdE(RdE),
    .ImmExtE(ImmExtE)
);

mux3 #(DATA_WIDTH) muxForwardAE(
    .in0(rd1E),
    .in1(ResultW),
    .in2(ALUResultM),
    .sel(ForwardAE),
    .out(SrcAE)
);

mux3 #(DATA_WIDTH) muxForwardBE(
    .in0(rd2E),
    .in1(ResultW),
    .in2(ALUResultM),
    .sel(ForwardBE),
    .out(WriteDataE)
);

mux #(DATA_WIDTH) mux2(
    .in0(WriteDataE),
    .in1(ImmExtE),
    .sel(ALUsrcE),
    .out(SrcBE)
);

alu #(DATA_WIDTH) alu_(
    .ALUop1(SrcAE),
    .ALUop2(SrcBE),
    .ALUctrl(ALUControlE),
    .ALUout(ALUResult),
    .eq(eq)
);

execute_mem_pipe #(DATA_WIDTH) pipeline_EM(
    .clk(clk),                           // Clock signal
    .flush(1'b0),                        // Assuming flush is not used in this context, set to 0 or connect appropriately

    // Inputs from EX stage
    .alu_result(ALUResult),              // ALU result from EX stage
    .write_data(WriteDataE),             // Write data (for store operations)
    .daddr(PCPlus4E),                    // Data memory address (using PCPlus4E as a placeholder)
    .mem_write(MemWriteE),               // Memory write enable signal
    .mem_read(1'b0),                     // Assuming mem_read is not used; set appropriately if needed
    .funct3(3'b000),                     // Assuming funct3 is not provided; set appropriately if needed
    .reg_dest(RdE),                      // Register destination from EX stage

    // Outputs to MEM stage
    .mem_alu_result(ALUResultM),         // ALU result to MEM stage
    .mem_write_data(WriteDataM),         // Write data to MEM stage
    .mem_daddr(PCPlus4M),                // Data memory address to MEM stage
    .mem_mem_write(MemWriteM),           // Memory write enable to MEM stage
    .mem_mem_read(ResultSrcM),           // Memory read enable to MEM stage (mapped from ResultSrcM)
    .mem_funct3(3'b000),                 // Function control (if used, map appropriately)
    .mem_reg_dest(RdM)                   // Register destination to MEM stage
);


mem_writeback_pipe #(DATA_WIDTH) pipeline_MW_inst(
    .clk(clk),                          // Clock signal
    .flush(1'b0),                       // Assuming flush is not being used in this context, set to 0 or connect appropriately

    // Inputs from MEM stage
    .mem_alu_result(ALUResultM),        // ALU result from MEM stage
    .mem_mem_data(PCPlus4M),            // Memory data or equivalent, assuming PCPlus4M is used here as memory data
    .mem_reg_dest(RdM),                 // Register destination from MEM stage
    .mem_reg_write(RegWriteM),          // Register write enable from MEM stage

    // Outputs to WB stage
    .wb_data(ALUResultW),               // Data to write back to the register file
    .wb_reg_dest(RdW),                  // Register destination to WB stage
    .wb_reg_write(RegWriteW)            // Register write enable to WB stage
);

mux3 #(DATA_WIDTH) mux3_(
    .in0(ALUResultW),
    .in1(ReadDataW),
    .in2(PCPlus4W),
    .sel(ResultSrcW),
    .out(ResultW)
);

hazard_unit hazard_unit_(
    // inputs/controls
    .Rs1D(Rs1D),
    .Rs2D(Rs2D),
    .Rs1E(Rs1E),
    .Rs2E(Rs2E),
    .RdE(RdE),
    .Hazard_PCsrc(Hazard_PCsrc),
    .ResultSrcE(ResultSrcE),
    .RdM(RdM),
    .RdW(RdW),
    .RegWriteM(RegWriteM),
    .RegWriteW(RegWriteW),

    // outputs
    .StallF(StallF),
    .StallD(StallD),
    .FlushD(FlushD),
    .FlushE(FlushE),
    .ForwardAE(ForwardAE),
    .ForwardBE(ForwardBE)
);

top_mem top_memory_inst (
        .clk(clk),                      
        .we(we),            
        .funct3(funct3),                
        .daddr(ALUResultM),              
        .wd_data(WriteDataM),       
        .cache_hit(cache_hit),                      
        .out(ReadDataW)               
    );



endmodule
