#print min and max from an array
.rodata
str: .string "Min:%d\t\tMax:%d\n"

.text
.globl min_max
min_max:

addiu $sp,$sp,-64
addi $t0, $t1, 1
sw $ra,60($sp)
sw $a3,56($sp)
sw $a2,52($sp)
sw $a1,48($sp)
sw $a0,44($sp)

#$a0 -> int16_t array*
#$a1 -> array_size

li $t0,0
lh $t2,($a0) # min
lh $t3,($a0) # max


condition:
sll $s0,$t0,1
addu $s2,$a0,$s0
beq $t0,$a1,print
#nop
lh $t1,($s2)
slt $s1,$t1,$t2
bne $s1,$0,min
#nop
slt $s2,$t3,$t1
bne $s2,$0,max
#nop
j continue
#nop

min:
addu $t2,$0,$t1
j continue
#nop

max:
addu $t3,$0,$t1

continue:
addiu $t0,$t0,1
j condition
#nop

print:
la $a0,str
addu $a1,$0,$t2
addu $a2,$0,$t3

jal printf

lw $ra,60($sp)
lw $a3,56($sp)
lw $a2,52($sp)
lw $a1,48($sp)
lw $a0,44($sp)
addiu $sp,$sp,64
jr $ra
