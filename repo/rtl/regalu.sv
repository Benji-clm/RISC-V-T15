module regalu#(
    parameter DATA_WIDTH = 32
)(
    input logic clk,
    input logic [4:0] rs1,
    input logic [4:0] rs2,
    input logic [4:0] rd,
    input logic [DATA_WIDTH-1:0] ImmOp,
    input logic ALUsrc,
    input logic ALUctrl,
    input logic regwrite,
    input logic [DATA_WIDTH-1:0] ALUout,
    output logic [DATA_WIDTH-1:0] rd1,
    output logic [DATA_WIDTH-1:0] rd2
);

    regfile regfile(
        .clk (clk),
        .ALUout (ALUout),
        .rs1 (rs1),
        .rs2 (rs2),
        .rd (rd),
        .regwrite (regwrite),
        .rd1 (rd1), 
        .rd2 (rd2)
    )
    
    mux mux(
        .in0 (rd2),
        .in1 (ImmOp), // sign extended ImmOp from Control Unit
        .sel (ALUsrc),
        .out (out)
    )

    alu alu(
        .clk (clk),
        .in1 (rd1),
        .in2 (out),
        .ALUctrl (ALUctrl),
        .ALUout (ALUout);
        .eq (eq);  
    )

    endmodule
