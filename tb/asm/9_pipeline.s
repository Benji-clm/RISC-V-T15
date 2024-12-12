.text
.globl main
.equ test_mem, 0x10100  # Test address

main:
    # Step 1: Write a value to memory
    LI t0, 0x4E           # Value to store
    LI t1, test_mem       # Memory address
    SB t0, 0(t1)          # Store 0x4E at 0x10100

    # Add a stall to simulate potential timing issues
    NOP
    NOP
    NOP

    # Step 2: Read the value back using `LBU`
    LBU t2, 0(t1)         # Load byte from 0x10100 into t2

    # Store the result in a0 for verification
    ADDI a0, t2, 0        # a0 = t2 (expected: 0x4E)

    # Infinite loop to stop execution
wait:
    J wait
