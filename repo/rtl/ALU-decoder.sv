module ALU_decoder (
    input  logic [6:0]       op,
    input  logic [2:0]       funct3,
    input  logic             funct7,
    input  logic [1:0]       ALUOp,
    output logic [2:0]       ALUControl
);

logic [1:0] opfunct;

always_comb begin
    ALUControl = 3'b000;
    opfunct = {op[5], funct7}; 

    case (ALUOp)
        2'b00: ALUControl = 3'b000; // ADD
        2'b01: ALUControl = 3'b001; // SUB
        2'b10: begin
            case (funct3)
                3'b000: 
                    ALUControl = (opfunct == 2'b11) ? 3'b001 : 3'b000; // ADD or SUB
                3'b010: ALUControl = 3'b101; // SLT
                3'b110: ALUControl = 3'b011; // OR
                3'b111: ALUControl = 3'b010; // AND
                default: ALUControl = 3'b000;
            endcase
        end
        default: ALUControl = 3'b000; 
    endcase
end

endmodule