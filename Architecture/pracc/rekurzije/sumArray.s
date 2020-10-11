.text
.globl sum
sum:

#$a0 -> niz* $a1 -> n

bne $a1, $0, rekurzija

li $v0, 0
jr $ra

rekurzija:

addiu $sp, $sp, -64
sw $ra, 60($sp)

sll $t0, $a1, 2
addu $t2, $a0, $t0

lw $t1, -4($t2)

sw $t1, 56($sp)

addiu $a1, $a1, -1

jal sum

lw $v1, 56($sp)
addu $v0, $v0, $v1

lw $ra, 60($sp)
addiu $sp, $sp, 64
jr $ra

