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
    // we start by setting all the ouputs to their default value (0?)
    ResultSrc = 0;
    MemWrite = 0;
    ALUSrc = 0;
    ImmSrc = 2'b00;
    RegWrite = 0;
    Branch = 0;
    ALUOp = 2'b00;

    case (op)
        // lw opcode
        7'b0000011: begin
            RegWrite = 1;
            ImmSrc = 2'b00;
            ALUSrc = 1;
            MemWrite = 0;
            ResultSrc = 1;
            Branch = 0;
            ALUOp = 2'b00;
        end

        // sw
        7'b0100011: begin
            RegWrite = 0;
            ImmSrc = 2'b01;
            ALUSrc = 1;
            MemWrite = 1;
            ResultSrc = 0; // ResultSrc is a don't care states
            Branch = 0;
            ALUOp = 2'b00;
        end

        // R-type
        7'b0110011: begin
            RegWrite = 1;
            ImmSrc = 2'b00; // don't care state
            ALUSrc = 0;
            MemWrite = 0;
            ResultSrc = 0;
            Branch = 0;
            ALUOp = 2'b10;
        end

        // beq
        7'b1100011: begin
            RegWrite = 0;
            ImmSrc = 2'b10;
            ALUSrc = 0;
            MemWrite = 0;
            ResultSrc = 0;
            Branch = 1;
            ALUOp = 2'b01;
        end

        default: begin
        end

    endcase
    
end


endmodule
