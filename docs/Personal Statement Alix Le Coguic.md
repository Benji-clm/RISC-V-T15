# Personal Statement: Alix Le Coguic

*Name*: Alix Le Coguic  
*CID*: 02460647  
*GitHub Username*: calixta216  

## Contributions:

### Lab 4 - Simplified RISC-V CPU:
I was responsible for implementing the following:

- *ALU module* (alu.sv)
- *Register File module* (regf.sv): Co-written with Selime, who assisted in implementing the [DATA_WIDTH-1:0] rf [DATA_WIDTH-1:0] logic after my initial version.

### Single-Cycle RISC-V CPU:
For the single-cycle RISC-V CPU, I implemented:

- *Data memory module* (datamem.sv)
- *Refactoring the Register File module* (regf.sv) with Selime’s help.

### Pipelined RISC-V CPU:
For the pipelined RISC-V CPU, I implemented:

- *Execute-memory pipeline module* (execute_mem_pipe.sv)
- *Memory-writeback pipeline module* (mem_writeback_pipe.sv)

Additionally, I assisted with the f1 testbench.

## Lab 4 Contributions:

- Implementing the ALU was relatively straightforward, with only a few instructions needing implementation. The main issue I encountered was selecting the correct add instruction for the testbenches due to some confusion.
  
- Implementing the Register File module was more complex. I initially used a wire for the rf logic, which caused issues. With Selime’s help, we corrected it by using a logic variable instead.
  
- I also faced challenges with blocking vs. non-blocking assignments in both the ALU and Register File modules. I had to revisit the first lectures on this topic. Additionally, I mistakenly used posedge instead of negedge for certain signals, which I corrected after it was pointed out in lecture that RISC-V would be implemented on negedge.

### Single-Cycle CPU:
- As mentioned earlier, I refactored the Register File module with Selime’s help.
- I also implemented the *data memory module* for the full single-cycle CPU. This involved using a similar logic variable for the memory. I faced challenges in handling different cases, and wrote several versions before finding the most effective implementation.

### Pipelined CPU:
- For the pipelined CPU, I implemented both the *execute-memory pipeline module* and the *memory-writeback pipeline module*. The main mistake I made was focusing on implementing flush logic, which wasn’t required for these stages.

## Reflections:

### What I Learned:
This project significantly enhanced my skills in SystemVerilog, Git, and RISC-V assembly, while deepening my understanding of *CPU architecture. I gained hands-on experience in designing and implementing key CPU components, from the **ALU* to the *pipeline stages. The project required effective **time management, **collaboration, and **clear communication, especially when working on modules like the **Register File* with teammates. This experience allowed me to bridge the gap between theory and practice, helping me gain a more thorough understanding of CPU design.

### Mistakes & What I Would Have Done Differently:
- While working on the *ALU module*, I initially misunderstood the testbench requirements, leading to delays. In hindsight, I would have clarified these specifications earlier to avoid confusion.
  
- During the *Register File* module development, I mistakenly used a wire for the rf logic instead of the required logic, which created issues. A more thorough review of SystemVerilog data types would have helped avoid this mistake.
  
- When working on the *data memory module* in the single-cycle CPU, I spent too much time experimenting instead of having a clearer plan upfront, which slowed down the process.
  
- Additionally, in the *pipelined CPU, I focused unnecessarily on **flush logic*, which wasn’t required for the stages I was working on. A better understanding of the pipeline structure would have helped me avoid this.

### Conclusion:
Overall, more preparation, clearer focus on module-specific requirements, and a better understanding of the system as a whole would have improved my efficiency and reduced time spent on avoidable mistakes.
