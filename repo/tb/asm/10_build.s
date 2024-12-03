.text
.globl main
.equ base_pdf, 0x100
.equ base_data, 0x10000
.equ max_count, 200

main:
    JAL     ra, init  # Jump to init, ra and save position to ra
    J       finish    # Skip build and display functions

init:       # Function to initialise PDF buffer memory
    LI      a1, 0x100           # loop_count a1 = 256
_loop1:                         # repeat
    ADDI    a1, a1, -1          #     decrement a1
    SB      zero, base_pdf(a1)  #     mem[base_pdf+a1) = 0
    BNE     a1, zero, _loop1    # until a1 = 0
    RET

finish:     # Function to set the return value then wait
    LI      a0, 0               # Indicate successful initialization
_wait:
    BNE     a0, zero, _wait     # Loop forever
