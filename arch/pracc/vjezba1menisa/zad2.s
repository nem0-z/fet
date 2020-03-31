#Data je funkcija f(x)=|16x-32|+3x, x je cijeli broj. Izračunati vrijednost funkcije za n elemenata
#niza te rezultate smještati u niz rez.

.data
n: .word 2
x: .word -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 6
rez: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

.text
.globl apsolutno
.globl f
.globl main

main:
addiu $sp,$sp,-256 #CUZ I CAN
sw $ra,252($sp)
sw $s0,248($sp)
sw $s1,244($sp)
sw $s2,240($sp)
sw $s3,236($sp)

la $s0,x
la $s1,rez
la $s2,n

li $t0,0
lw $s2,($s2)

check:
beq $t0,$s2,out

sll $t1,$t0,2
addu $s0,$s0,$t1
addu $s1,$s1,$t1
lw $a0,($s0)
jal f
sw $v0,($s1)
addiu $t0,$t0,1
j check

out:
lw $ra,252($sp)
lw $s0,248($sp)
lw $s1,244($sp)
lw $s2,240($sp)
lw $s3,236($sp)
addiu $sp,$sp,256
li $v0,0
jr $ra

f:
#return apsolutno(16*x-32)+3*x;
addiu $sp,$sp,-64
sw $ra,60($sp)
sw $a0,56($sp)

sll $a0,$a0,4
addiu $a0,$a0,-32

jal apsolutno

lw $a0,56($sp)
sll $t0,$a0,2
subu $t0,$t0,$a0

addu $v0,$v0,$t0
lw $ra,60($sp)
addiu $sp,$sp,64
jr $ra

apsolutno:

slti $t0,$a0,0
beq $t0,$0,positive

neg $v0,$a0
j end

positive:
addu $v0,$0,$a0

end:
jr $ra
