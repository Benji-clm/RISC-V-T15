`include "definitions.sv"

module pc_selector #(
    parameter ADDRESS_WIDTH = 32
)(
    input  logic [2:0]                  PCsrcE,
    input  logic [ADDRESS_WIDTH-1:0]    PCPlus4F,
    input  logic [ADDRESS_WIDTH-1:0]    PCTargetE,
    input  logic [ADDRESS_WIDTH-1:0]    ALUResult,
    input  logic                        eq,
    output logic                        Hazard_PCsrc,
    output logic [ADDRESS_WIDTH-1:0]    pc
);

always_comb begin 
    case(PCsrcE)
        `NEXT_PC: begin
            pc = PCPlus4F;
            Hazard_PCsrc = 0;
        end

        `EQ_TRUE: begin 
            if(eq) begin 
                pc = PCTargetE;
                Hazard_PCsrc = 1;
            end
            else begin 
                pc = PCPlus4F;
                Hazard_PCsrc = 0;
            end
        end

        `EQ_FALSE: begin 
            if(!eq) begin 
                pc = PCTargetE;
                Hazard_PCsrc = 1;
            end
            else begin 
                pc = PCPlus4F;
                Hazard_PCsrc = 0;
            end
        end

        `UC_JUMP: begin 
            pc = PCTargetE;
            Hazard_PCsrc = 1;
        end

        `JALR: begin 
            pc = ALUResult;
            Hazard_PCsrc = 1;
        end
        default: begin 
            pc = 0;
            Hazard_PCsrc = 0;
            $display("Unrecognized PCsrcE");
        end
    endcase 
end

endmodule
