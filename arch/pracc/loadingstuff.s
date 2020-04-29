.rodata
str: .string "%f"

.text
.globl main
main:
addiu $sp, $sp, -64
sw $ra, 60($sp)

#0x4077A1F7 CED91687
li $t0, 0xced91687
li $t1, 0x4077a1f7

sw $t0, 52($sp)
sw $t1, 56($sp)

addiu $a0, $sp, 52

jal foo

la $a0, str
lw $a2, 52($sp)
lw $a3, 56($sp)

jal printf

lw $ra, 60($sp)
addiu $sp, $sp, 64
li $v0, 0
jr $ra

.globl foo
foo:

l.d $f4, ($a0)
addiu $t0, $0, 2
mtc1 $t0, $f6
cvt.d.w $f6, $f6
mul.d $f8, $f4, $f6
s.d $f8, ($a0)
jr $ra
