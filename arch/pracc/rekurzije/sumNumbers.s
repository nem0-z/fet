.text
.globl sumNumber
sumNumber:

#$a0 -> num

bne $a0, $0, rekurzija
li $v0, 0
jr $ra

rekurzija:
addiu $sp, $sp, -128
sw $ra, 124($sp)

sw $a0, 120($sp)
addiu $a0, $a0, -1

jal sumNumber

lw $v1, 120($sp)
addu $v0, $v0, $v1

lw $ra, 124($sp)
addiu $sp, $sp, 128
jr $ra
