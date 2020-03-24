.text
.globl transform
transform:

addiu $sp,$sp,-32
sw $ra,28($sp)
sw $a2,24($sp)
sw $a1,20($sp)
sw $a0,16($sp)

#$a0 buffer
#$a1 buffer size -> limit
#$a2 function pointer

li $t3,0 #counter
addu $t0,$0,$a0

call:
beq $t3,$a1,out
lb $a0,($t0)

jalr $a2

sb $v0,($t0)
addiu $t0,$t0,1
addiu $t3,$t3,1
j call

out:
lw $ra,28($sp)
lw $a2,24($sp)
lw $a1,20($sp)
lw $a0,16($sp)
addiu $sp,$sp,32
jr $ra
