    .text
    .globl _start

_start:
    # Test case 1: 15 >=u 10 (unsigned comparison), should branch
    li t0, 15         # Load immediate value 15 into t0
    li t1, 10         # Load immediate value 10 into t1
    bgeu t0, t1, branched  # If t0 >=u t1, branch to "branched"

    # If no branch occurs, set a0 to 0x00 (No branch)
    li a0, 0x00       # No branch taken
    j end_test        # Jump to end of test

branched:
    # If branch occurs, set a0 to 0x01 (Branch taken)
    li a0, 0x01       # Branch taken

end_test:
    # Exit the program
    li a7, 10         # Exit system call
    ecall             # Make the system call to exit

