module fetch_decode_pipe #(
    parameter DATA_WIDTH = 32
) (
    input                         clk,
 
    input logic                   StallD,   //From Hazard Unit  acts as eable to FF
    input logic                   FlushD,   //From Hazard Unit  acts as rst to FF
 
    input logic [DATA_WIDTH-1:0]  pcF,   // Before i_mem
    input logic [DATA_WIDTH-1:0]  instr,       // output from i_mem
    input logic [DATA_WIDTH-1:0]  PCPlus4F,    // after +4
 
    output logic [DATA_WIDTH-1:0] instrD,      // after FF
    output logic [DATA_WIDTH-1:0] pcD,   // after FF
    output logic [DATA_WIDTH-1:0] PCPlus4D    //after FF
    // D -> after pipe, F -> before pipe
);
 
    always_ff @(posedge clk) begin
 
        //Pass data through pipeline
        if (!StallD) begin
            instrD <= instr;
            pcD <= pcF;
            PCPlus4D <= PCPlus4F;      
        end
 
        if (FlushD)
            instrD <= 32'h00000013;
    
 
    end
  
endmodule