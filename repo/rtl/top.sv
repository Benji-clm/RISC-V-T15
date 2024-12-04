module top #(
    DATA_WIDTH = 32,
    ADDRESS_WIDTH = 32,
    MEMORY_WIDTH = 8
) (
    input   logic clk,
    input   logic rst,
    input   logic trigger,
    output  logic [DATA_WIDTH-1:0] a0    
);
    assign a0 = 0;

logic [ADDRESS_WIDTH-1:0]   next_pc;
logic [DATA_WIDTH-1:0]      instr;

logic [DATA_WIDTH-1:0]      SrcAE;
logic [DATA_WIDTH-1:0]      WriteDataE;
logic [DATA_WIDTH-1:0]      SrcBE;

logic                       eq;
logic [DATA_WIDTH-1:0]      ALUResult;

// pipeline logic

// Fetch stage
logic [ADDRESS_WIDTH-1:0]   pcF;
logic [ADDRESS_WIDTH-1:0]   PCPlus4F;

// Decode stage
logic [DATA_WIDTH-1:0]      instrD;
logic                       RegWriteD;
logic [1:0]                 ResultSrcD;
logic                       MemWriteD;
logic [2:0]                 PCsrcD;
logic [3:0]                 ALUControlD;
logic                       ALUsrcD;
logic [2:0]                 ImmSrcD;
logic [DATA_WIDTH-1:0]      rd1;
logic [DATA_WIDTH-1:0]      rd2;
logic [DATA_WIDTH-1:0]      pcD;
logic [4:0]                 Rs1D;
logic [4:0]                 Rs2D;
logic [4:0]                 RdD;
logic [DATA_WIDTH-1:0]      ImmExtD;
logic [DATA_WIDTH-1:0]      PCPlus4D;
logic [2:0]                 LS_modeD;

// Execute stage
logic                       RegWriteE;
logic [1:0]                 ResultSrcE;
logic                       MemWriteE;
logic [2:0]                 PCsrcE;
logic [3:0]                 ALUControlE;
logic                       ALUsrcE;
logic [DATA_WIDTH-1:0]      rd1E;
logic [DATA_WIDTH-1:0]      rd2E;
logic [DATA_WIDTH-1:0]      pcE;
logic [4:0]                 Rs1E;
logic [4:0]                 Rs2E;
logic [4:0]                 RdE;
logic [DATA_WIDTH-1:0]      ImmExtE;
logic [DATA_WIDTH-1:0]      PCPlus4E;
logic [2:0]                 LS_modeE;

// Memorystage
logic                       RegWriteM;
logic [1:0]                 ResultSrcM;
logic                       MemWriteM;
logic [DATA_WIDTH-1:0]      ALUResultM;
logic [DATA_WIDTH-1:0]      WriteDataM;
logic [4:0]                 RdM;
logic [DATA_WIDTH-1:0]      PCPlus4M;
logic [2:0]                 LS_modeM;

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

logic MemReadD;
logic MemReadE;
logic MemReadM;

// control unit
logic [6:0]            op;
logic [2:0]            funct3;
logic [6:0]            funct7;

logic [31:7]           instr_ext;

assign PCPlus4F = pcF +4;

counter_module #(ADDRESS_WIDTH) pc_counter(
    .PCsrcE(PCsrcE),
    .PCPlus4F(PCPlus4F),
    .PCTargetE(pcE + ImmExtE),
    .ALUResult(ALUResult),
    .eq(eq),
    .Hazard_PCsrc(Hazard_PCsrc),
    .pc(next_pc)
);

always_ff @(posedge clk) begin
    if (!StallF) begin
        pcF <= rst ? 32'h0 : next_pc;
    end
end


i_mem #(DATA_WIDTH) instr_mem(
    .pc(pcF),
    .instr(instr)
);

fetch_decode_pipe #(DATA_WIDTH) pipeline_FD(
    .clk(clk),

    // controls
    .StallD(StallD),
    .FlushD(FlushD),

    // inputs
    .pcF(pcF),
    .instr(instr),
    .PCPlus4F(PCPlus4F),

    // outputs
    .instrD(instrD),
    .pcD(pcD),
    .PCPlus4D(PCPlus4D)
);

