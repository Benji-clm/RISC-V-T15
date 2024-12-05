module datamem #(
    parameter addr_width = 32,
              data_width = 32,
              memory_size = 8
)(
    input logic clk,
    input logic we,
    input logic [2:0] LS_mode,
    input logic [addr_width-1:0] a,
    input logic [data_width-1:0] wd,
    output logic [data_width-1:0] rd
);
 
    logic [memory_size-1:0] array [2**17-1:0];
 
    initial begin
        $display("Loading data into data memory...");
        $readmemh("../tb/data.hex", array, 17'h10000, 17'h1FFFF);
    end
 
// Read logic with extension
    always_ff @* begin
        rd = {
            array[{a[16:2], 2'b11}],
            array[{a[16:2], 2'b10}],
            array[{a[16:2], 2'b01}],    
            array[{a[16:2], 2'b00}]
        };
    end
 
        // Read and write operations
    always_ff @(posedge clk) begin
        if (we && LS_mode == 3'b01x) begin // Write only least significant byte (8 bits)
            array[a] <= wd[7:0];
        end
 
        else if (we) begin // Write whole word
            array[{a[16:2], 2'b00}] <= wd[7:0];
            array[{a[16:2], 2'b01}] <= wd[15:8];
            array[{a[16:2], 2'b10}] <= wd[23:16];
            array[{a[16:2], 2'b11}] <= wd[31:24];
        end
    end
 
endmodule
