.text
.globl calculate
calculate:

#$a0 -> niz*   $a1 -> size

addiu $sp,$sp,-64
sw $ra,60($sp)

slti $t0,$a1,2
beq $t0,$0,rekurzija

li $a0,1
jal transform   #transform(1)
#return value in $v0

j end

rekurzija:

lw $t0,($a0)
lw $t1,4($a0)   #dereference niz and niz+1

addu $t0,$t0,$t1 #*niz + *(niz+1)
sw $t0,32($sp) #save on stack

addiu $a0,$a0,4
addiu $a1,$a1,-1

jal calculate

move $a0,$v0       #call transform with return of calculate

jal transform

lw $t0,32($sp)  #load *niz + *(niz+1)

addu $v0,$v0,$t0

end:

lw $ra,60($sp)
addiu $sp,$sp,64
jr $ra
