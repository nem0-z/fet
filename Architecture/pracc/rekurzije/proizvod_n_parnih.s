.text
.globl proizvod
proizvod:

#$a0 -> n
li $t0,2    #za provjeru

bne $a0,$t0,rekurzija
move $v0, $t0
jr $ra

rekurzija:
addiu $sp, $sp, -4096
sw $ra, 4092($sp)
sw $a0, 4088($sp)

addiu $a0,$a0,-1
jal proizvod 

lw $a0, 4088($sp)

li $t0,2    #za provjeru
div $a0,$t0

mfhi $t0

beq $t0,$0,komplikovano
j end

komplikovano:
mult $a0,$v0
mflo $v0

end:
lw $ra, 4092($sp)
addiu $sp, $sp, 4096
jr $ra



