.text
.globl main
.equ test_mem, 0x10100  # Test address

main:
    # Write a byte to memory
    LI t0, 0x4E           # Value to store
    LI t1, test_mem       # Memory address
    SB t0, 0(t1)          # Store 0x4E at 0x10100

    # Read back the value using `LBU`
    LBU t2, 0(t1)         # Load the byte back into t2

    # Store the read value in a0 for verification
    ADDI a0, t2, 0        # a0 = t2 (expected: 0x4E)

    # Infinite loop to stop execution
wait:
    J wait
