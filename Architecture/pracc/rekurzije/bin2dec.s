.rodata
str: .string "Merima\!\|"

.text
.globl konverzija2
konverzija2:

#$a0 -> n
li $t8,10

bne $a0,$0,rekurzija
li $v0, 0
jr $ra

rekurzija:

addiu $sp, $sp, -32
sw $ra, 28($sp)

div $a0,$t8

mfhi $v1
sw $v1, 24($sp)

mflo $a0

jal konverzija2

sll $v0, $v0, 1

lw $v1, 24($sp)
addu $v0, $v0, $v1

lw $ra, 28($sp)
addiu $sp, $sp, 32

jr $ra


