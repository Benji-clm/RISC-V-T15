module dmem_top #(
        parameter   DATA_WIDTH = 32
)(
        input  logic                    clk,
        input  logic [2:0]              LS_mode, // for byte addressing
        input  logic [DATA_WIDTH-1:0]   a, // address
        input  logic [DATA_WIDTH-1:0]   wd, // write data
        input  logic                    we, // write enable (memwrite from control_unit)
        output logic [DATA_WIDTH-1:0]   rd // read data
);

    logic [15:0]                address;
    logic [3:0]                 byteena;
    logic [DATA_WIDTH-1:0]      q;

    assign address = a[16:2];
    
    always_comb begin // determining byteena
        case(LS_mode)
                `W_MODE: byteena = 4'b1111;

                `H_MODE, `UH_MODE: begin 
                        case(a[1:0])
                                2'b00: byteena = 4'b0011;
                                2'b10: byteena = 4'b1100;
                                default: begin
                                        byteena = 4'b0000;
                                end
                        endcase
                end

                `B_MODE, `UB_MODE: begin
                        case(a[1:0])
                                2'b00: byteena = 4'b0001; // byte 0
                                2'b01: byteena = 4'b0010; // byte 1
                                2'b10: byteena = 4'b0100; // byte 2
                                2'b11: byteena = 4'b1000; // byte 3
                        endcase
                end
                default: byteena = 4'b0000;
        endcase
    end

    dmem(
        .address(address),
        .byteena(byteena),
        .clock(~clk),
        .data(wd),
        .wren(we),
        .q(q)
    );

    always_comb begin 
        case(LS_mode) 
                `B_MODE: begin
                        case(a[1:0]) 
                                2'b00: rd = {{24{q[7]}}, q[7:0]};
                                2'b01: rd = {{24{q[15]}}, q[15:8]};
                                2'b10: rd = {{24{q[23]}}, q[23:16]};
                                2'b11: rd = {{24{q[31]}}, q[31:24]};
                        endcase
                end
                `H_MODE: begin
                        case(a[1:0])
                                2'b00: rd = {{16{q[15]}}, q[15:0]};
                                2'b10: rd = {{16{q[31]}}, q[31:16]};
                                default: rd = '0;
                        endcase
                end
                `UB_MODE: begin 
                        case(a[1:0]) 
                                2'b00: rd = {24'b0, q[7:0]};
                                2'b01: rd = {24'b0, q[15:8]};
                                2'b10: rd = {24'b0, q[23:16]};
                                2'b11: rd = {24'b0, q[31:24]};
                        endcase
                end
                `UH_MODE: begin 
                        case(a[1:0])
                                2'b00: rd = {16'b0, q[15:0]};
                                2'b10: rd = {16'b0, q[31:16]};
                                default: rd = '0;
                        endcase
                end
                `W_MODE: rd = q;
                default: rd = '0;
        endcase
    end

endmodule
