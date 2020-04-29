#$f12 vracaj $f0
.rodata
str: .string "%f"

.text
.globl foo
foo:

addiu $t0, $0, 3
mtc1 $t0, $f4
cvt.d.w $f4, $f4

mul.d $f0, $f12, $f4

jr $ra

.globl main
main:

addiu $sp, $sp, -32
sw $ra, 28($sp)

# 0x40120000 00000000

li $t0,0
li $t1, 0x40120000

mtc1 $t0, $f12
mtc1 $t1, $f13

jal foo

mfc1 $a2, $f0
mfc1 $a3, $f1
la $a0, str

jal printf

lw $ra, 28($sp)
addiu $sp, $sp, 32
li $v0, 0
jr $ra
