module ControlUnit (
    input logic [31:0] instr,         // 32-bit instruction input
    output logic RegWrite,            // Register write enable
    output logic [3:0] ALUCtl,        // ALU control signal
    output logic ALUSrc,              // ALU source select (1 = immediate, 0 = register)
    output logic [1:0] ImmSrc,        // Immediate source selection
    output logic PCSrc                // PC source (branch or sequential increment)
);

    // Extract opcode, funct3, and funct7 fields from the instruction
    logic [6:0] opcode;
    logic [2:0] funct3;
    logic [6:0] funct7;

    assign opcode = instr[6:0];
    assign funct3 = instr[14:12];
    assign funct7 = instr[31:25];

    // Default control signal values
    always_comb begin
        // Default values for control signals
        RegWrite = 0;
        ALUCtl   = 4'b0000;
        ALUSrc   = 0;
        ImmSrc   = 2'b00;
        PCSrc    = 0;

        // Decode based on opcode
        case (opcode)
            7'b0110011: begin // R-type (e.g., ADD, SUB, AND, OR)
                RegWrite = 1;
                ALUSrc = 0;
                PCSrc = 0;
                case (funct3)
                    3'b000: ALUCtl = (funct7 == 7'b0100000) ? 4'b0001 : 4'b0000; // SUB (0001) or ADD (0000)
                    3'b111: ALUCtl = 4'b0010; // AND
                    3'b110: ALUCtl = 4'b0011; // OR
                    3'b100: ALUCtl = 4'b0100; // XOR
                    default: ALUCtl = 4'b0000;
                endcase
            end
            
            7'b0010011: begin // I-type (e.g., ADDI)
                RegWrite = 1;
                ALUSrc = 1;
                PCSrc = 0;
                ImmSrc = 2'b00; // Use I-type immediate format
                case (funct3)
                    3'b000: ALUCtl = 4'b0000; // ADDI
                    3'b111: ALUCtl = 4'b0010; // ANDI
                    3'b110: ALUCtl = 4'b0011; // ORI
                    3'b100: ALUCtl = 4'b0100; // XORI
                    default: ALUCtl = 4'b0000;
                endcase
            end
            
            7'b0000011: begin // Load (e.g., LW)
                RegWrite = 1;
                ALUSrc = 1;
                PCSrc = 0;
                ImmSrc = 2'b00; // Use I-type immediate format
                ALUCtl = 4'b0000; // ADD for address calculation
            end
            
            7'b0100011: begin // S-type (e.g., SW)
                RegWrite = 0;
                ALUSrc = 1;
                PCSrc = 0;
                ImmSrc = 2'b01; // Use S-type immediate format
                ALUCtl = 4'b0000; // ADD for address calculation
            end
            
            7'b1100011: begin // B-type (e.g., BEQ)
                RegWrite = 0;
                ALUSrc = 0;
                ImmSrc = 2'b10; // Use B-type immediate format
                case (funct3)
                    3'b000: begin
                        ALUCtl = 4'b0001; // SUB for BEQ
                        PCSrc = (funct3 == 3'b000); // Only branch if BEQ is true
                    end
                    3'b001: begin
                        ALUCtl = 4'b0001; // SUB for BNE
                        PCSrc = (funct3 == 3'b001); // Only branch if BNE is true
                    end
                    default: PCSrc = 0;
                endcase
            end
            
            7'b1101111: begin // J-type (e.g., JAL)
                RegWrite = 1;
                ALUSrc = 1;
                ImmSrc = 2'b11; // Use J-type immediate format
                PCSrc = 1;      // Jump
            end
            
            default: begin // Default case for unsupported instructions
                RegWrite = 0;
                ALUCtl = 4'b0000;
                ALUSrc = 0;
                PCSrc = 0;
            end
        endcase
    end
endmodule
