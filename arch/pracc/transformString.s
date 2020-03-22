.rodata
str: .string "NeStO!?A"

.data
res: .space 100 #take 100 bytes 

.text
.globl main
main:

la $t4,str
la $t8,res

range:

lb $t0,($t4)
beq $t0,$0,out

slti $t3,$t0,123
beq $t3,$0,hop1

slti $t3,$t0,97
beq $t3,$0,hop1

addiu $t0,$t0,32

hop1:

sb $t0,($t8)

addiu $t8,$t8,1
addiu $t4,$t4,1
j range

out:

li $v0,0
jr $ra


