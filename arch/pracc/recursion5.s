
#/* { */
#/*   if(n<=1) return 1; */
#/*   else return n*fakt(n-1); */
#/* } */

.text
.globl fakt
fakt:


li $t0, 1
beq $a0, $t0, jedan
slt $t1, $a0, $t0
bne $t1, $0, jedan

addiu $sp, $sp, -16
sw $ra, 12($sp)

sw $a0, 8($sp)

addi $a0, $a0, -1

jal fakt

lw $t0, 8($sp)

mult $t0, $v0
mflo $v0

lw $ra, 12($sp)
addiu $sp, $sp, 16
jr $ra

jedan:
li $v0, 1
jr $ra
