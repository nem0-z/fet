.data
a: .hword 10
b: .hword 4
str: .asciiz "Stream\n"

.text
.globl main
.globl exchange

main:
addiu $sp,$sp,-28
sw $ra,24($sp)

la $a0,a
la $a1,b    #load addresses

sw $a0,20($sp)
sw $a1,16($sp)  #preserve registers

lh $a1,($a1)
jal exchange

#debug: # bpoint for debugging
#uhmm, this label here causes program to end when it reaches it
#wtf?

lw $ra,24($sp)
lw $a0,20($sp)
lw $a1,16($sp)  #return registers

lh $t2,($a0)
lh $t3,($a1)    #check values

addiu $sp,$sp,28
li $v0,0
jr $ra

exchange:

addiu $sp,$sp,-20
sw $ra,16($sp)

lh $t0,($a0)
sh $a1,($a0)
addu $v0,$0,$t0

#test 
la $a0,str
jal printf

lw $ra,16($sp)
addiu $sp,$sp,20
jr $ra
