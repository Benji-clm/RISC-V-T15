module pipeline_FD #(
    parameter DATA_WIDTH = 32
)(
    input  logic                    clk,
    
    // inputs
    input  logic [DATA_WIDTH-1:0]   instr,
    input  logic [DATA_WIDTH-1:0]   pcF,
    input  logic [DATA_WIDTH-1:0]   PCPlus4F,

    // controls
    input  logic                    StallD,
    input  logic                    FlushD,

    // outputs
    output logic [DATA_WIDTH-1:0]   instrD,
    output logic [DATA_WIDTH-1:0]   pcD,
    output logic [DATA_WIDTH-1:0]   PCPlus4D
);

always_ff @ (posedge clk) begin

    if (!StallD) begin
        instrD <= instr;
        pcD <= pcF;
        PCPlus4D <= PCPlus4F;        
    end

    if(FlushD) begin 
        instrD <= 32'h00000013;
    end
    
end
 
endmodule
