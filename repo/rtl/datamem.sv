module DataMemory #(
    parameter addr_width = 32,
    parameter data_width = 32,
    parameter memory_size = 128
)(
    input logic clk,
    input logic [3:0]we, // write enable
    input logic [2:0] funct3,
    input logic [addr_width-1:0] daddr, // address
    input logic [data_width-1:0] wd_data // mem_write data
    output logic [data_width-1:0] rd_data, // mem_read data
);

reg [data_width-1:0] mem [0:memory_size-1];
wire [31:0] addo0, add1, add2, add3;

initial 
$readmemh("../rtl/program.hex", mem);

assign add0 = (daddr & 32'hfffffffc)+ 32'h00000000;
assign add1 = (daddr & 32'hfffffffc)+ 32'h00000001;
assign add2 = (daddr & 32'hfffffffc)+ 32'h00000002;
assign add3 = (daddr & 32'hfffffffc)+ 32'h00000003;

// Read logic with extension
always_comb begin
    case (funct3)
        3'b010: rd_data = {mem[add3], mem[add2], mem[add1], mem[add0]};   // LW
        3'b001: rd_data = {{16{mem[add1][7]}}, mem[add1], mem[add0]};   // LH (sign-extended)
        3'b000: rd_data = {{24{mem[add0][7]}}, mem[add0]};            // LB (sign-extended)
        3'b101: rd_data = {16'b0, mem[add1], mem[add0]};              // LHU (zero-extended)
        3'b100: rd_data = {24'b0, mem[add0]};                       // LBU (zero-extended)
        default: rd_data = 32'b0;
    endcase
end

always_ff@(negedge clk) begin
    if (we[0]) m[add0] <= dwdata[7:0];
    if (we[1]) m[add1] <= dwdata[15:8];
    if (we[2]) m[add2] <= dwdata[23:16];
    if (we[3]) m[add3] <= dwdata[31:24];
end 

endmodule
