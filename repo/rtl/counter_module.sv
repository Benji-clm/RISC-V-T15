module counter_module #(
    parameter DATA_WIDTH = 16
)(
    // Interface signals
    input logic clk,                          // Clock
    input logic rst,                          // Reset
    input logic PCSrc,                        // Select signal for MUX
    input logic [DATA_WIDTH-1:0] PCTarget,    // Branch target address (PC + ImmExt)
    input logic [DATA_WIDTH-1:0] PCPlus4,     // Incremented PC (PC + 4)
    output logic [DATA_WIDTH-1:0] PCounter    // Program Counter after clk
);

    // Internal signal for PCnext (MUX output)
    logic [DATA_WIDTH-1:0] PCnext;

    // MUX logic: Select between PCTarget and PCPlus4 based on PCSrc
    assign PCnext = PCSrc ? PCTarget : PCPlus4;

    // Sequential logic to update PCounter on clock edge
    always_ff @(posedge clk) begin
        if (rst)
            PCounter <= {DATA_WIDTH{1'b0}}; // Reset PCounter to 0
        else
            PCounter <= PCnext; // Update PCounter to the next value
    end

endmodule
