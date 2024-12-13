module pipeline_FI #(
    parameter DATA_WIDTH = 32
) (
    input  logic                    clk,
    input  logic                    Flush,
    input  logic                    Stall,

    input  logic [DATA_WIDTH-1:0]   instr,
    input  logic [DATA_WIDTH-1:0]   pcF,
    input  logic [DATA_WIDTH-1:0]   PCPlus4F,

    output logic [DATA_WIDTH-1:0]   instrI,
    output logic [DATA_WIDTH-1:0]   pcI,
    output logic [DATA_WIDTH-1:0]   PCPlus4I
);

always_ff @ (posedge clk) begin 
    if (Flush) begin
        instrI   <= 32'h00000013;
        pcI      <= '0;
        PCPlus4I <= '0;
    end
    else if(!Stall) begin 
        instrI   <= instr;
        pcI      <= pcF;
        PCPlus4I <= PCPlus4F;
    end


end

endmodule
