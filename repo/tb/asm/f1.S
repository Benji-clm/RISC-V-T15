init:
    addi s1, zero, 0x0     /* Initialize counter to 0 */
    addi s2, zero, 0x8     /* Set counter limit to 8 (we count 0-8) */
    addi s3, zero, 0x3     /* Set delay constant for light */
    addi a3, zero, 0x1     /* Initialize delay multiplier */

rst:
    addi a0, zero, 0x0     /* Reset counter to 0 */
    addi a4, zero, 0x0     /* Reset delay counter */
    addi t0, zero, 0x0     /* Reset temporary variables */

mainloop:
    beq a0, s2, delay      /* If counter reaches 8, go to delay */
    addi a0, a0, 0x1       /* Increment counter */
    jal ra, lightdelay     /* Add delay before next increment */
    jal ra, mainloop       /* Loop until counter reaches 8 */

delay:
    jal ra, lightdelay     /* Add a delay when reaching 8 */
    addi a0, zero, 0x0     /* Reset counter to 0 */
    bne a0, s2, mainloop   /* Continue the loop once the delay is done */

lightdelay:
    addi a1, a1, 0x1       /* Increment delay count */
    bne a1, s3, lightdelay /* Wait until delay count reaches s3 */
    addi a1, zero, 0x0     /* Reset delay count */
    RET                    /* Return from lightdelay */

