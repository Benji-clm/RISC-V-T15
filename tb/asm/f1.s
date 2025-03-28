init:
    addi s1, zero, 0x1  /* assigning required values */
    addi s2, zero, 0xff 
    addi s3, zero, 0x3  /* determines delay between lights */
    addi a3, zero, 0x1 

rst:
    addi a0, zero, 0x0 /* reset all */
    addi a4, zero, 0x0 
    addi t0, zero, 0x0 

mainloop:
    beq  t0, s1, fsm    /* trigger */ 
    srli a2, a3, 0x3    /* LFSR */
    andi a2, a2, 0x1
    xor  a2, a2, a3
    andi a2, a2, 0x1 
    slli a3, a3, 0x1 
    add  a3, a3, a2 
    andi a3, a3, 0xf
    jal  ra, mainloop   /* Loop  */

fsm:
    jal  ra, lightdelay      /* add const delay */
    slli t1, a0, 0x1    /* shift left temp bits */
    addi a0, t1, 0x1    /* add 1 to shifted temp bits */
    bne  a0, s2, fsm    /* loop only if not all lights are on */

increment:
    beq  a4, a3, rst
    jal  ra, lightdelay      /* jump to counter */
    addi a4, a4, 0x1    /* inc delay */
    jal  ra, increment  /* run until delay finished */

lightdelay:
    addi  a1, a1, 0x1   /* inc count */
    bne   a1, s3, lightdelay
    addi  a1, zero, 0x0 /* reset count */
    RET


