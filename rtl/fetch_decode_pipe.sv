module fetch_decode_pipe #(
    parameter DATA_WIDTH = 32
) (
    input                         clk,
 
    input logic                   StallD,   //From Hazard Unit  acts as eable to FF
    input logic                   FlushD,   //From Hazard Unit  acts as rst to FF
 
    input logic [DATA_WIDTH-1:0]  pcF,   // Before i_mem
    input logic [DATA_WIDTH-1:0]  instr,       // output from i_mem
    input logic [DATA_WIDTH-1:0]  PCPlus4F,    // after +4
    input logic                   branch_predictF,

    output logic [DATA_WIDTH-1:0] instrD,      // after FF
    output logic [DATA_WIDTH-1:0] pcD,   // after FF
    output logic [DATA_WIDTH-1:0] PCPlus4D,    //after FF4
    output logic                  branch_predictD
    // D -> after pipe, F -> before pipe
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
