`include "definitions.sv"
 
module counter_module #(
    parameter DATA_WIDTH = 32
)(
    // Interface signals
    input logic [2:0] PCsrcE,                        // Select signal for MUX
    input logic [DATA_WIDTH-1:0]  PCTargetE,    // Branch target address (PC + ImmExt)
    input logic [DATA_WIDTH-1:0]  PCPlus4F,     // Incremented PC (PC + 4)
    input logic [DATA_WIDTH-1:0]  ALUResult,
    input logic                   eq,
    input logic                   branch_predictE,
    output logic [DATA_WIDTH-1:0] pc,    // Program Counter after clk
    output logic                  Hazard_PCsrc
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

        if(branch_predictE == Hazard_PCsrc && PCsrcE[1] == 1) begin 
            pc = PCPlus4F;
        end
end
 
 
endmodule
