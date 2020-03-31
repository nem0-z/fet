#factoriel of a number
.data
a: .word 5

.text
.globl main
main:

addiu $sp,$sp,-32
sw $ra,28($sp)

la $t0,a
lw $a0,($t0)

jal factoriel
#grab from $v0

lw $ra,28($sp)
addiu $sp,$sp,32
li $v0,0
jr $ra

factoriel:

#if n == 1 return 1; we can consider as if n<2
#else return n*factoriel(n-1);

slti $t0,$a0,2
beq $t0,0,racunaj
li $v0,1
jr $ra

racunaj:
addiu $sp,$sp,-32
sw $ra,28($sp)
sw $a0,24($sp)

addiu $a0,$a0,-1
jal factoriel

addu $t1,$0,$v0
lw $a0,24($sp)

mult $a0,$t1
mflo $v0

lw $ra,28($sp)
addiu $sp,$sp,32
jr $ra


