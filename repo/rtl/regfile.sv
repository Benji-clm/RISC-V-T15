module regfile #(
    parameter DEPTH = 32,       // Depth of the register file
    parameter DATA_WIDTH = 32   // Data width of each register
)(
    input logic clk,            // Clock signal
    input logic rst,            // Reset signal
    input logic [4:0] rs1,      // Source register 1 address
    input logic [4:0] rs2,      // Source register 2 address
    input logic [4:0] rd,       // Destination register address
    input logic regwrite,       // Register write enable
    input logic [DATA_WIDTH-1:0] ALUout, // Write data
    output logic [DATA_WIDTH-1:0] rd1,   // Read data 1
    output logic [DATA_WIDTH-1:0] rd2    // Read data 2
);

    // Register file array
    logic [DATA_WIDTH-1:0] registers [0:DEPTH-1];

    // Initialize register 0 to 0
    assign registers[0] = {DATA_WIDTH{1'b0}};

    // Read data
    assign rd1 = registers[rs1];
    assign rd2 = registers[rs2];

    // Write data
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            // Reset all registers
            for (int i = 0; i < DEPTH; i++) begin
                registers[i] <= {DATA_WIDTH{1'b0}};
            end
        end else if (regwrite && rd != 0) begin
            registers[rd] <= ALUout; // Write to destination register
        end
    end

endmodule
