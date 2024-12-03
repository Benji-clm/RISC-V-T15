module counter_top #(
    parameter DATA_WIDTH = 16
)(
    // Interface signals
    input logic clk,                        // Clock
    input logic rst,                        // Reset
    input logic PCSrcE,                      // Select signal for MUX
    input logic StallF,  
    input logic [DATA_WIDTH-1:0]  instr,
    input logic [DATA_WIDTH-1:0] ImmExt,    // Immediate value for branching
    output logic [DATA_WIDTH-1:0] pcF,     // Current Program Counter
);

    // Internal signals
    logic [DATA_WIDTH-1:0] PCPlus4F;         // PC + 4
    logic [DATA_WIDTH-1:0] PCTarget;        // PC + ImmExt
    logic [DATA_WIDTH-1:0] PCounterF;

    // Calculate PCPlus4
    assign PCPlus4F = PCounterF + {{DATA_WIDTH-3{1'b0}}, 3'b100}; // Increment PC by 4

    // Calculate PCTarget
    assign PCTarget = PCounterF + ImmExt; // Branch target address

    counter_module Counter(
        .PCSrcE(PCSrcE),
        .PCTargetE(PCTargetE),
        .PCPlus4F(PCPlus4F),
        .ALUResult(ALUResult),
        .eq(eq),
        .pc(PCounterF),
        .Hazard_PCsrc(Hazard_PCsrc)
    );


    always_ff @(posedge clk) begin
        if (!StallF) begin 
            pcF <=  rst ? '0 :PCounterF;       
        end            
    end


    i_mem #(DATA_WIDTH, ADDRESS_WIDTH) instr_mem(
    .pc(pc),
    .instr(instr)   
    );


endmodule


