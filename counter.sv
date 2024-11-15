module counter #(

    parameter DATA_WIDTH = 16
)(
    //interface signal
    input logic         clk,   //clock
    input logic         rst,   //reset
    input logic [DTA_WIDTH-1:0] next_PC,  //increment 16 bit number
    //input logic         en,    //counter enable, we dont need enable for Lab4
    output logic [DATA_WIDTH-1:0] p_count//count output 
);


always_ff @ (posedge clk)
    if(rst) p_count <= {DATA_WIDTH{1'b0}};//if reset is 1 count is declerated to 0 with WIDTH bits

    else   p_count <= p_count + next_PC ;  // increment by 4 every time

endmodule




