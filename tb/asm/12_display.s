.text
.globl main

.equ base_pdf, 0x100

main:
    JAL     ra, display   # Call the display function
    J       verify_sum    # Check the result

display:    # Compute the sum of all bins
    LI      s1, 0               # Sum accumulator
    LI      a1, 0               # Offset into pdf array
    LI      a2, 255             # Max index of pdf array
_loop3:
    ADD     t0, a1, base_pdf    # Calculate address base_pdf + a1
    LBU     t1, 0(t0)           # Load bin value
    ADD     s1, s1, t1          # Add to sum
    ADDI    a1, a1, 1           # Increment offset
    BNE     a1, a2, _loop3      # Loop until all bins are summed
    ADDI    a0, s1, 0           # Store sum in a0
    RET

verify_sum: # Verify that the sum matches expected value
    LI      t0, 28707           # Expected sum (from analysis)
    BEQ     a0, t0, pass        # If equal, test passes
    J       fail                # Otherwise, test fails

pass:
    LI      a0, 0               # Indicate success
    J       wait

fail:
    LI      a0, 1               # Indicate failure
    J       wait

wait:
    J wait
