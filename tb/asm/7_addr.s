.text
.globl main
main:
    # Test address calculation
    LI a1, 0x10000           # Base address (base_data)
    LI a2, 0x100             # Offset
    ADD a5, a1, a2           # a5 = base_data + offset

    # Store the computed address in a0 for verification
    ADDI a0, a5, 0           # a0 = a5 (expected: 0x10100)

    # Infinite loop to stop execution
wait:
    J wait
