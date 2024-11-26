module counter_module #(
    parameter DATA_WIDTH = 16
)(
    // Interface signals
    input logic clk,                          // Clock
    input logic rst,                          // Reset
    input logic PCSrc,                        // Select signal for MUX 
    input logic stallF,                       // Enable bit for clk from Hazard Unit
    input logic [DATA_WIDTH-1:0] PCTarget,    // Branch target address (PC + ImmExt)
    input logic [DATA_WIDTH-1:0] PCPlus4F,     // Incremented PC (PC + 4)
    output logic [DATA_WIDTH-1:0] PCounterF    // Program Counter after clk
);

    // Internal signal for PCnext (MUX output)
    logic [DATA_WIDTH-1:0] PCnext;

    // MUX logic: Select between PCTarget and PCPlus4 based on PCSrc
    assign PCnext = PCSrc ? PCTarget : PCPlus4F;

    // Sequential logic to update PCounter on clock edge
    always_ff @(posedge clk) begin
        if (rst)
            PCounterF <= {DATA_WIDTH{1'b0}}; // Reset PCounter to 0
        else if (stallF) begin
            PCounterF <= PCnext; // Update PCounter to the next value, if the clk is enabled            
        end
            
    end

endmodule
