module SignExtend (
    /* verilator lint_off UNUSEDSIGNAL */
    input logic [31:0] instr,
    /* verilator lint_on UNUSEDSIGNAL */           
    input logic [1:0] ImmSrc,           
    output logic [31:0] ImmOp
);

    always_comb begin
        case (ImmSrc)
            2'b00: ImmOp = {{20{instr[31]}}, instr[31:20]};              // I-type (12-bit signed immediate)
            2'b01: ImmOp = {{20{instr[31]}}, instr[31:25], instr[11:7]};   // S-type (split 12-bit signed immediate)
            2'b10: ImmOp = {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0}; // B-type (branch offset)
            default: ImmOp = 32'b0;                                       // Default case for unsupported formats
        endcase
    end

endmodule
