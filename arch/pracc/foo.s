.data
str: .string "Test"
test: .word str
str1: .string "Testing %f input."

.text
.globl main
main:
addiu $sp, $sp, -24
sw $ra, 20($sp)

#ori $t0, $0, 0xffff
#addi $t1, $0, 0xffff

#if (t0<=t1) printf("Test")

li $t2, -1  #0xffffffff
#reset 10th bit
ori $t3, $0, 32769
xor $t3, $t3, -1
and $t2, $t2, $t3

li $t0, 3
li $t1, 2

beq $t0, $t1, print
slt $t8, $t0, $t1 #t0 < t1 : false -> t0 >= t1
bne $t8, $0, print
j end


print:
la $a0, test
lw $a0, ($a0)

jal printf


end:

addi $t0, $0, 2
mtc1 $t0, $f6
cvt.d.w $f6, $f6
s.d $f6, 8($sp)
#mfc1 $a2, $f6
#mfc1 $a3, $f7
lw $a3, 12($sp)
lw $a2, 8($sp)

la $a0, str1

jal printf

lw $ra, 20($sp)
addiu $sp, $sp, 24
li $v0, 0
jr $ra
