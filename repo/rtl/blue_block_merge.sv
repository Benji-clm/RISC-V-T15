//merge two sv files here
//(this_file) .module_logic
module blue_block_merge#(
    parameter DATA_WIDTH = 16
)(
    
    // Interface signals
    input  logic             clk,      // clock 
    input  logic             rst,      // reset
    input logic [DATA_WIDTH-1:0] next_PC,
    input logic [DATA_WIDTH-1:0] ImmOp,
    output logic [DATA_WIDTH-1:0] p_count

    input   logic [DATA_WIDTH-1:0]  in0,
    input   logic [DATA_WIDTH-1:0]  in1,
    input   logic                   sel,
    output  logic [DATA_WIDTH-1:0]  out
);

    
    // Counter for the main address (addr1)
    counter counter(
        .clk (clk),
        .rst (rst),
        .next_PC(out),
        .p_count(p_count)   
    );


// .that file (here)
    assign in0 <= {DATA_WIDTH-3{1'b0},3'b100},
    assign in1 <= p_count + ImmOp;

    mux mux(
        .in0(in0),
        .in1(in1),
        .sel(sel),
        .out(out)        
    );

endmodule
