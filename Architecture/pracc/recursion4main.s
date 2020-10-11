.data
str: .string "%d"

.text
.globl main
main:

addiu $sp,$sp,-64
sw $ra,60($sp)

li $t0,2
sw $t0,36($sp)
li $t0,9
sw $t0,40($sp)
li $t0,2
sw $t0,44($sp)
li $t0,4
sw $t0,48($sp)
li $t0,7
sw $t0,52($sp)

addiu $a0,$sp,36
li $a1,5

jal calculate

move $a1,$v0
la $a0,str
jal printf

lw $ra,60($sp)
addiu $sp,$sp,64
li $v0,0
jr $ra
