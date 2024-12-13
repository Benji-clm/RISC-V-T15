# Team Report RISC-V-T15

## Group Members:
- Alix Le Coguic
- Selime Ozyurt
- Benjamin Clemente (Repo Master)
- Augustin Briens (Team Report Writer)

## Personal Statements
- [Personal Statement Augustin Briens](https://github.com/Benji-clm/RISC-V-T15/blob/master/docs/Personal%20Statement%20Augustin%20Briens.md)
- Personal Statement Benjamin Clemente
- [Personal Statement Selime Ozyurt](docs/Personal%20Statement%20Selime%20Ozyurt.md)
- [Personal Statement Alix Le Coguic](https://github.com/Benji-clm/RISC-V-T15/blob/master/docs/Personal%20Statement%20Alix%20Le%20Coguic.md)

## Table of Contemts
- [Single Cycle](#single-cycle)
  - [Program-Countr](docs/Personal%20Statement%20Selime%20Ozyurt.md#program-counter-block) (Selime Nur Ozyurt)
  - [Register-File](docs/Personal%20Statement%20Selime%20Ozyurt.md#register-file)
  - F1 Program (Benjamin Clemente, Alix Le Coguic)
  - [Instruction Memory](#instruction-memory) (Selime Ozyurt, Augustin Briens)
  - [ALU](#alu) (Augustin Briens)
  - [Data Memory](#data-memory) (Alix Le Coguic)   
- [Pipeline](#pipeline)
  - [4 Stages of Pipeline](docs/Personal%20Statement%20Selime%20Ozyurt.md#pipeline) (Alix Le Coguic, Selime Ozyurt)
  - [Hazard Unit](#hazard-unit) (Benjamin Clemente) 
- [Caches](#caches)
  - [Data Cache](#data-cache) (Augustin Briens, Benjamin Clemente)
  - [Top Memory](#top-memory) (Augustin Briens)
  - [Instruction Memory Cache](#i-mem-cache) (Augustin Briens)
- [Top Level](#top-level)
  - [Top file CPU](#top-file) (Benjamin Clemente, Augustin Briens)
  - [Testbenches](#testbenches) (Benjamin Clemente, Augustin Briens)
  - [CPU Tests](#cpu-tests) (Benjamin Clemente, Augustin Briens)
- [Branch Prediction](#branch-prediction) (Benjamin Clemente)


## Important Notes
### Critical Points:
- Ensure to draw attention to significant points such as tests and debugging information.

## Quick Start
### Prerequisite:
First, make your way to the **testbench** folder, using `cd tb`. \
The main script is `doit.sh` which runs all the tests **within the `tests` folder**.

> For simplicity, the **unit tests** are by default within the `unit_tests` folder, if you want to use these tests, simply move them to the `test` folder.

<br>

Below is a table listing the different shell scripts, and their use:

| Command                               | Behaviour                           |
| ------------------------------------- |-------------------------------------- |
| `./doit.sh`                           | Runs all the test benches within `tb/tests`            |
| `./f1.sh`     | Runs the `f1-lights` program|
| `./gaussian.sh`       | Plots the `gaussian` graph    |
| `./triangle.sh`       | Plots the `triangle` graph    |
| `./noisy.sh`       | Plots the `noisy` graph    |
## Overview
### Contribution Table
|              |                               | Selime | Alix | Ben | Augustin |
| ------------ | ----------------------------- | ------------------ | ---------------- | ------------------------ | ---------------- |
| Lab 4        | Program Counter               |            X       |                  |                          |                  |
|              | ALU                           |                    |         X        |                          |                  |
|              | Register File                 |            X       |         X        |                          |                  |
|              | Instruction Memory            |                    |                  |                          |      X           |
|              | Control Unit                  |                    |                  |            X             |      X           |
|              | Sign Extend                   |                    |                  |                          |      X           |
|              | Testbench                     |                    |                  |            X             |                  |
|              | Topfile/implementation        |                    |                  |            X             |                  |
| Single Cycle | Data Memory                   |                    |        X         |                          |                  |
|              | Program Counter (refactor)    |            X       |                  |                          |                  |
|              | ALU (refactor)                |                    |                  |                          |       X          |
|              | Register File (refactor)      |            X       |        X         |                          |                  |
|              | Instruction Memory (refactor) |            X       |                  |                          |                  |
|              | Control Unit (refactor)       |                    |                  |            X             |                  |
|              | Sign Extend (refactor)        |                    |                  |                          |       X          |
|              | Topfile/implementation        |                    |                  |            X             |       x          |
| Pipeline     | Fetch-Decode pipeline         |          X         |                  |                          |                  |
|              | Decode-Execute pipeline       |         X          |                  |                          |                  |
|              | Execture-Memory pipeline      |                    |         X        |                          |                  |
|              | Memory-WriteBack pipeline     |                    |         X        |                          |                  |
|              | Hazard unit                   |                    |                  |            X             |                  |
| Cache        | Memory (refactor)             |                    |                  |                          |        X         |
|              | Direct mapped cache           |                    |                  |                          |        X         |
|              | Two-way set associative cache |                    |                  |                          |        X         |
|Branch Prediction |                            |                    |                  |           X             |        X         |
| Other | F1 | | |X| |
|       | Vbuddy | | |X| |



### Proof Of Working CPU on Vbuddy:
#### F1



https://github.com/user-attachments/assets/e46eef8f-4ca8-4211-bf2e-87545c885bf0



#### Gaussian

https://github.com/user-attachments/assets/b1405c37-26fd-4ebb-8ade-5423f77de3d8


#### Noisy



https://github.com/user-attachments/assets/0a1737e9-e3f8-4969-b9c9-ad04d3b62692



#### Triangle



https://github.com/user-attachments/assets/44fff449-ee35-4557-bbde-f1ac81cde5f5


### Components
- [Single Cycle](#single-cycle)
  - F1 Program  
    Initial implementation of a single-cycle CPU program.
  - [Pipeline](#pipeline)  
    Design and implementation of pipeline functionality in the CPU.
  - [Instruction Memory](#instruction-memory)  
    Development of instruction memory for single-cycle execution.
  - [ALU](#alu)  
    Arithmetic Logic Unit creation for computation in the CPU.
  - [Data Memory](#data-memory)  
    Implementation of data memory handling for the CPU.

- [Pipeline](#pipeline)
  - 4 Stages of [Pipeline](#pipeline)  
    Design and breakdown of the CPU pipeline into 4 functional stages.
  - [Hazard Unit](#hazard-unit)  
    Hazard detection and resolution unit implementation for pipeline safety.

- [Caches](#caches)
  - [Data Cache](#data-cache)  
    Creation of a cache for optimized data memory access.
  - [Top Memory](#top-memory)  
    Integration of memory hierarchy at the top level of the CPU.
  - [Instruction Memory Cache](#i-mem-cache)  
    Development of an instruction cache for faster access to instruction memory.

- [Top Level](#top-level)
  - [Top file CPU](#top-file)  
    Integration of CPU components at the top level and harmonisation of Inputs and Outputs
  - [Testbenches](#testbenches)  
    Creation of testbenches for unit-testing CPU functionality:

  - [CPU Tests](#cpu-tests) 
    Creation of Assembly codes and test benches for integration testing of the CPU
