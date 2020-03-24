.data
arr1: .word 1,3,5,7,9,-9,-7,-5,-3,-1
arr2: .word 0,2,4,6,8,-8,-6,-4,-2,0
arrSize: .word 40

.text
.globl swap
.globl main

main:

addiu $sp,$sp,-48
sw $a2,28($sp)
sw $a0,24($sp)
sw $a1,20($sp)
sw $ra,16($sp)

la $t1,arrSize
lw $t1,($t1)
la $t2,arr1
la $t3,arr2

addu $a2,$0,$t1
addu $a0,$0,$t2
addu $a1,$0,$t3

jal swap

lw $ra,16($sp)
lw $a0,24($sp)
lw $a1,20($sp)
lw $a2,28($sp)
addiu $sp,$sp,48
li $v0,0
jr $ra


swap:
addiu $sp,$sp,-32
sw $ra,16($sp)
sw $a2,28($sp)
sw $a0,24($sp)
sw $a1,20($sp)

#$a0 je adresa prvog niza
#$a1 je adresa drugog niza
#$a2 je size*sizeof(int)

sra $t0,$a2,2 # $t0 limit
li $t1,0  #$t1 counter
addu $t2,$0,$a0
addu $t3,$0,$a1

size:
sll $t5,$t1,2
addu $t2,$a0,$t5
addu $t3,$a1,$t5

beq $t1,$t0,out

lw $t4,($t2)
lw $t5,($t3)
sw $t5,($t2)
sw $t4,($t3)
addiu $t1,$t1,1
j size


out:
lw $a0,24($sp)
lw $a1,20($sp)
lw $a2,28($sp)
lw $ra,16($sp)
addiu $sp,$sp,32

jr $ra


