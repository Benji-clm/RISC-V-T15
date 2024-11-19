module alu_decoder (
    input  logic             op,
    input  logic [2:0]       funct3,
    input  logic             funct7,
    input  logic [1:0]       ALUOp,
    output logic [2:0]       ALUControl
);

logic [1:0] opfunct;

always_comb begin
    // Set default ouput (add)
    ALUControl = 3'b000;

    opfunct = {op, funct7};

    case(ALUOp)

        2'b00: ALUControl = 3'b000; // add

        // 01 represnts all branching operations
        2'b01: begin
            case(funct3)

                3'b000: ALUControl = 3'b001; //beq
                3'b001: ALUControl = 3'b001;

            endcase
        end
    
        2'b10: begin

            case(funct3)

                3'b000: begin
                    case(opfunct)
                        2'b00, 2'b01, 2'b10: ALUControl = 3'b000;
                        2'b11: ALUControl = 3'b001;
                    endcase
                end

                3'b010: ALUControl = 3'b101; // Set less than
                3'b110: ALUControl = 3'b011; // or
                3'b111: ALUControl = 3'b010; // and
            endcase
        end
        default: ALUControl = 3'b000;
    endcase
end 

endmodule
