`include "definitions.sv"

module control_unit (
    // inputs
    input  logic [6:0]            op,
    input  logic                  stall,
    input  logic [2:0]            funct3,
    input  logic [6:0]            funct7,

    // outputs
    output logic [2:0]            PCsrc,
    output logic [1:0]            ResultSrc,
    output logic                  MemWrite,
    output logic [3:0]            ALUControl,
    output logic                  ALUsrc,
    output logic [2:0]            ImmSrc,
    output logic                  RegWrite, 
    output logic [2:0]            LS_mode,
    output logic                  MemRead              
);

    

always_comb begin

    // start with the default values
    PCsrc = `NEXT_PC;
    ResultSrc = 2'b00;
    MemWrite = 0;
    ALUControl = `ALUop_ADD;
    ALUsrc = 1'b0;
    ImmSrc = `I_TYPE; // (3'b000)
    RegWrite = 0;
    LS_mode = 3'b000;
    MemRead  = 0;

    case(op)

        // R-Type inst
        7'b0110011: begin
            ALUsrc = 0;
            RegWrite = 1;
            

            case(funct3)

                3'b000: begin
                    case(funct7)
                        
                        7'h00: begin
                            ALUControl = `ALUop_ADD;
                        end
                        
                        7'h20: begin
                            ALUControl = `ALUop_SUB;
                        end

                        default: $display("Warning: Undefined R-Type instruction");
                    endcase
                end

                3'b001: begin
                    ALUControl = `ALUop_LSL;
                end

                3'b010: begin 
                    ALUControl = `ALUop_SLT;
                end

                3'b011: begin 
                    ALUControl = `ALUop_SLTU;
                end

                3'b100: begin 
                    ALUControl = `ALUop_XOR;
                end

                3'b101: begin
                    case(funct7)
                        7'h00: begin
                            ALUControl = `ALUop_LSR;
                        end

                        7'h20: begin
                            ALUControl = `ALUop_ASR;
                        end
                        default: $display("Warning: Undefined R-Type right shift instruction");
                    endcase
                end

                3'b110: begin 
                    ALUControl = `ALUop_OR;
                end

                3'b111: begin 
                    ALUControl = `ALUop_AND;
                end

                default: $display("Warning: Unrecognized R-type instruction");
            endcase
        end

        // I-type inst
        7'b0010011: begin
            ImmSrc = `I_TYPE;
            RegWrite = 1;
            ALUsrc = 1;
            case(funct3)

                3'b000: begin
                    ALUControl = `ALUop_ADD;
                end

                3'b001: begin
                    ImmSrc = `NE_TYPE;
                    ALUControl = `ALUop_LSL;
                end

                3'b010: begin 
                    ALUControl = `ALUop_SLT;
                end

                3'b011: begin 
                    ALUControl = `ALUop_SLTU;
                end

                3'b100: begin 
                    ALUControl = `ALUop_XOR;
                end

                3'b101: begin
                    ImmSrc = `NE_TYPE;
                    case(funct7)
                        7'h00: begin
                            ALUControl = `ALUop_LSR;
                        end

                        7'h20: begin
                            ALUControl = `ALUop_ASR;
                        end

                        default: $display("Warning: Unrecognized Right-Shift type");
                    endcase
                end

                3'b110: begin 
                    ALUControl = `ALUop_OR;
                end

                3'b111: begin 
                    ALUControl = `ALUop_AND;
                end
                
                default: $display("Warning: Unrecognized I-type instruction");
            endcase
        end
    
    // Load I-type
    // For Load and Store instructions, we need to specify the type (k.e. half, word etc).
    // Default is full word
        7'b000011: begin
            ALUControl = `ALUop_ADD;
            ImmSrc = `I_TYPE;
            ALUsrc = 1;
            ResultSrc = 1;
            RegWrite = 1;
            MemWrite = 0;
            MemRead  = 1;
            case(funct3)
                // lb
                3'b000: begin 
                    LS_mode = `B_MODE;
                end

                3'b001: begin 
                    LS_mode = `H_MODE;
                end

                // lw
                3'b010: begin 
                    LS_mode = `W_MODE;
                end

                // lbu
                3'b100: begin 
                    LS_mode = `UB_MODE;
                end

                3'b101: begin 
                    LS_mode = `UH_MODE;
                end

                default: $display("Warning: Unrecognized Load I-type instruction");
            endcase
        end

        // S-type
        7'b0100011: begin 
            ALUControl = `ALUop_ADD;
            ImmSrc = `S_TYPE;
            ALUsrc = 1;
            RegWrite = 0;
            MemWrite = 1;
            MemRead  = 0;

            case(funct3) 
                3'b000: begin 
                    LS_mode = `B_MODE;
                end

                3'b001: begin 
                    LS_mode = `H_MODE;
                end

                3'b010: begin 
                    LS_mode = `W_MODE;
                end

                default: $display("Warning: Unrecognized S-type instruction");
            endcase
        end

        // B-type
        7'b1100011: begin
            ImmSrc = `B_TYPE;
            ALUsrc = 0;
            RegWrite = 0;

            case(funct3) 
                // beq
                3'b000: begin 
                    ALUControl = `ALUop_SUB;
                    PCsrc = `EQ_TRUE;
                end

                // bne
                3'b001: begin 
                    ALUControl = `ALUop_SUB;
                    PCsrc = `EQ_FALSE;
                end

                // blt
                3'b100: begin 
                    ALUControl = `ALUop_SLT;
                    PCsrc = `EQ_FALSE;
                end

                // bge
                3'b101: begin 
                    ALUControl = `ALUop_SLT;
                    PCsrc = `EQ_TRUE;
                end

                // bltu
                3'b110: begin 
                    ALUControl = `ALUop_SLTU;
                    PCsrc = `EQ_FALSE;
                end

                // bgeu
                3'b111: begin 
                    ALUControl = `ALUop_SLTU;
                    PCsrc = `EQ_TRUE;
                end

                default: $display("Warning: Unrecognized B-type instruction");
            endcase
        end

        // J-type
        // uses ResultSrc = 2 as it stores PC + 4 into rd
        7'b1101111: begin 
            ImmSrc = `J_TYPE;
            PCsrc = `UC_JUMP;
            ALUsrc = 1;
            RegWrite = 1;
            ResultSrc = 2;
        end

        // JALR
        7'b1100111: begin 
            ImmSrc = `I_TYPE;
            ALUControl = `ALUop_ADD;
            PCsrc = `JALR;
            ALUsrc = 1; 
            RegWrite = 1;
            ResultSrc = 2;
        end

        // U-type

        // LUI
        7'b0110111: begin 
            ImmSrc = `U_TYPE;
            ALUControl = `ALUop_B;
            RegWrite = 1;
            ALUsrc = 1;
        end

        // AUIPC
        7'b0010111: begin 
            ImmSrc  = `U_TYPE;
            RegWrite = 1;
            ALUsrc = 1;
        end

        // // Environment
        // 7'b1110011: begin 
        //     ImmSrc = `I_TYPE;

        //     case(instr[7])

        //         1'b0: begin 
        //             // TODO
        //         end

        //         1'b1: begin 
        //             // TODO
        //         end
        //     endcase
        // end

        // We can ignore Environment calls (for the moment...)


        default: begin
            // $display("Warning: Undefined instruction");
            PCsrc = `NEXT_PC;
            ResultSrc = 2'b00;
            MemWrite = 0;
            ALUControl = `ALUop_ADD;
            ALUsrc = 0;
            ImmSrc = `I_TYPE;
            RegWrite = 0;
            LS_mode = 3'b000;
        end
    endcase

    if (stall) begin
        MemWrite = 0;
        RegWrite = 0;
    end

end

endmodule
