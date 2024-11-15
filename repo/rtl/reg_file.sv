module reg_file #(
    parameter WIDTH = 32,  // Width of each register
    parameter DEPTH = 32   // Number of registers
)(
    input logic             clk,        // Clock
    input logic [4:0]       ad1,        // Source register 1 address
    input logic [4:0]       ad2,        // Source register 2 address
    input logic [4:0]       as3,
    input logic             RegWrite,   // Register write enable
    input logic [WIDTH-1:0] ALUOUT,
    input logic [WIDTH-1:0] WD,         // Write data
    output logic [WIDTH-1:0] RD1,       // Read data 1
    output logic [WIDTH-1:0] RD2        // Read data 2
);

    // Register array
    logic [WIDTH-1:0] registers [0:DEPTH-1],
    assign registers[0] = {WIDTH-1{1'b0}};
    
    // Read operations
    assign RD1 = registers[rs1];
    assign RD2 = registers[rs2];

    always_ff @(posedge clk)
        // Write operations
        if(RegWrite) assign register[rd] = ALUOUT;
    

    
endmodule
