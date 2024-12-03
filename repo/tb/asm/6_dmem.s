.text
.globl main
.equ test_mem1, 0x10000  # Define a base address for the first test memory location
.equ test_mem2, 0x10010  # Define a base address for the second test memory location

main:
    # Step 1: Write data to memory
    LI t0, 0x4E           # t0 = 0x4E (value to store)
    LI t1, test_mem1      # t1 = base address 1 (0x10000)
    SB t0, 0(t1)          # Store 0x4E at address 0x10000

    LI t0, 0x3C           # t0 = 0x3C (value to store)
    LI t1, test_mem2      # t1 = base address 2 (0x10010)
    SB t0, 0(t1)          # Store 0x3C at address 0x10010

    # Step 2: Read back the data
    LI t1, test_mem1      # Load base address 1 (0x10000)
    LBU t2, 0(t1)         # Load byte from address 0x10000 into t2

    LI t1, test_mem2      # Load base address 2 (0x10010)
    LBU t3, 0(t1)         # Load byte from address 0x10010 into t3

    # Step 3: Compute the sum of the read values
    ADD a0, t2, t3        # a0 = t2 + t3 (sum of 0x4E and 0x3C)

    # Step 4: End the program
    J wait                # Infinite loop to stop execution

wait:
    J wait                # Infinite loop to stop execution
