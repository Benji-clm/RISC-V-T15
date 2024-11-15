module reg_file#(
    parameter DATA_WIDTH = 32
    parameter DEPTH = 32
)(
    input logic clk,
    input logic [4:0] rs1,
    input logic [4:0] rs2,
    input logic [4:0] rd,
    input logic regwrite,
    input logic [DATA_WIDTH-1:0] ALUout,
    output logic [DATA_WIDTH-1:0] rd1,
    output logic [DATA_WIDTH-1:0] rd2
);

logic [WIDTH-1: 0] registers [0:DEPTH-1];
assign registers[0] = {WIDTH-1{1'b0}};

always_ff (@posedge clk)
    assign rd1 = registers[1];
    assign rd2 = registers[2];
    if (regwrite)
        assign registers[rd] = ALUout;
    


endmodule
