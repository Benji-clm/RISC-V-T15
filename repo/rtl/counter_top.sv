counter_top #(
    parameter DATA_WIDTH = 16
)(
    // Interface signals
    input logic clk,                        // Clock
    input logic rst,                        // Reset
    input logic PCSrc,                      // Select signal for MUX
    input logic [DATA_WIDTH-1:0] ImmExt,    // Immediate value for branching
    output logic [DATA_WIDTH-1:0] PC       // Current Program Counter
);

    // Internal signals
    logic [DATA_WIDTH-1:0] PCPlus4;         // PC + 4
    logic [DATA_WIDTH-1:0] PCTarget;        // PC + ImmExt
    logic [DATA_WIDTH-1:0] PCnext;          // Output of MUX (next PC)

    counter_module Counter(
        .clk(clk),
        .rst(rst),
        .PCSrc(PCSrc),
        .PCTarget(PCTarget),
        .PCPlus4(PCPlus4),
        .PCounter(PC) // Output the current Program Counter
    );

    // Calculate PCPlus4
    assign PCPlus4 = PC + {{DATA_WIDTH-3{1'b0}}, 3'b100}; // Increment PC by 4

    // Calculate PCTarget
    assign PCTarget = PC + ImmExt; // Branch target address
