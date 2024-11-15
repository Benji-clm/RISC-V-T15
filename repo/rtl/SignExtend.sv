module SignExtend (
    input logic [31:0] ImmOp,           
    input logic [1:0] ImmSrc,           
    output logic [31:0] imm_ext
);

    always_comb begin
        case (ImmSrc)
            2'b00: imm_ext = {{20{ImmOp[31]}}, ImmOp[31:20]};              // I-type (12-bit signed immediate)
            2'b01: imm_ext = {{20{ImmOp[31]}}, ImmOp[31:25], ImmOp[11:7]};   // S-type (split 12-bit signed immediate)
            2'b10: imm_ext = {{19{ImmOp[31]}}, ImmOp[31], ImmOp[0], ImmOp[30:25], ImmOp[4:1], 1'b0}; // B-type (branch offset)
            default: imm_ext = 32'b0;                                       // Default case for unsupported formats
        endcase
    end

endmodule
