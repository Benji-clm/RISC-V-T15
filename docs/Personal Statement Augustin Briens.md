 # Augustin's Personal Statement

  - Name : Augustin Briens
  - CID: 02375711 

# Overview
## Lab 4
In Lab 4, I focused on:
- [Sign Extension](#sign-extension)
- [Instruction Memory](#instruction-memory)
- [Control Unit](#control-unit)
## Single Cycle CPU
For the Single Cycle, I focused on:
- [Signe Extension for Single Cycle](#single-cycle-extension)
- [Alu (Refractor)](#single-cycle-alu)
## Cache
For the Cache Extension:
- [Direct Mapped Cache](#direct-mapped-data-cache)
- [Two-Way Set Associative Cache](#two-way-set-associative-cache)
- [Instruction Memory Cache](#instruction-memory-cache)
## Other Modifications
- [Top File](#top-file)
- [CPU Tets](#tests)
## Project Takebacks
- [What I learned](#what-i-learned)
- [Mistakes I made](#mistakes-i-made)
- [Special Design Decisions](#special-design-decisions)
- [What I Might Do Differently](#what-i-might-do-differently-and-if-i-had-more-time)


# Sign Extension 
The Sign Extension Module is an important component in the RISC-V 32I CPU design. This module handles the process of extending immediate values from instructions to 32 bits while preserving their signed nature. 
![image](https://github.com/user-attachments/assets/dbb2934b-cb44-490f-9045-5df354b111d6)

## Repository
[LAb 4 Sign Extension Module](https://github.com/Benji-clm/RISC-V-T15/commit/bf3093fa1702d23905d1c9a58ba19c07c0f4820b)
[Single Cycle Sign Extension Module](https://github.com/Benji-clm/RISC-V-T15/commit/76f6622b35fa05d476bb99fff607258e1320da18)

### Lab 4: Simplified CPU Design

Supported Immediate Formats:
- I-Type: Handles 12-bit signed immediate values used in instructions like ADDI and LOAD.
- S-Type: Manages split 12-bit signed immediate values for instructions like STORE.
- B-Type: Supports branch offsets with a 12-bit signed immediate format used in branch instructions like BEQ and BNE.
Input and Output:

Inputs:
- instr (32-bit): The instruction word containing the immediate value
- ImmSrc (2-bit): Specifies the type of immediate value to be processed
Output:
- ImmOp (32-bit): The sign-extended immediate value

### Single Cycle Extension
Expanded Instruction Formats:
- U-Type: Upper immediate (LUI and AUIPC instructions).
- J-Type: Jump immediate (JAL instruction).
- NE_TYPE: No-extension type, used for instructions that handle shift amounts.

The values of ImmOp therefore chose the Instruction type; the different values are defined in the [definitions.sv](https://github.com/Benji-clm/RISC-V-T15/blob/master/repo/rtl/definitions.sv) file.
| ImmOp | Instruction type |
|--------|------------------|
| 000    | Immediate        |
| 001    | Store             |
| 010    | Branch            |
| 011    | Jump              |
| 100    | Upper Immediate   |

# Instruction Memory
The Instruction Memory (I-mem) module stores the machine instructions to be executed by the CPU. It is a vital component that serves as the bridge between the control logic and the stored program.

## Repository
[`i_mem.sv`](https://github.com/Benji-clm/RISC-V-T15/blob/47afb84170ecad81ab356995a1badec80bfc6e0e/repo/rtl/i_mem.sv): Lab 4 Instruction Memory Module
[`i_mem_tb.cpp`](https://github.com/Benji-clm/RISC-V-T15/blob/fedfc920902fe59581c8a9e72b1fbf01aaf273a5/repo/tb/tests/i_mem_tb.cpp): Lab 4 Instruction Memory Testbench

## Lab 4

- The `i_mem` module is designed to fetch 32-bit instructions in a RISC-V compliant format.
- Memory is byte-addressable, and instructions are loaded from a hex file (`program.hex`) during simulation.
- The module supports parameterized data and address widths for scalability.

---

## Design Details

### Parameters
- **`DATA_WIDTH`**: Configured to 32 bits, matching the RISC-V instruction word size.
- **`ADDRESS_WIDTH`**: Set to 16 bits, allowing an addressable memory range of \(2^{16}\) bytes.

### Inputs and Outputs
- **Input: `pc`**
  - Represents the program counter, which specifies the memory address of the instruction to fetch.
  - Configurable to 16 bits using the `ADDRESS_WIDTH` parameter.
  
- **Output: `instr`**
  - A 32-bit instruction fetched from the memory location specified by `pc`.
  - Configurable to 32 bits using the `DATA_WIDTH` parameter.

### Memory Design
- The memory is byte-addressable and implemented as:
  ```verilog
  logic [7:0] array [0:2**ADDRESS_WIDTH-1];
  ```
- Instructions are fetched by combining four consecutive bytes from memory in little-endian order:
  ```verilog
  assign instr = {array[pc+3], array[pc+2], array[pc+1], array[pc]};
  ```

### Memory Initialization
- Memory is initialized at simulation start using `$readmemh`:
  ```verilog
  initial begin
      $display("Loading program into instruction memory...");
      $readmemh("../rtl/program.hex", array);
  end
  ```
- The file `program.hex` contains hexadecimal-encoded instructions.

## Instruction Memory Cache:

The `i_cache` is designed as a 2-way set-associative cache with configurable parameters such as cache size, line size, and associativity. It interfaces with an instruction memory module (`i_mem`) to fetch instructions and refill the cache on misses.

### Key Features
- **Configurable Parameters**: Supports customizable cache size, associativity, and line size.
- **Hit/Miss Detection**: Implements tag comparison for detecting hits and misses.
- **LRU Replacement**: Uses Least Recently Used (LRU) policy for cache replacement.
- **Modular Design**: Encapsulates instruction fetch and cache refill logic.

---

### Design Breakdown

#### Cache Line Structure
Each cache line contains a valid bit, tag, and data storage for multiple instructions.

#####  Cache Line Definition
```verilog
typedef struct packed {
    logic valid;  // Valid bit
    logic [ADDR_WIDTH-$clog2(CACHE_SIZE*LINE_SIZE)-1:0] tag; // Tag
    logic [DATA_WIDTH*LINE_SIZE-1:0] data; // Cache line data
} cache_line_t;
```

#### Cache Set and Memory
Each cache set is composed of multiple associative ways, and the cache memory consists of multiple sets.

##### Cache Memory Definition
```verilog
typedef struct packed {
    cache_line_t [ASSOC-1:0] ways; // Associative ways
    logic [ASSOC-1:0] lru;         // LRU bits
} cache_set_t;

cache_set_t cache_mem [CACHE_SIZE];
```

#### Hit/Miss Detection
Tag comparison is used to determine whether the requested instruction is present in the cache.

#####  Hit Detection Logic
```verilog
always_comb begin
    hit = 0;
    hit_way = 0;
    for (int i = 0; i < ASSOC; i++) begin
        if (cache_mem[index].ways[i].valid && cache_mem[index].ways[i].tag == tag) begin
            hit = 1;
            hit_way[i] = 1;
        end
    end
end
```

#### Instruction Output Logic
If a cache hit occurs, the requested instruction is retrieved directly from the cache. Otherwise, the default value from the memory module is used.

##### Data Output Logic
```verilog
always_comb begin
    instr = mem_instr; // Default value for instr
    if (hit) begin
        for (int i = 0; i < ASSOC; i++) begin
            if (hit_way[i]) begin
                instr = cache_mem[index].ways[i].data[(block_offset*DATA_WIDTH) +: DATA_WIDTH];
            end
        end
    end
end
```

#### Cache Refill and Replacement
On a cache miss, a new cache line is fetched from the memory, and the Least Recently Used (LRU) way is replaced.

#####  Replacement Logic
```verilog
always_ff @(posedge clk) begin
    if (!hit) begin
        logic [$clog2(ASSOC)-1:0] lru_way;
        lru_way = 0;
        for (int i = 1; i < ASSOC; i++) begin
            if (cache_mem[index].lru[i] > cache_mem[index].lru[lru_way]) begin
                lru_way = i[$clog2(ASSOC)-1:0];
            end
        end

        // Replace the LRU way
        cache_mem[index].ways[lru_way].data <= mem_data;
        cache_mem[index].ways[lru_way].tag <= tag;
        cache_mem[index].ways[lru_way].valid <= 1;

        // Update LRU
        for (int i = 0; i < ASSOC; i++) begin
            cache_mem[index].lru[i] <= (i[$clog2(ASSOC)-1:0] == lru_way) ? 0 : cache_mem[index].lru[i] + 1;
        end
    end
end
```

---

This instruction cache enhances instruction fetch performance by reducing memory access latency and leveraging a 2-way associative design.



# Control Unit

The Control Unit takes the instruction (`instr`) and a zero flag (`zero`) as inputs and generates control signals to manage the datapath of the CPU. It determines which operation to perform, which registers to write to, and how the program counter should be updated.

### Key Features
- **Modularity**: Separated into `main_decoder` and `ALU_decoder` for clarity and scalability.
- **RISC-V Compliance**: Designed to handle essential RISC-V instructions like `lw`, `sw`, `R-type`, and `beq`.
- **Parameterized Design**: Supports configurable `DATA_WIDTH`.

## Repository

- [`control_unit.sv`](https://github.com/Benji-clm/RISC-V-T15/blob/9d913fcd27d928bca9e46529e047580c69e7930e/repo/rtl/control_unit.sv): Top-level Control Unit module.
- [`main_decoder.sv`](https://github.com/Benji-clm/RISC-V-T15/blob/9d913fcd27d928bca9e46529e047580c69e7930e/repo/rtl/main_decoder.sv): Main decoder for opcode decoding.
- [`alu_decoder.sv`](https://github.com/Benji-clm/RISC-V-T15/blob/9d913fcd27d928bca9e46529e047580c69e7930e/repo/rtl/ALU_decoder.sv): ALU decoder for generating ALU control signals.
- [`control_unit_tb.cpp`](https://github.com/Benji-clm/RISC-V-T15/blob/6fc02e2185d52ad8efd14be24972a6c3eac80e4e/repo/tb/tests/No%20use/control_unit_tb.cpp): Contro Unit testbench.

## Top-Level Module

The top-level `control_unit` module instantiates both the `main_decoder` and `ALU_decoder`. It computes the `PCSrc` signal for branch instructions based on the zero flag and the branch signal.

```verilog
assign PCSrc = zero & Branch;
```

The key components are:
- `op`, `funct3`, `funct7`: Extracted fields from the instruction.
- Connections to decoders for generating control signals.

#### Top-Level Connections
```verilog
main_decoder main_decoder_ (
    .op(op),
    .ResultSrc(ResultSrc),
    .MemWrite(MemWrite),
    .ALUSrc(ALUSrc),
    .ImmSrc(ImmSrc),
    .RegWrite(RegWrite),
    .Branch(Branch),
    .ALUOp(ALUOp)
);

ALU_decoder alu_decoder_ (
    .op(op),
    .funct3(funct3),
    .funct7(funct7),
    .ALUOp(ALUOp),
    .ALUctrl(ALUctrl)
);
```

---

## Main Decoder

The `main_decoder` determines high-level control signals such as `MemWrite`, `ALUSrc`, and `Branch` based on the opcode (`op`).

#### Key Logic
- Load Word (`lw`): Enables `RegWrite` and sets `ResultSrc` for memory.
- Store Word (`sw`): Enables `MemWrite` and configures `ImmSrc` for store instructions.
- R-Type: Enables `RegWrite` and sets `ALUOp` for arithmetic operations.
- Branch (`beq`): Configures `Branch` and `ALUOp` for comparison.

#### Main Decoder Logic
```verilog
case (op)
    7'b0000011: begin // lw
        RegWrite = 1;
        ImmSrc = 2'b00;
        ALUSrc = 1;
        MemWrite = 0;
        ResultSrc = 1;
        Branch = 0;
        ALUOp = 2'b00;
    end
    7'b0100011: begin // sw
        RegWrite = 0;
        ImmSrc = 2'b01;
        ALUSrc = 1;
        MemWrite = 1;
        ResultSrc = 0; // don't care
        Branch = 0;
        ALUOp = 2'b00;
    end
    // Other cases omitted for brevity
endcase
```

---

## ALU Decoder

The `ALU_decoder` generates the `ALUctrl` signal based on the `ALUOp`, `funct3`, and `funct7` fields. This determines the specific arithmetic or logical operation to perform.

#### Key Logic
- Add/Subtract: Configured based on `funct7` for R-type operations.
- Logical Operations: Handles `OR`, `AND`, and `SLT` using `funct3`.

#### ALU Decoder Logic
```verilog
case (ALUOp)
    2'b00: ALUctrl = 3'b000; // ADD
    2'b01: ALUctrl = 3'b001; // SUB
    2'b10: begin
        case (funct3)
            3'b000: ALUctrl = (opfunct == 2'b11) ? 3'b001 : 3'b000; // ADD or SUB
            3'b010: ALUctrl = 3'b101; // SLT
            3'b110: ALUctrl = 3'b011; // OR
            3'b111: ALUctrl = 3'b010; // AND
            default: ALUctrl = 3'b000;
        endcase
    end
endcase
```

---

## Testing and Validation

The Control Unit was tested for the following scenarios:
- **Load Word (`lw`)**: Verified correct memory read and register write behavior.
- **Store Word (`sw`)**: Ensured data is correctly stored in memory.
- **Arithmetic Operations**: Confirmed proper ALU control signals for addition and subtraction.
- **Branch (`beq`)**: Verified accurate branching behavior based on the zero flag.


The modular design of the Control Unit simplifies debugging and scalability. It efficiently decodes instructions and generates the necessary control signals for the CPU datapath. Future enhancements involved support for additional RISC-V instructions and integration with pipeline stages.


# Single Cycle ALU

This repository documents the design of an Arithmetic Logic Unit (ALU) for a single-cycle RISCV32I CPU, supporting all instructions specified by the RISC-V ISA. The ALU processes two operands and performs arithmetic, logical, and comparison operations based on a control signal (`ALUctrl`).

## Overview

The ALU module accepts two inputs (`ALUop1` and `ALUop2`) and performs operations such as addition, subtraction, logical AND, OR, and comparisons. It also generates an equality flag (`eq`) for branch instructions.

### Key Features
- **Extensive Operation Support**: Handles all required RISC-V arithmetic, logical, and comparison operations.
- **Parameterization**: Designed with configurable data width (`DATA_WIDTH`) to support various operand sizes.
- **Efficient Design**: Optimized with signed and unsigned arithmetic for accurate comparisons.

## Repository

- [`alu.sv`](https://github.com/Benji-clm/RISC-V-T15/blob/6fc02e2185d52ad8efd14be24972a6c3eac80e4e/repo/rtl/alu.sv): ALU module.
- [`definitions.sv`](https://github.com/Benji-clm/RISC-V-T15/blob/6fc02e2185d52ad8efd14be24972a6c3eac80e4e/repo/rtl/definitions.sv): Contains definitions for `ALUctrl` signal values (Made by Benjamin C.).
- [`testbench`](https://github.com/Benji-clm/RISC-V-T15/blob/6fc02e2185d52ad8efd14be24972a6c3eac80e4e/repo/tb/tests/alu_tb.cpp): Testbenches for ALU validation.

## ALU Architecture

### Module Inputs and Outputs

- **Inputs**:
  - `ALUop1`, `ALUop2`: Operands for the ALU.
  - `ALUctrl`: 4-bit control signal determining the operation.
- **Outputs**:
  - `ALUout`: Result of the operation.
  - `eq`: Equality flag set if the output is zero.

### Supported Operations

The ALU performs the following operations based on the `ALUctrl` signal. These operations are defined in the included `definitions.sv` file:

- Arithmetic: ADD, SUB.
- Logical: AND, OR, XOR.
- Shift: Logical Shift Left (`LSL`), Logical Shift Right (`LSR`), Arithmetic Shift Right (`ASR`).
- Comparisons: Signed Less Than (`SLT`), Unsigned Less Than (`SLTU`).
- Pass-through: Load Operand (`B`).

#### Operation Logic
```verilog
case(ALUctrl)
    `ALUop_ADD:  ALUout = ALUop1 + ALUop2;                             
    `ALUop_SUB:  ALUout = ALUop1 - ALUop2;                             
    `ALUop_AND:  ALUout = ALUop1 & ALUop2;                             
    `ALUop_OR:   ALUout = ALUop1 | ALUop2;                             
    `ALUop_XOR:  ALUout = ALUop1 ^ ALUop2;                            
    `ALUop_LSL:  ALUout = ALUop1 << ALUop2;                       
    `ALUop_LSR:  ALUout = ALUop1 >> ALUop2;                       
    `ALUop_ASR:  ALUout = op1_signed >>> ALUop2;                  
    `ALUop_SLT:  ALUout = (op1_signed < op2_signed) ? 1 : 0;           
    `ALUop_SLTU: ALUout = (ALUop1 < ALUop2) ? 1 : 0;                   
    `ALUop_B:    ALUout = ALUop2;                                      
    default:     ALUout = 0;                                           
endcase
```

---

### Equality Flag (`eq`)

The `eq` output is set to 1 if the result (`ALUout`) equals zero, simplifying branch decision-making for instructions like `BEQ`.

#### Equality Logic
```verilog
eq = (ALUout == 0'b0) ? 1 : 0;
```

---

## Testing and Validation

The ALU was tested using testbenches that verified each supported operation. The key test scenarios included:

1. **Arithmetic Operations**:
    - Verified addition and subtraction with signed and unsigned numbers.
2. **Logical Operations**:
    - Confirmed correct bitwise AND, OR, and XOR behavior.
3. **Shift Operations**:
    - Tested logical and arithmetic shifts for different operand values.
4. **Comparison Operations**:
    - Verified signed and unsigned less-than comparisons.
5. **Equality Flag**:
    - Checked that the equality flag accurately reflected zero output.



The ALU is a critical component of the single-cycle RISCV32I CPU. Its design ensures compatibility with the RISC-V ISA while maintaining efficiency and flexibility.


# Cached Memory

This repository documents the design and implementation of a cached memory system for a single-cycle RISCV32I CPU. The design integrates a `DataCache` for fast memory access, a `DataMem` module for main memory storage, and a `top_mem` module that connects and manages interactions between them.

## Overview

The cached memory system is designed to improve memory access efficiency while supporting various load/store operations. The `DataCache` module acts as an intermediary between the CPU and the main memory, providing faster access to frequently used data.

### Key Features
- **Cache Implementation**: Includes a direct-mapped `DataCache` with eight cache lines.
- **Memory Access Modes**: Supports word, byte, and halfword access in both signed and unsigned formats.
- **Modular Design**: Combines cache and main memory modules for scalability and clarity.
- **Integration**: `top_mem` module integrates cache and memory functionality.

---
## Repository

- [`DataCache.sv`](https://github.com/Benji-clm/RISC-V-T15/blob/ecf447cc3388dd6958205c69a5c75b0c198eb09c/repo/rtl/DataCache.sv): Direct Mapped Cache module.
- ['DataCace.sv'](https://github.com/Benji-clm/RISC-V-T15/blob/master/rtl/DataCache.sv): Two-way set associative Cache module
- [`DataMem.sv`](https://github.com/Benji-clm/RISC-V-T15/blob/ecf447cc3388dd6958205c69a5c75b0c198eb09c/repo/rtl/datamem.sv): Main memory module (designed by Alix).
- [`top_mem.sv`](https://github.com/Benji-clm/RISC-V-T15/blob/ecf447cc3388dd6958205c69a5c75b0c198eb09c/repo/rtl/top_mem.sv): Top-level module integrating cache and memory.
- [`testbench`]: Testbenches for validation.

## Top Memory

The `top_mem` module manages memory read/write operations. It connects the CPU to the `DataCache` and `DataMem`, handling memory access logic based on the `LS_mode` signal.

#### Memory Read Logic
```verilog
case (LS_mode)
    `W_MODE: begin
        rd = rd_cache; 
    end
    `B_MODE: begin
        case (a[1:0])
            2'b00: rd = {{24{byte0[7]}}, byte0};
            2'b01: rd = {{24{byte1[7]}}, byte1};
            2'b10: rd = {{24{byte2[7]}}, byte2};
            2'b11: rd = {{24{byte3[7]}}, byte3};
        endcase
    end
    // Other cases omitted for brevity
endcase
```

---

## Direct-mapped Data Cache

The `DataCache` module is a direct-mapped cache with eight cache lines. It uses a tag and index mechanism to determine whether data is cached. On a cache miss, data is loaded from the main memory into the cache.

#### Key Components
- **Cache Line Structure**: Each line includes valid bits, tag bits, and data bytes.
- **Write Logic**: Handles word, byte, and halfword writes based on `LS_mode`.

#### Cache Read Logic
```verilog
always_comb begin
    address_tag = a[ADDR_WIDTH-1:5];
    cache_index = a[4:2];
    byte_offset = a[1:0];

    if (cache_mem[cache_index].valid_bit && cache_mem[cache_index].tag_bits == address_tag) begin
        rd = {
            cache_mem[cache_index].byte3,
            cache_mem[cache_index].byte2,
            cache_mem[cache_index].byte1,
            cache_mem[cache_index].byte0
        };
    end else begin
        rd = temp_rd;
    end
end
```

#### Cache Write Logic
```verilog
if (we) begin
    cache_mem[cache_index].valid_bit <= 1;
    cache_mem[cache_index].tag_bits <= a[31:5];

    case (LS_mode)
        `W_MODE: begin
            cache_mem[cache_index].byte3 <= wd[31:24];
            cache_mem[cache_index].byte2 <= wd[23:16];
            cache_mem[cache_index].byte1 <= wd[15:8];
            cache_mem[cache_index].byte0 <= wd[7:0];
        end
        // Other cases omitted for brevity
    endcase
end
```


## Data Memory

The `DataMem` module was designed by **Alix**, with minor modifications for compatibility with the cached memory system. It supports both read and write operations, including sign-extension for signed load instructions.

## Testing and Validation

The cached memory system was validated with the following scenarios:

1. **Cache Hits and Misses**:
    - Verified proper cache line updates on misses.
    - Ensured correct data retrieval on hits.
2. **Load/Store Operations**:
    - Tested word, byte, and halfword operations in both signed and unsigned modes.
3. **Integration**:
    - Ensured seamless integration between `DataCache` and `DataMem` through `top_mem`.



The cached memory system enhances memory access efficiency while maintaining compatibility with the single-cycle RISCV32I CPU. The design modularity ensures scalability and ease of debugging. Special thanks to **Alix** for the `DataMem` module.


## Two-way set associative Cache

I decided to implement a two-way set associative cache. Each cache line contains a valid bit, tag, and data storage for multiple instructions.

### Cache Set and Memory
Each cache set is composed of multiple associative ways, and the cache memory consists of multiple sets.

#### Cache Memory Definition
```verilog
typedef struct packed {
    cache_line_t [ASSOC-1:0] ways; // Associative ways
    logic [ASSOC-1:0] lru;         // LRU bits
} cache_set_t;

cache_set_t cache_mem [CACHE_SIZE];
```

### Hit/Miss Detection
Tag comparison is used to determine whether the requested instruction is present in the cache.

####  Hit Detection Logic
```verilog
always_comb begin
    hit = 0;
    hit_way = 0;
    for (int i = 0; i < ASSOC; i++) begin
        if (cache_mem[index].ways[i].valid && cache_mem[index].ways[i].tag == tag) begin
            hit = 1;
            hit_way[i] = 1;
        end
    end
end
```

### Instruction Output Logic
If a cache hit occurs, the requested instruction is retrieved directly from the cache. Otherwise, the default value from the memory module is used.

####  Data Output Logic
```verilog
always_comb begin
    instr = mem_instr; // Default value for instr
    if (hit) begin
        for (int i = 0; i < ASSOC; i++) begin
            if (hit_way[i]) begin
                instr = cache_mem[index].ways[i].data[(block_offset*DATA_WIDTH) +: DATA_WIDTH];
            end
        end
    end
end
```

### Cache Refill and Replacement
On a cache miss, a new cache line is fetched from the memory, and the Least Recently Used (LRU) way is replaced.

I followed LRU policy to implement the cache as follows:
![image](https://github.com/user-attachments/assets/87df0a2b-191a-42fd-a667-ec31ff342213)

#### Replacement Logic
```verilog
always_ff @(posedge clk) begin
    if (!hit) begin
        logic [$clog2(ASSOC)-1:0] lru_way;
        lru_way = 0;
        for (int i = 1; i < ASSOC; i++) begin
            if (cache_mem[index].lru[i] > cache_mem[index].lru[lru_way]) begin
                lru_way = i[$clog2(ASSOC)-1:0];
            end
        end

        // Replace the LRU way
        cache_mem[index].ways[lru_way].data <= mem_data;
        cache_mem[index].ways[lru_way].tag <= tag;
        cache_mem[index].ways[lru_way].valid <= 1;

        // Update LRU
        for (int i = 0; i < ASSOC; i++) begin
            cache_mem[index].lru[i] <= (i[$clog2(ASSOC)-1:0] == lru_way) ? 0 : cache_mem[index].lru[i] + 1;
        end
    end
end
```

---

This instruction cache enhances instruction fetch performance by reducing memory access latency and leveraging a 2-way associative design. Its modular and parameterized approach ensures scalability and adaptability to various CPU configurations.


# Other Modifications

## Top file

Once pipelining and cache stages were finished, I harmonised all inputs and outputs across all modules to ensure that the CPU ran smoothly.

[Major Commits and I/O harmonisation](https://github.com/Benji-clm/RISC-V-T15/commit/b73413423637a0af0a9e71f0f2e36cf1162e4b4e)

## Tests

Along with Benjamin C. I created some tests to test cases for our CPU. This included:
- [BGE](https://github.com/Benji-clm/RISC-V-T15/blob/484941511801aa48c32da72cc9d1401174ad4e2c/tb/asm/11_bge.s)
- [BLTU](https://github.com/Benji-clm/RISC-V-T15/blob/484941511801aa48c32da72cc9d1401174ad4e2c/tb/asm/12_bltu.s)
- [BGEU](https://github.com/Benji-clm/RISC-V-T15/blob/484941511801aa48c32da72cc9d1401174ad4e2c/tb/asm/13_bgeu.s)

# Project Reflection

## What I Learned
- First of all, I got a hands on experience as to how a CPU functions, looking at different modules and putting them together
- I learnt about the difficulties of cache design, including associativity, hit/miss detection, and replacement policies
- How to balance hardware complexity and performance when chosing what to add to the CPU
- A greater understanding of the RISV32I set architecture
- Managing data coherency between the cache and main memory during reads and writes

## Mistakes I Made
- For the ALU, I at first overcomplicated the test cases making the overall module to complicated when it could be simplified using the definitions module which Benjamin C. wrote
- Most of the mistakes whilst making the cache:
 - Initially I forgot about edge cases such as handling misaligned writes for halfword and byte accesses
 - Mismanaged tag and index bit calculations
 - Did not think LRU bits would be useful in the two-way set associative cache

## Special Design Decisions
- For the cache I finally opted for a **two-way set-associative cache** to balance hardware complexity and hit rate, as a direct-mapped cache had higher conflict miss rates in test scenarios
- Chose in the end to make a control unit as one not as a decomposition of main decoder and alu decoder for simplicity when concerting with Benjamin C.

## What I Might Do Differently and If I Had More Time
1. **Try to fully implement Virtual Memory**: 
   - Create the TLB's replacement policy, using a Least Recently Used (LRU) strategy for better cache locality
   - Optimize page table management by implementing a hierarchical page table or leveraging large page support to reduce page table lookups
2. **Design a Superscalar Processor**:
   - Implement multiple issue pipelines to fetch, decode, and execute multiple instructions simultaneously
   - Add dynamic scheduling with a reservation station and reorder buffer to maximize instruction-level parallelism while maintaining precise exceptions





      

      
