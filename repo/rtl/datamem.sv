module DataMemory #(
    parameter addr_width = 32,
    parameter data_width = 32,
    parameter memory_depth = 10
)(
    input logic clk,
    input logic we, // write enable
    input logic [addr_width-1:0] A, // address input
    input logic [data_width-1:0] wd, // write data
    output logic [data_width-1:0] rd, // read data
);

logic [DATA_WIDTH-1:0] mem [0:MEM_DEPTH-1];

assign rd = mem [A];

always_ff@(negedge clk) begin
    if (we)
        mem[A] <= wd;
end 

endmodule
