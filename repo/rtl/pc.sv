module pc #(
    parameter ADDRESS_WIDTH = 16
) (
    input  logic                     clk,         // Clock input
    input  logic                     rst,         // Reset input
    input  logic [ADDRESS_WIDTH-1:0] branch_PC,   // Branch address
    input  logic [ADDRESS_WIDTH-1:0] inc_pc,      // Incremented PC address
    input  logic                     PCsrc,       // PC source selection
    output logic [ADDRESS_WIDTH-1:0] next_PC     // Current PC
);

    // Next PC selection logic
    logic [ADDRESS_WIDTH-1:0] pctemp;
    assign pctemp = PCsrc ? branch_PC : inc_pc;

    // PC update logic
    always @(posedge clk or posedge rst) begin
        if (rst)
            next_PC <= 0; // Reset PC to 0
        else
            next_PC <= pctemp; // Update PC
    end

endmodule
