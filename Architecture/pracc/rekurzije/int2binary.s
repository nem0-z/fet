.text
.globl int2bin
int2bin:


li $t1, 2
li $t2, 10

bne $a0, $0, rekurzija

li $v0, 0
jr $ra

rekurzija:
addiu $sp, $sp, -128
sw $ra, 124($sp)

div $a0, $t1
mfhi $t7

sw $t7, 120($sp)

mflo $a0

jal int2bin

mult $v0,$t2
mflo $t8

lw $t7, 120($sp)

addu $v0,$t7,$t8

lw $ra, 124($sp)
addiu $sp, $sp, 128
jr $ra



