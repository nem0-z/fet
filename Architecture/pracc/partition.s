.text
.globl partition

 partition:
# $a0 -> niz*   $a1 -> size   $a2 -> predicate 

addiu $sp, $sp, -8192
sw $ra, 8188($sp)

sll $t0, $a1, 2
addiu $t0, $t0, -4    #size*4 - 4

addu $a1, $a0, $t0    #niz + size*4 - 4

jal partition_impl

lw $ra, 8188($sp)
addiu $sp, $sp, 8192
jr $ra

 partition_impl:

# $a0 -> first*   $a1 -> second*  $a2 -> predicate

bne $a0, $a1, rekurzija
jr $ra                  #if first == second return;

rekurzija:

addiu $sp, $sp, -256
sw $ra, 252($sp)
sw $a0, 248($sp)
sw $a1, 244($sp)
sw $a2, 240($sp)

lw $a0, ($a0)
jalr $a2        #dereference first and call predicate

beq $v0, $0, else

lw $a0, 248($sp)
lw $a1, 244($sp)

jal swap        #return preserved a0 and a1 and call swap

addiu $a1, $a1, -4
sw $a1, 244($sp)

j callpartition #skip this else label

else:

lw $a0, 248($sp)
addiu $a0, $a0, 4
sw $a0, 248($sp)

callpartition:

lw $a0, 248($sp)
lw $a1, 244($sp)
lw $a2, 240($sp)      #load every change you made and prepare for recursive call

jal partition_impl

lw $ra, 252($sp)
addiu $sp, $sp, 256
jr $ra
