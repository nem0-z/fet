.rodata
num: .word 7
str : .string "%f"
.text
.globl main
main:
addiu $sp, $sp, -64
sw $ra, 60($sp)

la $t0, num
lw $a1, ($t0)

#0x40165C28F5C28F5C 5.59 in IEEE754

li $t2,0x40165c28 
li $t3,0xf5c28f5c

mtc1 $t3, $f4 #lower 32 bits
mtc1 $t2, $f5 #upper 32 bits

s.d $f4, 52($sp)

addiu $a0, $sp, 56

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

