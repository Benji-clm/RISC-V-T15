module regf #(
    DATA_WIDTH = 32
)(
    input logic                    clk,
    input logic [4:0]       a1, a2, a3,
    input logic                    we3,
    input logic  [DATA_WIDTH-1:0]  wd3,
    input                          t0,
    output logic [DATA_WIDTH-1:0]  rd1,
    output logic [DATA_WIDTH-1:0]  rd2,
    output logic [DATA_WIDTH-1:0]  a0
);
 
logic [DATA_WIDTH-1:0] rf [DATA_WIDTH-1:0];
 
assign a0 = rf[10];
 
always_ff @ (negedge clk) begin
    if(we3 & a3 != 5'b0) rf[a3] <= wd3;
    if(t0 == 1'b1) rf[5] <= 1;
end
 
always_comb begin
    rd1 = rf[a1];
    rd2 = rf[a2];
end
 
endmodule
 
 
