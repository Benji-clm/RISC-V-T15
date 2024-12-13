// Hexadecimal display for 7-segment
module display (
    input [31:0] i_data,      // Input data (binary)
    output [7:0] o_display0,  // Hex digit 0 (LSB)
    output [7:0] o_display1,  // Hex digit 1
    output [7:0] o_display2,  // Hex digit 2
    output [7:0] o_display3,  // Hex digit 3
    output [7:0] o_display4,  // Hex digit 4
    output [7:0] o_display5   // Hex digit 5 (MSB)
);

// Extract each nibble from the 32-bit input for hexadecimal digits
wire [3:0] nibble0 = i_data[3:0];
wire [3:0] nibble1 = i_data[7:4];
wire [3:0] nibble2 = i_data[11:8];
wire [3:0] nibble3 = i_data[15:12];
wire [3:0] nibble4 = i_data[19:16];
wire [3:0] nibble5 = i_data[23:20];

// Map each nibble to its 7-segment hexadecimal representation
decoder_hex d0 (.i_bin(nibble0), .o_dec(o_display0));
decoder_hex d1 (.i_bin(nibble1), .o_dec(o_display1));
decoder_hex d2 (.i_bin(nibble2), .o_dec(o_display2));
decoder_hex d3 (.i_bin(nibble3), .o_dec(o_display3));
decoder_hex d4 (.i_bin(nibble4), .o_dec(o_display4));
decoder_hex d5 (.i_bin(nibble5), .o_dec(o_display5));

endmodule

// Decoder for 4-bit input to 7-segment hexadecimal display
module decoder_hex (
    input  [3:0] i_bin,
    output [7:0] o_dec
);

reg [7:0] r_dec;

always @(i_bin) begin
    case (i_bin)
        4'h0: r_dec = 8'b1100_0000; // 0
        4'h1: r_dec = 8'b1111_1001; // 1
        4'h2: r_dec = 8'b1010_0100; // 2
        4'h3: r_dec = 8'b1011_0000; // 3
        4'h4: r_dec = 8'b1001_1001; // 4
        4'h5: r_dec = 8'b1001_0010; // 5
        4'h6: r_dec = 8'b1000_0010; // 6
        4'h7: r_dec = 8'b1111_1000; // 7
        4'h8: r_dec = 8'b1000_0000; // 8
        4'h9: r_dec = 8'b1001_0000; // 9
        4'hA: r_dec = 8'b1000_1000; // A
        4'hB: r_dec = 8'b1000_0011; // B
        4'hC: r_dec = 8'b1100_0110; // C
        4'hD: r_dec = 8'b1010_0001; // D
        4'hE: r_dec = 8'b1000_0110; // E
        4'hF: r_dec = 8'b1000_1110; // F
        default: r_dec = 8'b1111_1111; // Blank
    endcase
end

assign o_dec = r_dec;

endmodule
