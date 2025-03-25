module fetch_decode_pipe #(
    parameter DATA_WIDTH = 32
) (
    input                         clk,
 
    input logic                   StallD,
    input logic                   FlushD,
 
    input logic [DATA_WIDTH-1:0]  pcF,
    input logic [DATA_WIDTH-1:0]  instr,
    input logic [DATA_WIDTH-1:0]  PCPlus4F,
    input logic                   branch_predictF,

    output logic [DATA_WIDTH-1:0] instrD,
    output logic [DATA_WIDTH-1:0] pcD,
    output logic [DATA_WIDTH-1:0] PCPlus4D,
    output logic                  branch_predictD
);
 
    always_ff @(posedge clk) begin
 
        //Pass data through pipeline
        if (!StallD) begin
            instrD <= instr;
            pcD <= pcF;
            PCPlus4D <= PCPlus4F;
            branch_predictD <= branch_predictF;  
        end
 
        if (FlushD) begin
            instrD <= 32'h00000013;
            branch_predictD <= 1'b0;
        end
 
    end
  
endmodule
