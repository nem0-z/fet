.data
d: .double 6.28

.rodata 
num: .word 7
str: .string "%f"

.text
.globl main
.globl foo

main:
addiu $sp, $sp, -64
sw $ra, 60($sp)

#0x40165C28 F5C28F5C
li $t0, 0x40165c28
li $t1, 0xf5c28f5c

sw $t1, 52($sp)
sw $t0, 56($sp)

addiu $a0, $sp, 52

la $a1, num
lw $a1, ($a1)

jal foo

s.s $f0, 48($sp)

la $a0, str
cvt.d.s $f0, $f0
mfc1 $a2, $f0
mfc1 $a3, $f1

jal printf

lw $ra, 60($sp)
addiu $sp, $sp, 64
li $v0, 0
jr $ra


foo:
#$a0 double pointer
#$a1 integer

l.d $f4, ($a0)
# *x u $f4
mtc1 $a1, $f6
cvt.d.w $f6, $f6
# n u $f6

la $t0, d
l.d $f8, ($t0)

c.lt.d $f4, $f6
bc1f else
add.d $f4, $f4, $f8
s.d $f4, ($a0)
addiu $t0, $0, 3
mtc1 $t0, $f8
cvt.d.w $f8, $f8
mul.d $f0, $f4, $f8
cvt.s.d $f0, $f0
jr $ra

else:
sub.d $f4, $f4, $f8
s.d $f4, ($a0)
sub.d $f0, $f4, $f6
cvt.s.d $f0, $f0
jr $ra
