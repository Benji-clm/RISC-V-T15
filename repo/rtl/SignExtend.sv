`include "definitions.sv"

module SignExtend #(
    parameter DATA_WIDTH = 32
)(
    /* verilator lint_off UNUSED */
    input logic [31:0] instr,
    /* verilator lint_off UNUSED */          
    input logic [1:0] ImmSrc,           
    output logic [31:0] ImmOp
);

    always_comb begin
        case (ImmSrc)
            `I_TYPE: ImmOp = {{DATA_WIDTH-12{instr[31]}}, instr[31:20]}; // I-type immediate
            `S_TYPE: ImmOp = {{DATA_WIDTH-12{instr[31]}}, instr[31:25], instr[11:7]}; // S-type immediate
            `B_TYPE: ImmOp = {{DATA_WIDTH-12{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0}; // B-type immediate
            `U_TYPE: ImmOp = {instr[31:12], {DATA_WIDTH-20{1'b0}}}; // U-type immediate
            `J_TYPE: ImmOp = {{DATA_WIDTH-21{instr[31]}}, instr[31], instr[19:12], instr[20], instr[30:21], 1'b0};
            `NE_TYPE: ImmOp = {DATA_WIDTH{1'b0}}; // No extension for shifts (NE_TYPE)
            default:begin
                ImmOp = 0;
            end 
        endcase
    end

endmodule
