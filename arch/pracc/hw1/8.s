.data
dummy: .space 32
buffer: .space 32
stream1: .string "It took me %d iterations to convert %d to binary!\n"
stream2: .string "Number %d in binary equals to "
num: .word 2351    #testing stuff

.text
.globl toBinary
toBinary:

addiu $sp,$sp,-32
sw $ra,28($sp)
sw $a0,24($sp)
sw $a1,20($sp)    #prologue

#$a0 buffer 
#$a1 decimal number to convert to binary

la $t5,dummy
li $t8,0 
li $t7,0  #counters

divide:

beq $a1,$0,copy #loop condition

andi $t0,$a1,1
beq $t0,$0,zero

addiu $t0,$0,49
j continue

zero:
addiu $t0,$0,48 #1 or 0

continue:
sb $t0,($t5)
sra $a1,$a1,1
addiu $t8,$t8,1
addiu $t5,$t5,1
j divide    #store 1/0 and increment stuff


copy: #for reversing the output

addiu $t5,$t5,-1 #get away from '\0' at the beginning
beq $t7,$t8,null_terminate
lb $t0,($t5)
sb $t0,($a0)
addiu $a0,$a0,1
addiu $t7,$t7,1
j copy    #store 1/0 and increment stuff

null_terminate:
addiu $a0,$a0,1
sb $0,($a0)   #null terminate the string in buffer

addu $v0,$0,$t8
lw $ra,28($sp)
lw $a0,24($sp)
lw $a1,20($sp)
addiu $sp,$sp,32
jr $ra    #epilogue




.globl main
main:
addiu $sp,$sp,-32

la $a0,buffer
la $a1,num
lw $a1,($a1)

sw $ra,28($sp)
sw $a0,24($sp)
sw $a1,20($sp)

jal toBinary

addu $a1,$v0,0
la $a0,stream1
lw $a2,20($sp)

jal printf

la $a0,stream2
lw $a1,20($sp)

jal printf

la $a0,buffer

jal printf

lw $ra,28($sp)
lw $a0,24($sp)
lw $a1,20($sp)
addiu $sp,$sp,32
li $v0,0
jr $ra
