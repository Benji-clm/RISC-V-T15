.text
.globl main
main:
    li s0, 0x00010000   # Create pointer to base of data array

    # Store half-word values
    li t1, 0x1234
    sh t1, 0(s0)        # Store 0x1234 at address 0x00010000
    li t2, 0xABCD
    sh t2, 2(s0)        # Store 0xABCD at address 0x00010002

    # Load half-word values
    lhu t3, 0(s0)       # t3 = *(0x00010000) = 0x1234
    lhu t4, 2(s0)       # t4 = *(0x00010002) = 0xABCD

    # Perform addition
    add a0, t3, t4      # a0 = t3 + t4 = 0x1234 + 0xABCD = 0xBDF1
    bne a0, zero, finish # Enter finish state

finish:                 # Expected result is 0xBDF1
    bne a0, zero, finish # Loop forever
