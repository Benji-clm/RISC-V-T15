
> **Note:** not all files from the FPGA work were uploaded, only the ones necessary for users to compile and run the tests themselves on **Quartus**.
### Video Evidence


### Objective

I decided to take the route of the FPGA, as, although simulation can be a great tool, it is **unaffected by real-world** constraints and exists under a perfect environment, being simulated cycle-by-cycle. The FPGA allowed us to refined our design, and ensure it wasn't only theoretically sound, but also **functional in a physical hardware environment**.

For simplicity, I decided to only synthesise the **pipelined version** of the CPU (without added cache, branch prediction etc.). However, the hardware still had to modified, mainly fixing **timing issues**, and making all the code synthesisable, as the instruction-memory is now **clocked** and a lot of the code which might makes makes sense in simulation, could be **wrong in actual hardware**.

I chose to use the *DE10-Lite* as our FPGA, as it will be the FPGA used next-term for the Information-processing module.

### Hardware Modification

I first had to change from simply using **arrays** for the memories, to using the **MAX10** architecture memories, provided within Quartus for the **DE10-Lite**.

For the **instruction memory**, I created a **ROM**, which I then connected to a top module, note how I discard the least significant 2-bits, as the memories are now **word aligned**, and I need to ensure that I are always aligned.

```systemverilog
module i_mem_top #(
    parameter   DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]   pc,
	input   logic 				     Flush,
    input   logic                    clk,
    output  logic [DATA_WIDTH-1:0]   instr    
);

logic [DATA_WIDTH-1:0] q;
logic [11:0] address;

assign address = pc[13:2];

i_mem (
    .address(address),
    .clock(~clk),
    .q(q)
);

// NOP (0x13) if flush occurs
assign instr = Flush ? 32'h00000013 : q;

endmodule

```

On the actual memory itself, I are not using simple `.hex` files anymore, but are using `.mif`, which provide detail about the memory itself, to be properly loaded onto the FPGA:

`altsyncram_component.init_file = "./firmware/program.mif",`

Where `program.mif` is shown below:

```mif
WIDTH=32;
DEPTH=4096;

ADDRESS_RADIX=HEX;
DATA_RADIX=HEX;

CONTENT BEGIN
  000 : FFF00313; -- li t1, -1
  001 : 00000513; -- li a0, 0
  002 : 00000593; -- li a1, 0
  003 : 00058513; -- mv a0, a1
  004 : 00158593; -- addi a1, a1, 1
  005 : FE659CE3; -- bne a1, t1, bfc0000c <iloop>
  006 : 00051263; -- bnez a0, bfc0001c <finish>
  007 : 00051063; -- bnez a0, bfc0001c <finish>
  [008..FFF] : 00000000; -- Fill remaining addresses with zero
END;
```
*(this is a modified counter, where I set $t1$ to $-1$, making it loop infinitely)*

I wrote a code to produce the wanted `.mif` file:

```python
def disassembly_to_mif(input_file, output_file):
    # Initialize the MIF header
    header = (
        "WIDTH=32;\n"
        "DEPTH=4096;\n\n"
        "ADDRESS_RADIX=HEX;\n"
        "DATA_RADIX=HEX;\n\n"
        "CONTENT BEGIN\n"
    )

    # Read the disassembly from the input file
    with open(input_file, 'r') as f:
        lines = f.readlines()

    # Parse the disassembly and extract instructions
    instructions = []
    for line in lines:
        # Look for lines with the disassembly (hexadecimal instruction)
        parts = line.strip().split()
        if len(parts) >= 2 and parts[1].endswith(":"):
            # Instruction line format: address: instruction
            address = parts[0].strip(":")
            instruction = parts[1]
            # Extract the comment if available
            comment = " ".join(parts[2:]) if len(parts) > 2 else ""
            instructions.append((address, instruction, comment))

    # Write to the MIF file
    with open(output_file, 'w') as f:
        f.write(header)

        # Write instructions
        for i, (address, instruction, comment) in enumerate(instructions):
            mif_line = f"  {i:03X} : {instruction};"
            if comment:
                mif_line += f" -- {comment}"
            f.write(mif_line + "\n")

        # Fill remaining addresses with zeros
        f.write("  [008..FFF] : 00000000; -- Fill remaining addresses with zero\n")
        f.write("END;\n")

# I/O file paths
input_file = "program.dis"
output_file = "program.mif"

disassembly_to_mif(input_file, output_file)
```


For the **data memory**, I used a **RAM**, with byte-enabled addressing, `byteena`, which means I also had to change the logic of the `dmem_top.sv`:

```systemverilog
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
        .clock(clk),
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

```
<br>
Finally, due to timing issues, I have to use `~clk`  (@ negedge) within the **clocked memories**, as there was a mismatch of one cycle between the **pc counter** and the **instruction memory**.

### Testing

To be able to test our design I did **two things**:
- Create an equivalent of the FPGA design for Verilator, allowing for easier testing.
- Use the FPGA monitor to output $a0$, or other wires.

For the FPGA, I had to design a module to control the **display**, using HEX values:

```verilog
// Hexadecimal display for 7-segment
module display (
    input [31:0] data,      // Input data (binary)
    output [7:0] display0,  // Hex digit 0 (LSB)
    output [7:0] display1,  // Hex digit 1
    output [7:0] display2,  // Hex digit 2
    output [7:0] display3,  // Hex digit 3
    output [7:0] display4,  // Hex digit 4
    output [7:0] display5   // Hex digit 5 (MSB)
);

// Extract each nibble from the 32-bit input for hexadecimal digits
wire [3:0] nibble0 = data[3:0];
wire [3:0] nibble1 = data[7:4];
wire [3:0] nibble2 = data[11:8];
wire [3:0] nibble3 = data[15:12];
wire [3:0] nibble4 = data[19:16];
wire [3:0] nibble5 = data[23:20];

// Map each nibble to its 7-segment hexadecimal representation
decoder_hex d0 (.i_bin(nibble0), .o_dec(display0));
decoder_hex d1 (.i_bin(nibble1), .o_dec(display1));
decoder_hex d2 (.i_bin(nibble2), .o_dec(display2));
decoder_hex d3 (.i_bin(nibble3), .o_dec(display3));
decoder_hex d4 (.i_bin(nibble4), .o_dec(display4));
decoder_hex d5 (.i_bin(nibble5), .o_dec(display5));

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

```