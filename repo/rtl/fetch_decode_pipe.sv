module fetch_decode_pipe #(
    parameter DATA_WIDTH = 16
) (
    input logic stallD,   //From Hazard Unit  acts as eable to FF
    input logic flushD,   //From Hazard Unit  acts as rst to FF
    input logic [DATA_WIDTH-1:0]  PCounterF,   // Before i_mem 
    input logic [DATA_WIDTH-1:0]  instr,       // output from i_mem
    input logic [DATA_WIDTH-1:0]  PCPlus4F,    // after +4

    output logic [DATA_WIDTH-1:0] InstrD,      // after FF
    output logic [DATA_WIDTH-1:0] PCounterD,   // after FF
    output logic [DATA_WIDTH-1:0] PCPlus4D    //after FF 
    // D -> after pipe, F -> before pipe 
);

    always_ff @(posedge clk) begin

        if (FlushD)
            InstrD <= 0 ;
        
        //Pass data through pipeline 
        else if (!stallD) begin
            InstrD <= instr;
            PCounterD <= PCounterF;
            PCPlus4D <= PCPlus4F;      
        end

    end
  
endmodule