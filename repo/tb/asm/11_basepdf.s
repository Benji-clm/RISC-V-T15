.text
.globl main

.equ base_pdf, 0x100

main:
    # Write a known pattern to base_pdf
    LI t0, base_pdf      # Base address of pdf array
    LI t1, 0             # Offset
    LI t2, 255           # Max offset
    LI t3, 0xAA          # Pattern to write
_loop_write:
    ADD t4, t0, t1       # Calculate address
    SB t3, 0(t4)         # Write pattern
    ADDI t1, t1, 1       # Increment offset
    BNE t1, t2, _loop_write

    # Verify the written pattern
    LI t1, 0             # Reset offset
_loop_verify:
    ADD t4, t0, t1       # Calculate address
    LBU t5, 0(t4)        # Load value
    BNE t5, t3, error    # If mismatch, jump to error
    ADDI t1, t1, 1       # Increment offset
    BNE t1, t2, _loop_verify

    # Pass test
    J wait

error:
    LI a0, 1             # Error state
    J wait

wait:
    J wait
