module reg_file #(
    parameter WIDTH = 32,  // Width of each register
    parameter DEPTH = 32   // Number of registers
)(
    input logic             clk,        // Clock
    input logic [4:0]       ad1,        // Source register 1 address
    input logic [4:0]       ad2,        // Source register 2 address
    input logic [4:0]       as3,        // Destination register address
    input logic             RegWrite,   // Register write enable
    input logic [WIDTH-1:0] WD,         // Write data
    output logic [WIDTH-1:0] RD1,       // Read data 1
    output logic [WIDTH-1:0] RD2        // Read data 2
);

    // Register array
    logic [WIDTH-1:0] registers [0:DEPTH-1];

    assign RD1 = (ad1 != 0) ? registers[ad1] : 0;
    assign RD2 = (ad2 != 0) ? registers[ad2] : 0;

    always_ff @(posedge clk) begin
        // Write operations
        if (RegWrite && as3 != 0) begin
            registers[as3] <= WD;
        end
    end

endmodule
