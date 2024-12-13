module i_mem_top #(
    parameter   DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]   pc,
	 input   logic 						 Flush,
    input   logic                    clk,
    output  logic [DATA_WIDTH-1:0]   instr    
);

logic [DATA_WIDTH-1:0] q;
logic [11:0] address;

assign address = pc[13:2];

i_mem (
    .address(address),
    .clock(clk),
    .q(q)
);

// NOP (0x13) if flush occurs
assign instr = Flush ? 32'h00000013 : q;

endmodule
