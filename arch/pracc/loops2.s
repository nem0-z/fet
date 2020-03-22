#for given array, determine
#sum of all even numbers
#sum of all odd numbers
#print greater of those two

.rodata
myarr: .hword 1,2,3,4,5,6,7,8,9,10,11,12
print_string: .asciiz "Veca suma iznosi %d\n"

.data
sum_odd: .hword 0
sum_even: .hword 0

.text
.globl main
main:

addiu $sp,$sp,-20
sw $ra,16($sp)

la $t0,myarr

la $t1,sum_odd
lhu $t1,($t1)

la $t2,sum_even
lhu $t2,($t2)

li $t7,0 #set counter

check:
slti $t3,$t7,12 #uslov
beq $t3,$0,out #gtfo at the end

lhu $t4,($t0) #$t4 = arr[i]

addiu $t0,$t0,2 #increment adress
addiu $t7,$t7,1 #increment counter

andi $t5,$t4,1 #check odd or even
beq $t5,$0,even

addu $t1,$t1,$t4
j check

even:
addu $t2,$t2,$t4
j check

out:
la $a0,print_string

slt $t0,$t1,$t2
bne $t0,$0,prep
addu $a1,$0,$t1
j call

prep:
addu $a1,$0,$t2

call:
jal printf

lw $ra,16($sp)
addiu $sp,$sp,20
li $v0,0
jr $ra
#just practicing arrays/loops so won't be messing with stack, no need

