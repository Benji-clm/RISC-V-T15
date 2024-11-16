module ALU#(
    parameter DATA_WIDTH = 32
)(
    input logic clk,
    input logic [DATA_WIDTH-1:0] in1,
    input logic [DATA_WIDTH-1:0] in2,
    input logic [2:0] ALUctrl,
    output logic [DATA_WIDTH-1:0] ALUout,
    output logic eq
);

    logic [DATA_WIDTH-1:0] sub;  

    // Combinational logic for subtraction
    assign sub = in1 - in2;

    // Sequential logic for ALU operations
    always_ff @(posedge clk) begin
        // Set default values to avoid latches
        ALUout <= 0;
        eq <= 0;

        case (ALUctrl)
            3'b000: begin
                ALUout <= in1 + in2; // Addition
            end
            3'b001: begin
                ALUout <= sub;       // Subtraction
                eq <= (sub == 0);    // Set eq if sub is zero
            end
            // Add more cases for other ALU operations
            default: begin
                ALUout <= 0;         // Default output
                eq <= 0;
            end
        endcase
    end

endmodule

