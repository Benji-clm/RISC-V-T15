module counter_top #(
    parameter DATA_WIDTH = 16
)(
    // Interface signals
    input logic clk,                        // Clock
    input logic rst,                        // Reset
    input logic PCSrc,                      // Select signal for MUX
    input logic stallF, 
    input logic stallD, 
    input logic flushD,
    input logic [DATA_WIDTH-1:0]  instr,
    input logic [DATA_WIDTH-1:0] ImmExt,    // Immediate value for branching
    output logic [DATA_WIDTH-1:0] PCounterF,     // Current Program Counter
    output logic [DATA_WIDTH-1:0] InstrD,
    output logic [DATA_WIDTH-1:0] PCounterD,   // after FF
    output logic [DATA_WIDTH-1:0] PCPlus4D
);

    // Internal signals
    logic [DATA_WIDTH-1:0] PCPlus4F;         // PC + 4
    logic [DATA_WIDTH-1:0] PCTarget;        // PC + ImmExt

    counter_module Counter(
        .clk(clk),
        .rst(rst),
        .PCSrc(PCSrc),
        .stallF(stallF),
        .PCTarget(PCTarget),
        .PCPlus4F(PCPlus4F),
        .PCounterF(PCounterF) // Output the current Program Counter
    );

    // Calculate PCPlus4
    assign PCPlus4F = PCounterF + {{DATA_WIDTH-3{1'b0}}, 3'b100}; // Increment PC by 4

    // Calculate PCTarget
    assign PCTarget = PCounterF + ImmExt; // Branch target address


    fetch_decode_pipe pipeline(
        .stallD(stallD),
        .flushD(flushD),
        .PCounterF(PCounterF),
        .instr(instr),
        .PCPlus4F(PCPlus4F),
        .InstrD(InstrD),
        .PCounterD(PCounterD),
        .PCPlus4D(PCPlus4D)
    );

endmodule


