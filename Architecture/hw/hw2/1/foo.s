.data
i: .word 2
j: .word 3

.rodata
str: .string "foo(%d, %d), %hd\n"

.text
.globl main
main:

addiu $sp, $sp, -128
sw $ra, 124($sp)
sw $s0, 48($sp)
sw $s1, 52($sp)
sw $s2, 56($sp)
sw $s3, 60($sp)

la $s0,i
lw $s0,($s0)

li $s2,6
li $s3,7    #limits

mainLoop:
beq $s0, $s2, out

la $s1,j
lw $s1,($s1)

sw $s0,120($sp)
sw $s1,116($sp)


subLoop:
beq $s1, $s3, incrMain

lh $a0,120($sp)
lh $a1,116($sp)

jal foo

la $a0,str
move $a1,$s0
move $a2,$s1
move $a3,$v0

jal printf

addiu $s1, $s1, 1
sw $s1,116($sp)
j subLoop

incrMain:
addiu $s0, $s0, 1
sw $s0,120($sp)
li $v0, 0
j mainLoop


out:

lw $s0, 48($sp)
lw $s1, 52($sp)
lw $s2, 56($sp)
lw $s3, 60($sp)
lw $ra, 124($sp)
addiu $sp, $sp, 128

li $v0, 0
jr $ra