assign op = instrD[6:0];
assign funct3 = instrD[14:12];
assign funct7 = instrD[31:25];

control_unit ctrl_unit(
    .op(op),
    .stall(StallD),
    .funct3(funct3),
    .funct7(funct7),
    .PCsrc(PCsrcD),
    .ResultSrc(ResultSrcD),
    .MemWrite(MemWriteD),
    .ALUControl(ALUControlD),
    .ALUsrc(ALUsrcD),
    .ImmSrc(ImmSrcD),
    .RegWrite(RegWriteD),
    .LS_mode(LS_modeD),
    .MemRead(MemReadD)
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

regf #(DATA_WIDTH) registers(
    .clk(clk),
    .a1(Rs1D),
    .a2(Rs2D),
    .a3(RdW),
    .we3(RegWriteW),
    .wd3(ResultW),
    .rd1(rd1),
    .rd2(rd2),
    .a0(a0),
    .t0(trigger)
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
    .MemReadD(MemReadD),

    // Register file, extend, and PC inputs
    .rd1(rd1),
    .rd2(rd2),
    .pcD(pcD),
    .PCPlus4D(PCPlus4D),
    .Rs1D(Rs1D),
    .Rs2D(Rs2D),
    .RdD(RdD),
    .ImmExtD(ImmExtD),
    .LS_modeD(LS_modeD),  

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
    .ImmExtE(ImmExtE),
    .LS_modeE(LS_modeE),
    .MemReadE(MemReadE)
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
    .clk(clk),                                                  

    // Inputs from EX stage
    .ALUResult(ALUResult),              
    .WriteDataE(WriteDataE),             
    .PCPlus4E(PCPlus4E),                    
    .MemWriteE(MemWriteE),                                   
    .LS_modeE(LS_modeE),                     
    .RdE(RdE), 
    .ResultSrcE(ResultSrcE),   
    .RegWriteE(RegWriteE),                
    .MemReadE(MemReadE),

    // Outputs to MEM stage
    .ALUResultM(ALUResultM),         // ALU result to MEM stage
    .WriteDataM(WriteDataM),         // Write data to MEM stage
    .PCPlus4M(PCPlus4M),                // Data memory address to MEM stage
    .MemWriteM(MemWriteM),           // Memory write enable to MEM stage
    .ResultSrcM(ResultSrcM),           // Memory read enable to MEM stage (mapped from ResultSrcM)
    .LS_modeM(LS_modeM),                 // Function control (if used, map appropriately)
    .RdM(RdM),                   // Register destination to MEM stage
    .RegWriteM(RegWriteM),
    .MemReadM(MemReadM)
);

top_mem top_memory_inst (
        .clk(clk),                      
        .we(MemWriteM),            
        .LS_mode(LS_modeM),
        .MemRead(MemReadM),                
        .a(ALUResultM),              
        .wd(WriteDataM),       
        .rd(rd)               
    );

mem_writeback_pipe #(DATA_WIDTH) pipeline_MW_inst(
    .clk(clk),                          // Clock signal

    // Inputs from MEM stage
    .ALUResultM(ALUResultM),        // ALU result from MEM stage
    .PCPlus4M(PCPlus4M),            // Memory data or equivalent, assuming PCPlus4M is used here as memory data
    .RdM(RdM),                 // Register destination from MEM stage
    .RegWriteM(RegWriteM),          // Register write enable from MEM stage
    .rd(rd),
    .ResultSrcM(ResultSrcM),

    // Outputs to WB stage
    .ALUResultW(ALUResultW),               // Data to write back to the register file
    .RdW(RdW),                  // Register destination to WB stage
    .RegWriteW(RegWriteW),            // Register write enable to WB stage
    .PCPlus4W(PCPlus4W),
    .ReadDataW(ReadDataW),
    .ResultSrcW(ResultSrcW)
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
    .ResultSrcE(ResultSrcE[0]),
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





endmodule
