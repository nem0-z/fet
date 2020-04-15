.text
.globl foo
foo:
addiu $sp, $sp, -64
sw $ra, 60($sp)

slti $t2,$a0,2

beq $t2,$0,elif
li $v0,0
jr $ra

elif:
slti $t2,$a1,3
beq $t2,$0,go

li $v0,1
jr $ra

go:
sh $a0,56($sp)
sh $a1,52($sp)

slt $t2,$a0,$a1
beq $t2,$0,else

addiu $a0, $a0, -1
addiu $a1, $a1, -3

jal foo

lh $t4,56($sp)
addu $v0, $v0, $t4 

lw $ra, 60($sp)
addiu $sp, $sp, 64
jr $ra


else:

addiu $a0, $a0, -2
addiu $a1, $a1, -1

jal foo

lh $t3,56($sp)
lh $t4,52($sp)

subu $t3, $t3, $t4
addu $v0, $v0, $t3

lw $ra, 60($sp)
addiu $sp, $sp, 64

jr $ra

