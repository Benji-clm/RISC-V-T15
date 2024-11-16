module i_mem #(
    DATA_WIDTH = 32,
    ADDRESS_WIDTH = 16
) (
    input   logic [ADDRESS_WIDTH-1:0]   pc,
    output  logic [DATA_WIDTH-1:0]      instr    
);

logic [7:0] array [0:2**ADDRESS_WIDTH-1]; // Byte-addressable memory

initial begin
		$display("Loading program into instruction memory...");
		$readmemh("../rtl/program.hex", array);
end

assign instr = {array[pc+3], array[pc+2], array[pc+1], array[pc]};

endmodule
