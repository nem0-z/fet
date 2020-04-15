.text
.globl djeljitelj
djeljitelj:

bne $a1,$0,rekurzija

move $v0,$a0
jr $ra

rekurzija:
addiu $sp, $sp, -128
sw $ra, 124($sp)

div $a0,$a1

move $a0,$a1
mfhi $a1

jal djeljitelj

lw $ra, 124($sp)
addiu $sp, $sp, 128
jr $ra



