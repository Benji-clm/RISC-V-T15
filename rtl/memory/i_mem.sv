module i_mem #(
    DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]   pc,
    output  logic [DATA_WIDTH-1:0]      instr    
);
 
logic [7:0] array [32'hBFC00FFF:32'hBFC00000];
 
initial begin
        $display("Loading program into instruction memory...");
        $readmemh("../tb/program.hex", array);
end
 
assign instr = {array[pc+3], array[pc+2], array[pc+1], array[pc]};
 
endmodule
