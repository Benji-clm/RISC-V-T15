module top #(
    DATA_WIDTH = 32,
    ADDRESS_WIDTH = 32
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
logic                       Flush;
logic [1:0]                 ForwardAE;
logic [1:0]                 ForwardBE;

logic MemReadD;
logic MemReadE;
logic MemReadM;

// control unit
logic [6:0]                 op;
logic [2:0]                 funct3;
logic [6:0]                 funct7;

logic [31:7]                instr_ext;


// Branch prediction
logic [ADDRESS_WIDTH-1:0]   targetE;
logic                       branch_predictF;
logic                       branch_predictD;
logic                       branch_predictE;
logic [ADDRESS_WIDTH-1:0]   branch_target;
logic [ADDRESS_WIDTH-1:0]   pc;
logic                       prediction_penalty;

assign PCPlus4F = pcF + 4;
assign targetE  = pcE + ImmExtE;

counter_module #(ADDRESS_WIDTH) pc_counter(
    .PCsrcE(PCsrcE),
    .PCPlus4F(PCPlus4F),
    .PCTargetE(targetE),
    .ALUResult(ALUResult),
    .eq(eq),
    .branch_predictE(branch_predictE),
    .Hazard_PCsrc(Hazard_PCsrc),
    .pc(pc)
);

branch_pred #(ADDRESS_WIDTH, 64, 6) branch_prediction (
    .clk(clk),
    .reset(rst),
    .pcF(pcF),
    .pcE(pcE),
    .branch_valid(PCsrcE[1]),
    .branch_taken(Hazard_PCsrc),
    .targetE(targetE),
    .branch_predictF(branch_predictF),
    .branch_targetF(branch_target)
);

assign prediction_penalty = (Hazard_PCsrc != branch_predictE);
assign next_pc = branch_predictF ? branch_target : pc;


always_ff @(posedge clk) begin
    if (prediction_penalty && PCsrcE[1]) begin
        pcF <= rst ? 32'h0 : pcE;
    end
    else if (!StallF) begin
        pcF <= rst ? 32'h0 : next_pc;
    end
end 

i_cache cache (
    .clk(clk),
    .reset(rst),
    .pc(pcF),
    .instr(instr)
);

fetch_decode_pipe #(DATA_WIDTH) pipeline_FD(
    .clk(clk),

    // controls
    .StallD(StallD),
    .FlushD(Flush),

    // inputs
    .pcF(pcF),
    .instr(instr),
    .PCPlus4F(PCPlus4F),
    .branch_predictF(branch_predictF),

    // outputs
    .instrD(instrD),
    .pcD(pcD),
    .PCPlus4D(PCPlus4D),
    .branch_predictD(branch_predictD)
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
    .FlushE(Flush),

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
    .branch_predictD(branch_predictD),  

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
    .MemReadE(MemReadE),
    .branch_predictE(branch_predictE)
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
    .ALUResultM(ALUResultM),
    .WriteDataM(WriteDataM),
    .PCPlus4M(PCPlus4M),
    .MemWriteM(MemWriteM),
    .ResultSrcM(ResultSrcM),
    .LS_modeM(LS_modeM),
    .RdM(RdM),
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
    .clk(clk),

    // Inputs from MEM stage
    .ALUResultM(ALUResultM),
    .PCPlus4M(PCPlus4M),
    .RdM(RdM),
    .RegWriteM(RegWriteM),
    .rd(rd),
    .ResultSrcM(ResultSrcM),

    // Outputs to WB stage
    .ALUResultW(ALUResultW),
    .RdW(RdW),
    .RegWriteW(RegWriteW),
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
    .Hazard_PCsrc(prediction_penalty),
    .ResultSrcE(ResultSrcE[0]),
    .RdM(RdM),
    .RdW(RdW),
    .RegWriteM(RegWriteM),
    .RegWriteW(RegWriteW),

    // outputs
    .StallF(StallF),
    .StallD(StallD),
    .Flush(Flush),
    .ForwardAE(ForwardAE),
    .ForwardBE(ForwardBE)
);

endmodule
