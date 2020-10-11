.text
.globl partition
partition:
addiu $sp, $sp, -32
sw $ra, 28($sp)

sll $t0, $a1, 2
addu $a1, $a0, $t0
addiu $a1, $a1, -4

jal partition_impl

lw $ra,28($sp)
addiu $sp, $sp, 32
jr $ra


partition_impl: #ne stavljamo globl, static

bne $a0, $a1, call_predicate
jr $ra

call_predicate:
addiu $sp, $sp, -64
sw $ra,60($sp)
sw $a0,32($sp)
sw $a1,36($sp)
sw $a2,40($sp)

lw $a0,($a0)

jalr $a2

beq $v0, $0, else

lw $a0,32($sp)
lw $a1,36($sp)

jal swap

lw $a1,36($sp)  #ucitaj prezervirani $a1 tj second jer sta znas sta je swap s njeg uradio
addiu $a1, $a1, -4  #second--;
sw $a1,36($sp)

j rekurzija

else:
lw $a0,32($sp)  #ucitaj prezervirani $a0 tj first jer sta znas sta je $a2 s njeg uradio
addiu $a0, $a0, 4   #first++;
sw $a0,32($sp)

rekurzija:

lw $a0, 32($sp) #pogledaj snimak vjezbi, detaljno je objasnio zasto koji ucitavamo
lw $a1, 36($sp) #ili jednostavno prodji sam jos jednom kroz flow control, nisi glup! :) dobar si druze :)
lw $a2, 40($sp)

jal partition_impl

lw $ra, 60($sp)
addiu $sp, $sp, 64
jr $ra






