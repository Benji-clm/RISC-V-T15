# Team Report RISC-V-T15

## Group Members:
- Alix Le Coguic
- Selime Ozyurt
- Benjamin Clemente (Repo Master)
- Augustin Briens (Team Report Writer)

## Personal Statements
- Personal Statement Augustin Briens
- Personal Statement Benjamin Clemente
- Personal Statement Selime Ozyurt
- Personal Statement Alix Le Coguic
- 
## Table of Contemts
- [Single Cycle](#single-cycle)
  - F1 Program (Benjamin Clemente, Alix Le Coguic)
  - [Pipeline](#pipeline) (Selime Ozyurt)
  - [Instruction Memory](#instruction-memory) (Selime Ozyurt, Augustin Briens)
  - [ALU](#alu) (Augustin Briens)
  - [Data Memory](#data-memory) (Alix Le Coguic)   
- [Pipeline](#pipeline)
  - 4 Stages of [Pipeline](#pipeline) (Alix Le Coguic, Selime Ozyurt)
  - [Hazard Unit](#hazard-unit) (Benjamin Clemente) 
- [Caches](#caches)
  - [Data Cache](#data-cache) (Augustin Briens)
  - [Top Memory](#top-memory) (Augustin Briens)
  - [Instruction Memory Cache](#i-mem-cache) (Augustin Briens)
- [Top Level](#top-level)
  - [Top file CPU](#top-file) (Benjamin Clemente, Augustin Briens)
  - [Testbenches](#testbenches) (Benjamin Clemente, Augustin Briens)
  - [CPU Tests](#cpu-tests) (Benjamin Clemente, Augustin Briens)


## Important Notes
### Critical Points:
- Ensure to draw attention to significant points such as tests and debugging information.

## Quick Start
### Prerequisite:
Before running **any** script, ensure you are in the correct path. Use the following command to navigate:
```bash
cd tb
```
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
| Other | F1 | | |X| |
|       | Vbuddy | | |X| |



### Proof Of Working CPU on Vbuddy:
#### F1

#### Gaussian

#### Noisy

#### Sine

#### Triangle

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
    Creation of testbenches for verifying CPU functionality:
 
    
    <img width="188" alt="Screenshot 2024-12-13 at 12 16 00" src="https://github.com/user-attachments/assets/84059bbf-8bef-40a8-8b5b-956512b6fd7e" />

  - [CPU Tests](#cpu-tests)  
    See below for the tests in Assembly:
 
    
    <img width="156" alt="Screenshot 2024-12-13 at 12 15 18" src="https://github.com/user-attachments/assets/3c343c69-1182-4a5f-879d-8728e39a704c" />
