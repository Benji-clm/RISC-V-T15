module main_decoder (
    input  logic [6:0]            op,
    output logic                  ResultSrc,
    output logic                  MemWrite,
    output logic                  ALUSrc,
    output logic [1:0]            ImmSrc,
    output logic                  RegWrite,
    output logic                  Branch,
    output logic [1:0]            ALUOp
);

always_comb begin
    logic [7:0] control; 
    
    unique case (op)
        7'b0000011: control = 8'b1010_1000; // lw: RegWrite=1, ALUSrc=1, ImmSrc=00, ResultSrc=1
        7'b0100011: control = 8'b0101_0000; // sw: MemWrite=1, ALUSrc=1, ImmSrc=01
        7'b0110011: control = 8'b0000_0010; // R-type: RegWrite=1, ALUOp=10
        7'b1100011: control = 8'b0000_1101; // beq: Branch=1, ImmSrc=10, ALUOp=01
        default:    control = 8'b0000_0000; // Default
    endcase

    {ResultSrc, MemWrite, ALUSrc, ImmSrc, RegWrite, Branch, ALUOp} = control;
end

endmodule