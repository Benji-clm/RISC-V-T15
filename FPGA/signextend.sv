`include "definitions.sv"

module signextend #(
    parameter DATA_WIDTH = 32
)
(
    input logic [31:7] instr,           
    input logic [2:0] ImmSrc,           
    output logic [31:0] ImmOp
);

    always_comb begin
        case (ImmSrc)
            `I_TYPE: ImmOp = {{DATA_WIDTH-12{instr[31]}}, instr[31:20]};
            `S_TYPE: ImmOp = {{DATA_WIDTH-12{instr[31]}}, instr[31:25], instr[11:7]};
            `B_TYPE: ImmOp = {{DATA_WIDTH-12{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};
            `U_TYPE: ImmOp = {instr[31:12], {12{1'b0}}};
            `J_TYPE: ImmOp = {{DATA_WIDTH-20{instr[31]}}, instr[19:12], instr[20], instr[30:25], instr[24:21], 1'b0};
            `NE_TYPE: ImmOp = {{DATA_WIDTH-5{1'b0}}, instr[24:20]};
            default: ImmOp = 32'b0; // Default case for unsupported formats
        endcase
    end

endmodule
