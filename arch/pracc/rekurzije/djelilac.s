.text
.globl stepen
stepen:
#$a0 -> baza $a1 -> eksponent
bne $a1,$0,rekurzija1
li $v0, 1
jr $ra

rekurzija1:
addiu $sp, $sp, -64
sw $ra, 60($sp)

addiu $a1, $a1, -1
sw $a0, 56($sp)

jal stepen

lw $a0, 56($sp)

mult $a0, $v0
mflo $v0

lw $ra, 60($sp)
addiu $sp, $sp, 64
jr $ra


.globl hfc
hfc:
#$a0 -> n1 $a1 -> n2
beq $a1, $0, rekurzija2
move $v0, $a0
jr $ra

rekurzija2:
addiu $sp, $sp, -64
sw $ra, 60($sp)

div $a0, $a1

move $a0, $a1
mfhi $a1

jal hfc

lw $ra, 60($sp)
addiu $sp, $sp, 64
jr $ra



