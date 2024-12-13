Name: Benjamin Clemente \
CID: 02401985 \
GitHub username: Benji-clm

## Summary

- I worked mainly on assembling the CPU and **testing**. I was also the repo-master.
- I also did a fair share of code review, where I helped guide my teammates towards fixing their code, and sometimes fixed it myself.
- I also worked a lot on the **FPGA**, where I was able to fully synthetize our CPU design onto the *DE10-Lite*, even achieving a theoretical $f_{max} = 300 MHz$.
- Finally, I created a **2-bit branch unit**, which successfully improved speed by up to $20 \%$, and mitigated stalls and misprediction penalties.

## Single-cycle CPU
- Unit Testing for the Single-cycle CPU components: [1](https://github.com/Benji-clm/RISC-V-T15/commit/ad97162de5b1c71f993c772b9a73fb3a16d8e750), [2](https://github.com/Benji-clm/RISC-V-T15/commit/aba2028af67102549ae35e41be150653a83370d4), [3](https://github.com/Benji-clm/RISC-V-T15/commit/df277e353f138b83c96ba6e647286cab12ddd9dc)
- Code Fixes: [1](https://github.com/Benji-clm/RISC-V-T15/commit/63812d48e99a931d67d628ff0fa7a5df072bb2cf), [2](https://github.com/Benji-clm/RISC-V-T15/commit/d25efc142985122da3d4e1366b1fbb54287fa423)
- Putting Everything together: [1](https://github.com/Benji-clm/RISC-V-T15/commit/bb74ff7ef03d9c2cab7b17eb08a459dd336b08fa) 
## Pipelined CPU
- Hazard-unit: [1](https://github.com/Benji-clm/RISC-V-T15/commit/0e0d4a209d03c5875ce934c43667723e10e488fe), [2](https://github.com/Benji-clm/RISC-V-T15/commit/8783fbc118c2a90af45cb9a639fcf49530c0f0cf)
- Code Fixes: [1](https://github.com/Benji-clm/RISC-V-T15/commit/9e6a9c1e80707d42e04918ed637d0245e835421c), [2](https://github.com/Benji-clm/RISC-V-T15/commit/fedfc920902fe59581c8a9e72b1fbf01aaf273a5), [3](https://github.com/Benji-clm/RISC-V-T15/commit/19045937bf5562959d6f061f19cdb8bdd9debc96)
- Testing: [1](https://github.com/Benji-clm/RISC-V-T15/commits/master/?author=Benji-clm&before=e72c5e5798d52fa4581719bda63147d18dabef57+35)
- Assembling: [1](https://github.com/Benji-clm/RISC-V-T15/commit/9ffae0fb1289f4d89dc5e0f63161f9d38cc058aa)
## [FPGA](https://github.com/Benji-clm/RISC-V-T15/blob/master/FPGA/FPGA.md)  (Separate .md file)
-  [1](https://github.com/Benji-clm/RISC-V-T15/commit/9a587a4e00443a855f6066ee4a99f27ca6a1ed6e)
## Branch Prediction
- Logic (rtl): [1](https://github.com/Benji-clm/RISC-V-T15/commit/e36187aa663fb4b33cac2d96841e65868ea45fa1)
- Tests: [1](https://github.com/Benji-clm/RISC-V-T15/commit/5fae8dd4a018d1a6fd63d1fb05d7efb63422dac8)
<br>

## **Single-Cycle CPU**

The single-cycle CPU is a foundational implementation of the RISC-V architecture, executing one instruction per clock cycle. This section details my contributions to the design, testing, and verification of this CPU.

---

### **Design Details**

The single-cycle CPU integrates several essential components:
1. **Register File**: Provides fast read and write access to 32 registers.
2. **ALU (Arithmetic Logic Unit)**: Performs arithmetic, logical, and comparison operations.
3. **Control Unit**: Decodes instructions and generates control signals for the datapath.
4. **Instruction Memory**: Stores program instructions.
5. **Data Memory**: Stores data used in load and store operations.

Key features include:
- Full support for RISC-V base integer instructions (RV32I).
- Parameterized components for modularity and scalability.
- Clean datapath with minimal combinational logic delays.

---

### **Unit Testing**

Rigorous testing was performed for individual components, ensuring their correctness before integration. Below is an example of unit testing for the **Register File**.

#### **Code Example: Register File Testbench**

```cpp
/*
 *  Verifies the results of the mux, exits with a 0 on success.
 */

#include "base_testbench.h"

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class regfTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->clk = 1;
        top->a1 = 0x0;
        top->a2 = 0x0;
        top->a3 = 0x0;
        top->we3 = 0;
        top->wd3 = 0x0;
        // output: RD1 and RD2
    }

    void tick() {
        top->clk = 0; // Clock low
        top->eval();
        tfp->dump(ticks++);

        top->clk = 1; // Clock high
        top->eval();
        tfp->dump(ticks++);
    }

};

TEST_F(regfTestbench, RegConnectRegistryA)
{
    int inputreg = 0x12345678;

    top->a3 = 1;
    top->wd3 = inputreg;
    top->we3 = 1;

    top->a1 = 0;
    top->a2 = 0;

    tick();
    
    top->a1 = 1;
    top->a2 = 0;

    tick();

    top->we3 = 0;

    EXPECT_EQ(top->rd1, inputreg);
    EXPECT_EQ(top->rd2, 0);
}

int main(int argc, char **argv)
{
    top = new Vdut;
    tfp = new VerilatedVcdC;

    Verilated::traceEverOn(true);
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");

    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();

    top->final();
    tfp->close();

    delete top;
    delete tfp;

    return res;
}
```

#### **Explanation**

This testbench verifies the functionality of the register file by:
1. Initializing the inputs (`a1`, `a2`, `a3`, `we3`, and `wd3`).
2. Writing a value (`inputreg`) to a specific register (`a3`) with `we3` (write enable) set to 1.
3. Reading back values from the registers (`rd1` and `rd2`) to ensure the correct data was written and other registers were not affected.

The testing framework (`gtest`) provides assertions (`EXPECT_EQ`) to validate the results:
- `top->rd1` should match the written value.
- `top->rd2` should remain 0.

---

### **Key Features**

- **Ease of Testing**: Implemented a reusable `tick()` function to simulate clock cycles, simplifying the testing process for all modules. This approach ensures consistent simulation of rising and falling edges of the clock, reducing repetitive code and errors in testbenches.
- **Modularity**: The `tick()` function encapsulates clock toggling logic, making it easier to integrate with different test scenarios and components.
- **Efficiency**: Reduces boilerplate code in testbenches, allowing for more focused and streamlined test cases.
<br>

<br>

---
## **Control Unit**

The control unit is a critical module in the RISC-V CPU design. It interprets the opcode, `funct3`, and `funct7` fields from the instruction to generate control signals for other components in the datapath. This module ensures proper coordination of all parts of the CPU, enabling correct execution of instructions.

---

### **Design Details**

The control unit is designed with the following features:
1. **Input Signals**:
   - `op` (7 bits): The opcode field, which specifies the type of instruction (R-type, I-type, S-type, etc.).
   - `funct3` (3 bits): Encodes specific instruction behaviour within an opcode class.
   - `funct7` (7 bits): Further refines the behaviour of certain instructions.
   - `stall` (1 bit): Halts writes to the register file and memory during pipeline stalls.

2. **Output Signals**:
   - `PCsrc` (3 bits): Controls program counter updates (e.g., next PC, branch, jump).
   - `ResultSrc` (2 bits): Selects the data source for the write-back stage.
   - `MemWrite` (1 bit): Enables memory writes.
   - `ALUControl` (4 bits): Determines the ALU operation to execute (e.g., ADD, SUB, OR).
   - `ALUsrc` (1 bit): Chooses between immediate or register as the second ALU operand.
   - `ImmSrc` (3 bits): Specifies the type of immediate (I-type, S-type, B-type, etc.).
   - `RegWrite` (1 bit): Enables writes to the register file.
   - `LS_mode` (3 bits): Specifies the size and signed/unsigned behavior for load/store instructions.
   - `MemRead` (1 bit): Enables memory reads.

---

### **Key Features**

- **Comprehensive Instruction Coverage**: The control unit handles all RV32I base instructions, including R-type, I-type, S-type, B-type, J-type, and U-type instructions.
- **Default Signal Values**: Default values are assigned to ensure predictable behaviour for unsupported instructions.
- **Pipeline Stall Handling**: If a stall signal is active, the control unit disables memory writes and register writes to avoid data hazards.
- **Environment Calls**: We decided not to implement environment calls for simplicity, although they can be useful for certain programs.

---

### **Modular Design with `definitions.sv`**

To improve code maintainability and readability, a `definitions.sv` file was created. This file contains macros for:
1. **ALU Control Signals**: Defines operations like `ALUop_ADD`, `ALUop_SUB`, etc.
2. **Immediate Types**: Defines types like `I_TYPE`, `S_TYPE`, `B_TYPE`, etc.
3. **PC Source Signals**: Encodes values for `NEXT_PC`, `EQ_TRUE`, `UC_JUMP`, etc.
4. **Load/Store Modes**: Defines `B_MODE`, `W_MODE`, `H_MODE`, etc.

**Advantages**:
- **Code Readability**: Makes the code self-explanatory by replacing raw numbers with descriptive macros.
- **Ease of Integration**: Other modules (e.g., datapath, ALU) can directly use the defined macros, ensuring consistency across the CPU.
- **Scalability**: Adding new instructions or modifying signal values is centralized and straightforward.

Example:
```systemverilog
// Defining opcodes for the different branching conditions -> allows for several B-type operations
// The opcode will help us determine how to check whether we branch or not (combined with `eq`).
`define NEXT_PC         3'b000
`define EQ_TRUE         3'b001
`define EQ_FALSE        3'b010
`define UC_JUMP         3'b011
`define JALR            3'b100
```

---

### **Design Breakdown**

#### **Instruction Decoding**
The control unit decodes the opcode (`op`), `funct3`, and `funct7` fields to generate control signals. For example:
- **R-Type Instructions**:
  - Opcode: `7'b0110011`
  - Control Signals: `ALUsrc = 0`, `RegWrite = 1`, `ALUControl` based on `funct3` and `funct7`.

- **I-Type Instructions**:
  - Opcode: `7'b0010011`
  - Control Signals: `ALUsrc = 1`, `RegWrite = 1`, immediate type is `I_TYPE`.

- **Load/Store Instructions**:
  - Load (`7'b000011`): Sets `MemRead = 1`, `ResultSrc = 1`.
  - Store (`7'b0100011`): Sets `MemWrite = 1`, `ALUsrc = 1`.

#### **Branch Instructions**
Branch instructions (e.g., BEQ, BNE, BLT) use `PCsrc` to decide whether to branch or proceed sequentially. The ALU computes conditions (e.g., equality or comparison), and `PCsrc` is updated accordingly.

Example:
- BEQ (`3'b000`): `PCsrc = EQ_TRUE` if `ALUControl = SUB` and operands are equal.
- BLT (`3'b100`): `PCsrc = EQ_FALSE` if `ALUControl = SLT` and operand1 < operand2.

#### **Pipeline Stall Handling**
When a stall is detected (`stall = 1`), `MemWrite` and `RegWrite` are disabled to prevent unintended overwrites.

---

### **Example Code Snippets**

#### **R-Type Instruction**
```systemverilog
7'b0110011: begin
    ALUsrc = 0;
    RegWrite = 1;

    case(funct3)
        3'b000: begin
            case(funct7)
                7'h00: ALUControl = `ALUop_ADD;
                7'h20: ALUControl = `ALUop_SUB;
                default: $display("Warning: Undefined R-Type instruction");
            endcase
        end
        3'b010: ALUControl = `ALUop_SLT;
        3'b111: ALUControl = `ALUop_AND;
        default: $display("Warning: Unrecognized R-type instruction");
    endcase
end
```

#### **Load Instruction**
```systemverilog
7'b000011: begin
    ALUControl = `ALUop_ADD;
    ImmSrc = `I_TYPE;
    ALUsrc = 1;
    ResultSrc = 1;
    RegWrite = 1;
    MemRead = 1;

    case(funct3)
        3'b000: LS_mode = `B_MODE;  // lb
        3'b010: LS_mode = `W_MODE;  // lw
        3'b100: LS_mode = `UB_MODE; // lbu
        default: $display("Warning: Unrecognized Load instruction");
    endcase
end
```

#### **Branch Instruction**
```systemverilog
7'b1100011: begin
    ImmSrc = `B_TYPE;
    ALUsrc = 0;
    RegWrite = 0;

    case(funct3)
        3'b000: begin // beq
            ALUControl = `ALUop_SUB;
            PCsrc = `EQ_TRUE;
        end
        3'b100: begin // blt
            ALUControl = `ALUop_SLT;
            PCsrc = `EQ_FALSE;
        end
        default: $display("Warning: Unrecognized Branch instruction");
    endcase
end
```

---

### **Advantages of the Design**

- **Scalability**: The modular structure, combined with the `definitions.sv` file, allows for easy addition of new instructions.
- **Error Handling**: Warnings for unrecognized instructions or unsupported fields ensure better debugging and maintainability.
- **Efficiency**: Default signal assignments reduce the number of explicit cases, streamlining the decoding logic.

---
### **Code Fixes**

Testing and debugging were crucial aspects of the development process, often requiring significant time and effort to track down the root cause of errors. Given the complexity of the control unit and its interactions with other modules, identifying issues involved rigorous testing and analysis. For instance, some bugs manifested as subtle misbehavior in branch instructions, which necessitated examining waveforms using **GTKWave** to pinpoint discrepancies in signal timing and values.  Debugging was a meticulous process, often requiring iteration between the testbench and the module design, but these efforts were vital for ensuring the robustness and reliability of the CPU.

<br>

<br>

---

## **Hazard Unit**

The hazard unit is a critical component in the pipelined CPU, responsible for handling data hazards and control hazards to ensure correct program execution. It manages stalling, forwarding, and flushing signals to resolve hazards without breaking the sequential semantics of instructions.

---

### **Design Details**

The hazard unit is designed to handle two types of hazards:
1. **Data Hazards**: Occur when an instruction depends on the result of a previous instruction that has not yet completed.
2. **Control Hazards**: Arise during branch or jump instructions, where the program counter (PC) may need to be updated.

---

### **Key Features**

- **Stalling**: The hazard unit generates `StallF` and `StallD` signals to pause the fetch (`F`) and decode (`D`) stages of the pipeline when a load-use hazard occurs.
- **Forwarding**: Dynamically resolves data hazards by forwarding values from the memory (`M`) or write-back (`W`) stage to the execute (`E`) stage using `ForwardAE` and `ForwardBE` signals.
- **Flushing**: Ensures that invalid instructions in the pipeline are cleared by generating a `Flush` signal, particularly during branch mispredictions or jumps.
- **Low Overhead**: Designed to minimize performance loss while maintaining correctness.

---

### **Hazard Resolution**

#### **1. Data Hazard Resolution**
- **Forwarding Logic**: 
  - If a source register in the execute stage (`Rs1E` or `Rs2E`) matches the destination register in the memory stage (`RdM`) or write-back stage (`RdW`), and the corresponding write-enable signal is active (`RegWriteM` or `RegWriteW`), the hazard unit forwards the value.
  - Forwarding is encoded as:
    - `2'b10`: Forward from the memory stage (`ALUResultM`).
    - `2'b01`: Forward from the write-back stage (`ResultW`).
    - `2'b00`: No forwarding (use the register file output).
- Example Logic for `ForwardAE`:

  ```systemverilog
  if (((Rs1E == RdM) && RegWriteM) && (Rs1E != 0)) begin
      ForwardAE = 2'b10;
  end else if (((Rs1E == RdW) && RegWriteW) && (Rs1E != 0)) begin 
      ForwardAE = 2'b01;
  end else begin 
      ForwardAE = 2'b00;
  end
```

- **Stalling Logic**:
  - A stall occurs when a load-use hazard is detected. This happens when the result of a load instruction (`ResultSrcE`) is used by the next instruction (`Rs1D` or `Rs2D` match `RdE`).
  - The stall signals (`StallF`, `StallD`) are asserted to pause the fetch and decode stages:
  ```systemverilog
  if (ResultSrcE && ((Rs1D == RdE) || (Rs2D == RdE))) begin
      lwStall = 1'b1;
  end else begin
      lwStall = 1'b0;
  end

  StallF = lwStall;
  StallD = lwStall;
  ```

#### **2. Control Hazard Resolution**
- **Flushing Logic**:
  - When a branch or jump instruction is taken, the pipeline must flush invalid instructions from the fetch and decode stages. This is done using the `Flush` signal:
  ```systemverilog
  Flush = Hazard_PCsrc;
  ```
  - `Hazard_PCsrc` indicates whether a branch or jump target is being taken.

---

### **Key Design Decisions**

- **Forwarding for Efficiency**:
  - Forwarding eliminates unnecessary stalls for many data hazards, significantly improving performance in the pipelined design.
- **Stall for Load-Use Hazards**:
  - The unit stalls the pipeline only when absolutely necessary, such as during load-use dependencies, to balance performance and correctness.
- **Modular Signals**:
  - Outputs like `ForwardAE`, `ForwardBE`, `StallF`, `StallD`, and `Flush` are modular and easily integrable with the rest of the pipeline.

---

### **Advantages**

1. **Improved Performance**:
   - Forwarding minimizes stalls and ensures efficient data flow across pipeline stages.
2. **Correct Execution**:
   - By accurately handling hazards, the unit ensures that instruction dependencies and control flow are respected.
3. **Simplified Integration**:
   - Modular outputs enable straightforward integration with the datapath and other pipeline components.

---
### **Testing**

The hazard unit was thoroughly tested using various scenarios to ensure correctness:
1. **Data Hazards**:
   - Simulated load-use hazards and verified that stalls were correctly inserted.
   - Verified that forwarding resolved data dependencies for both `ForwardAE` and `ForwardBE`.
2. **Control Hazards**:
   - Tested branch instructions with correct and incorrect predictions to ensure proper flushing behaviour.
3. **Integration**:
   - Combined the hazard unit with other pipeline components to test end-to-end functionality.

Key commits for the hazard unit:
-  [1](https://github.com/Benji-clm/RISC-V-T15/commit/0e0d4a209d03c5875ce934c43667723e10e488fe), [2](https://github.com/Benji-clm/RISC-V-T15/commit/8783fbc118c2a90af45cb9a639fcf49530c0f0cf)
<br>


<br>

---

## **Branch Prediction Unit**

The branch prediction unit is a key performance-enhancing component in the pipelined CPU, reducing control hazards by predicting the outcome of branch instructions during the fetch stage. This module employs a **two-bit saturating counter** prediction strategy, combined with a **Branch History Table (BHT)** and a **Branch Target Buffer (BTB)**, to improve the accuracy of branch predictions.

---

### **Design Overview**

The branch prediction unit operates in two main phases:
1. **Prediction (Fetch Stage)**:
   - Predicts whether the branch is taken or not (`branch_predictF`).
   - Provides the predicted target address (`branch_targetF`) if the branch is predicted as taken.

2. **Update (Execute Stage)**:
   - Updates the BHT and BTB based on the actual outcome of the branch (`branch_taken`).
   - Refines prediction accuracy by updating the two-bit saturating counter in the BHT and storing the correct target address in the BTB.

---

### **Key Components**

#### **1. Branch History Table (BHT)**

The BHT is an array of **two-bit saturating counters**, one for each entry. These counters represent the likelihood of a branch being taken:
- **State Encoding**:
  - `00`: Strongly not taken.
  - `01`: Weakly not taken.
  - `10`: Weakly taken.
  - `11`: Strongly taken.
- **Prediction Logic**:
  - Predict **taken** if the most significant bit (`stateF[1]`) of the counter is `1`.
  - Predict **not taken** otherwise.

**Indexing**:
- The BHT is indexed using the lower bits of the program counter (`pcF` for fetch stage and `pcE` for execute stage). These bits are selected based on the BHT size (log2 of the number of entries).

#### **2. Branch Target Buffer (BTB)**

The BTB stores the target addresses of branches predicted as taken. It ensures that the correct target address is available in the fetch stage when a branch is predicted as taken.

**Indexing**:
- Similar to the BHT, the BTB is indexed using the lower bits of the program counter.

---

### **Prediction Logic (Fetch Stage)**

During the fetch stage, the branch prediction unit provides:
- `branch_predictF`: Indicates whether the branch is predicted as taken.
- `branch_targetF`: Provides the target address for the predicted branch.

**Steps**:
1. The program counter (`pcF`) is used to compute the index into the BHT and BTB.
2. The current state of the branch (from the BHT) is read.
3. If the state indicates "taken" (`stateF[1] == 1`), the branch is predicted as taken, and the target address is fetched from the BTB.
4. If the state indicates "not taken," the branch is predicted as not taken, and the target is simply the next sequential instruction (`pcF + 4`).

Example Logic:
```systemverilog
always_comb begin
    stateF = bht[indexF];
    if (stateF[1] == 1) begin
        branch_predictF = 1'b1;
        branch_targetF = btb[indexF];
    end else begin
        branch_predictF = 1'b0;
        branch_targetF = pcF + 4;
    end
end
```

### **Update Logic (Execute Stage)**

When the actual outcome of a branch is resolved in the execute stage:
- The BHT is updated to refine future predictions based on the actual outcome (`branch_taken`).
- The BTB is updated with the correct target address for taken branches.

**Steps**:
1. The program counter of the branch (`pcE`) is used to compute the index into the BHT and BTB.
2. The current state of the branch (from the BHT) is updated based on whether the branch was actually taken or not:
   - **If taken**:
     - Increment the counter up to `11` (saturating at `11`).
     - Update the BTB with the actual target address (`targetE`).
   - **If not taken**:
     - Decrement the counter down to `00` (saturating at `00`).

**Example Logic**:
```systemverilog
if (branch_taken) begin
    case (current_state)
        2'b00: bht[indexE] <= 2'b01; // strongly not taken -> weakly not taken
        2'b01: bht[indexE] <= 2'b10; // weakly not taken -> weakly taken
        2'b10: bht[indexE] <= 2'b11; // weakly taken -> strongly taken
        2'b11: bht[indexE] <= 2'b11; // strongly taken stays
    endcase
    btb[indexE] <= targetE; // Update BTB
end else begin
    case (current_state)
        2'b00: bht[indexE] <= 2'b00; // already strongly not taken
        2'b01: bht[indexE] <= 2'b00; // weakly not taken -> strongly not taken
        2'b10: bht[indexE] <= 2'b01; // weakly taken -> weakly not taken
        2'b11: bht[indexE] <= 2'b10; // strongly taken -> weakly taken
    endcase
end
```

---

### **Key Design Features**

1. **Two-Bit Saturating Counters**:
   - Reduces the likelihood of mispredictions by using two bits to track branch history.
   - Allows for gradual changes in prediction state, improving stability.
   - Much more accurate than a **1-bit** predictor.

2. **Branch Target Buffer**:
   - Provides fast access to branch target addresses, reducing the delay in fetching the correct instruction for taken branches.

3. **Parameterized Design**:
   - The module supports configurable address width and number of BHT entries (`BHT_ENTRIES`), making it scalable for different pipeline configurations.

4. **Prediction Accuracy**:
   - By using a combination of branch history and a dedicated target buffer, the design achieves high accuracy, minimizing pipeline stalls caused by branch mispredictions.

---

### **Advantages**

- **Reduced Control Hazards**:
  - Accurate branch predictions allow the pipeline to continue fetching instructions speculatively, minimizing the performance impact of control hazards.
- **Scalability**:
  - The parameterized size of the BHT and BTB allows the design to be adapted to pipelines with varying branch densities.
- **Simplicity and Efficiency**:
  - The use of saturating counters and a small, indexed BTB ensures low overhead while maintaining high prediction accuracy. 

<br>

<br>

---

## **Branch Prediction Unit Testing**

Testing the branch prediction unit is essential to ensure its accuracy and performance in predicting branch outcomes and managing branch targets. The following testbench verifies the functionality of the unit by simulating various branch scenarios and checking the outputs against expected results.

---

### **Testbench Explanation**

The testbench is built using the Google Test framework and simulates the branch prediction logic through:
1. **Initialization**:
   - Inputs such as `pcF`, `pcE`, `branch_valid`, `branch_taken`, and `targetE` are initialized.
   - The branch predictor is reset to ensure a consistent starting state.
2. **Prediction Testing**:
   - The testbench verifies that the predictor initializes with a "not taken" state for all branches.
3. **Training the Predictor**:
   - The testbench simulates multiple taken outcomes for a branch to transition the corresponding two-bit counter in the Branch History Table (BHT) to the "strongly taken" state.
4. **Validation of Predictions**:
   - The testbench checks that the branch predictor correctly predicts taken/not taken based on prior branch outcomes.
   - The branch target is also validated against the expected stored target.

---

### **Code Example**

#### **Test: Basic Prediction Behaviour**
```cpp
// Test that the predictor starts off predicting not taken and transitions after multiple taken branches
TEST_F(BranchPredTestbench, BasicPredictionTest) {
    // Bring out of reset
    initializeInputs();
    tick(); // latch reset state
    top->reset = 0;
    tick(); // apply reset removal

    // Initially, at pcF = 0, we expect not taken prediction
    top->pcF = 0x100;  // arbitrary PC
    top->eval();
    EXPECT_EQ(top->branch_predictF, 0) << "Initially should predict not taken.";
    EXPECT_EQ(top->branch_targetF, (uint32_t)0x104) << "Initially target should be pcF+4";

    // Let's define the branch at pcE=0x100, say it was taken multiple times
    // This should move predictor's saturating counter towards taken.
    uint32_t branch_pc = 0x100;
    uint32_t branch_target = 0x200; // predicted target to set
    top->pcE = branch_pc;
    top->branch_valid = 1;
    top->branch_taken = 1;
    top->targetE = branch_target;

    // Apply several taken updates to push the counter towards strongly taken
    for (int i = 0; i < 4; i++) {
        tick();
    }

    // Now stop asserting branch_valid so we can check new prediction
    top->branch_valid = 0;
    top->branch_taken = 0;

    // Fetch again from pcF = 0x100 and see if we now predict taken
    top->pcF = branch_pc;
    top->eval();
    // After multiple taken outcomes, we should see the predictor guess taken
    EXPECT_EQ(top->branch_predictF, 1) << "After training, should predict taken.";
    EXPECT_EQ(top->branch_targetF, branch_target) << "After training, target should match what we stored.";

    // Done with test
}
```

#### **Explanation of the Test**
1. **Initial State Validation**:
   - At the beginning, the branch predictor is expected to predict "not taken" for all branches. This is verified using `EXPECT_EQ` assertions.
   - The branch target is checked to be `pcF + 4` (next sequential instruction).

2. **Branch Training**:
   - The testbench simulates a branch at `pcE = 0x100` that is repeatedly taken.
   - Each cycle, the branch predictor updates the BHT counter for the corresponding index to move closer to the "strongly taken" state.
   - The BTB is updated with the branch target address.

3. **Post-Training Validation**:
   - After multiple updates, the predictor is re-tested for the same branch.
   - It is expected to predict "taken" with the stored target address.

---

### **Additional Testing Scenarios**

1. **Not Taken Branch Behavior**:
   - Simulate a branch that is consistently "not taken" and verify the BHT counter transitions to "strongly not taken."

2. **Mixed Outcomes**:
   - Alternate branch outcomes (taken and not taken) to validate the behavior of weakly taken/not taken states.

3. **Reset Behavior**:
   - Verify that resetting the branch predictor initializes all BHT entries to "strongly not taken" and clears the BTB.

---

### **Advantages of the Testbench**

- **Comprehensive Testing**:
  - Covers a variety of branch outcomes, ensuring the predictor handles all scenarios correctly.
- **Incremental Validation**:
  - Validates behavior at different stages (initialization, training, and prediction).
- **Realistic Scenarios**:
  - Simulates real pipeline conditions, including branching patterns and targets.

---

### **Output Expectations**

1. **Initial State**:
   - `branch_predictF = 0` for all branches.
   - `branch_targetF = pcF + 4`.

2. **Post-Training State**:
   - For a trained branch, `branch_predictF = 1` if the branch was consistently taken.
   - `branch_targetF` matches the correct target address stored in the BTB.

3. **Transition Behaviour**:
   - The two-bit counters in the BHT should transition gradually based on the branch outcomes.

<br>

<br>

---

## **Overall Assembly of the RISC-V CPU**

The assembly of the RISC-V CPU integrates all the designed modules, creating a complete pipelined processor capable of executing RV32I base instructions. This section provides an overview of the assembly process, detailing the interaction between the pipeline stages, hazard resolution, and auxiliary units such as branch prediction and memory.

---

### **Key Design Goals**
1. **Modular Integration**:
   - Each stage of the pipeline (Fetch, Decode, Execute, Memory, and Writeback) is implemented as a distinct module, allowing for flexibility and scalability.
2. **Efficient Hazard Resolution**:
   - The hazard unit resolves data and control hazards dynamically using stalling, forwarding, and flushing mechanisms.
3. **Performance Optimization**:
   - The branch prediction unit minimizes control hazards, while forwarding logic reduces unnecessary stalls caused by data dependencies.
4. **Scalability**:
   - Parameterized components ensure adaptability for different instruction widths or pipeline configurations.

---

### **Pipeline Stages and Interconnections**

#### **1. Fetch Stage**
- **Components**:
  - Program Counter (`pcF`): Tracks the address of the next instruction.
  - Instruction Cache: Fetches instructions from memory.
  - Branch Prediction Unit: Provides predictions for branch outcomes and target addresses.
- **Outputs**:
  - The instruction (`instr`) is passed to the Decode stage.
  - The program counter (`pcF`) is updated based on the branch prediction or sequential logic.

#### **2. Decode Stage**
- **Components**:
  - Instruction Decoder: Extracts opcode, `funct3`, and `funct7` fields from the instruction.
  - Control Unit: Generates control signals such as `PCsrc`, `ALUsrc`, and `MemWrite`.
  - Register File: Reads source register values (`rd1` and `rd2`).
  - Sign Extension Unit: Extends immediate values to 32 bits.
- **Outputs**:
  - Decoded signals and operands are passed to the Execute stage.
  - Hazard detection logic ensures stalls or flushes are applied as needed.

#### **3. Execute Stage**
- **Components**:
  - ALU: Performs arithmetic, logical, and comparison operations.
  - Forwarding Logic: Resolves data hazards by dynamically forwarding values from later pipeline stages.
  - Branch Logic: Evaluates branch conditions and determines the target address for taken branches.
- **Outputs**:
  - The ALU result (`ALUResult`) and memory write data (`WriteDataE`) are passed to the Memory stage.
  - The branch condition outcome (`Hazard_PCsrc`) informs the control logic for flushing and updating the PC.

#### **4. Memory Stage**
- **Components**:
  - Data Memory: Reads or writes data based on the control signals and ALU results.
  - Pipeline Registers: Buffer outputs for the Writeback stage.
- **Outputs**:
  - Memory read data (`rd`) and ALU results are forwarded to the Writeback stage.

#### **5. Writeback Stage**
- **Components**:
  - Multiplexer: Selects the data source for writing back to the register file (ALU result, memory read data, or PC+4).
  - Register File Writeback: Writes the selected value to the destination register.
- **Outputs**:
  - Updated register values complete the instruction execution cycle.

---

### **Hazard Resolution**

- **Hazard Unit**:
  - Dynamically handles data and control hazards by:
    - Stalling the pipeline (`StallF`, `StallD`) during load-use dependencies.
    - Forwarding data (`ForwardAE`, `ForwardBE`) from later stages to the Execute stage.
    - Flushing invalid instructions (`Flush`) during branch mispredictions or jumps.
- **Branch Prediction**:
  - Minimizes control hazards by predicting branch outcomes in the Fetch stage.
  - Updates predictions dynamically based on actual outcomes in the Execute stage.

---

### **Auxiliary Units**

1. **Branch Prediction Unit**:
   - Employs a two-bit saturating counter for accurate branch outcome predictions.
   - Reduces control hazards by preemptively updating the PC for predicted-taken branches.
2. **Instruction and Data Memory**:
   - Implements caches for efficient instruction fetches and memory accesses, reducing access latency.
3. **Pipeline Registers**:
   - Separate each stage of the pipeline to maintain data integrity and enable concurrent execution of instructions.

---

### **Key Challenges and Solutions**

- **Challenge**: Resolving hazards in a pipelined architecture.
  - **Solution**: A combination of hazard detection, forwarding, stalling, and branch prediction ensures correct execution while minimizing performance loss.
- **Challenge**: Maintaining modularity in a complex design.
  - **Solution**: Parameterized modules and clear interfaces simplify integration and allow for future scalability.

---

### **Advantages of the Design**

1. **High Performance**:
   - The pipelined architecture allows multiple instructions to execute simultaneously, significantly improving throughput.
   - Optimizations like branch prediction and forwarding reduce pipeline stalls and improve execution efficiency.
2. **Scalability**:
   - Parameterized modules support easy adaptation to different architectures or expanded instruction sets.
3. **Modularity**:
   - The separation of concerns in each pipeline stage makes the design maintainable and extensible.

---

### **Conclusion**

The overall assembly of the RISC-V CPU demonstrates a robust and efficient implementation of a pipelined processor. By integrating hazard resolution mechanisms, branch prediction, and memory management, the design achieves both correctness and performance. The modularity and scalability of the design ensure that it can be adapted for more complex architectures or instruction sets in the future. It was great fun working on this project, I learned so much and loved it!

<br>

<br>

---

## What I learned

Before this project, apart from the Labs, I had no experience in HDL, testing and FPGA. My only relevant experience was that of the RISCV ISA, which I had learned to create my own compiler over the summer. 

After this project, I feel much more computer with computer architecture, hardware design, testing, and even hardware synthesis. Being on the testing side took a lot of patience and resilience, as sometimes, the source of bugs can be extremely difficult to track down, but it rewards a great feeling of achievement when you finally put your finger on it.

<br>

<br>

---

## Reflection

The process wasn't perfect, far from it, and I have made my fair share of mistakes along the way, so here is a non-exhaustive list containing some of them, and what could have been done better.

- **Repo Management**: Although we haven't been affected too much by merging issues, and other git related issues, we could have made a better use of **branches**, which could have allowed us to keep track of different versions of the CPU more easily, and to have kept log of the **single-cycle** CPU in one o the branch.
- **Testing**: At first, I decided to do full unit-testing, which was tedious, and not necessary for simple components. However, as the CPU expanded, I moved towards **integration testing**, this was good at first, as it reduced unnecessary codes. However, it took me a while to debug the pipelined CPU, as the `pdf` test wasn't passing, if only I had decided to do **unit-testing** on some of the critical parts of the CPU (notably `dmem`), it could have perhaps significantly reduced the time it took me to debug it.
- **FPGA**: As I had never worked previously on FPGAs, I started directly trying to put our CPU design onto Quartus and compile it, I quickly learned that I knew nothing about FPGAs... I had to go back and learn properly how to use FPGAs, notably synthetizing simpler models and learning the different tools needed. I wish I had spent that initial time, where I tried to skip steps and go directly to the finish line, learning instead, which I had to do in the end anyways.
