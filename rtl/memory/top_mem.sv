module top_mem #(
    parameter ADDR_WIDTH = 32,
              DATA_WIDTH = 32
) (
    input logic clk,
    input logic we,
    input logic MemRead,            
    input logic [2:0] LS_mode,              
    input logic [ADDR_WIDTH-1:0] a,    
    input logic [DATA_WIDTH-1:0] wd, 
                    
    output logic [DATA_WIDTH-1:0] rd   
);

logic   [DATA_WIDTH-1:0] rd_cache;
logic [7:0] byte3, byte2, byte1, byte0;

always_comb begin
    byte3 = rd_cache[31:24];
    byte2 = rd_cache[23:16];
    byte1 = rd_cache[15:8];
    byte0 = rd_cache[7:0];

    // Read logic
    case (LS_mode)
        `W_MODE: begin
            rd = rd_cache; 
        end
        `B_MODE: begin
            case (a[1:0])
                2'b00: begin
                    rd = {{24{byte0[7]}}, byte0};
                end
                2'b01: begin
                    rd = {{24{byte1[7]}}, byte1};
                end
                2'b10: begin
                    rd = {{24{byte2[7]}}, byte2};
                end
                2'b11: begin
                    rd = {{24{byte3[7]}}, byte3};
                end
            endcase
        end

        `H_MODE: begin
            case (a[1:0])
                2'b00: begin
                    rd = {{16{byte1[7]}}, byte1, byte0};
                end

                2'b10: begin
                    rd = {{16{byte3[7]}}, byte3, byte2};
                end
                default: begin
                    $error("Misaligned halfword write detected!");
                end
            endcase
        end

        `UB_MODE: begin
            case (a[1:0])
                2'b00: begin
                    rd = {24'b0, byte0};
                end
                2'b01: begin
                    rd = {24'b0, byte1};
                end
                2'b10: begin
                    rd = {24'b0, byte2};
                end
                2'b11: begin
                    rd = {24'b0, byte3};
                end
            endcase
        end

        `UH_MODE: begin
            case (a[1:0])
                2'b00: begin
                    rd = {{16{byte1[0]}}, byte1, byte0};
                end
                2'b10: begin
                    rd = {16'b0, byte3, byte2};
                end
                default: begin
                    $error("WARNING: Misaligned halfword write detected");
                end
            endcase
        end

        default: $display("WARNING: unrecognised LS_mode in cached_memory");
    endcase
end


DataCache data_cache_inst (
    .clk(clk),
    .we(we),                 
    .LS_mode(LS_mode), 
    .MemRead(MemRead),              
    .a(a),                  
    .wd(wd), 
                            
    .rd(rd_cache)            
);

endmodule
