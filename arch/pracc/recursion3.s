.data
dummy: .byte 0

.text
.globl isPalindrome
isPalindrome:

#$a0 -> pointer na niz
#$a1 -> duzina niza

slti $t0, $a1, 2
bne $t0,$0,ret1

addu $t8,$a0,$a1
addiu $t8,$t8,-1    #len-1

lbu $t0,($a0)   #s[0] 
lbu $t1,($t8)   #s[len-1]

bne $t0,$t1,nije_pal

addiu $sp,$sp,-32
sw $ra,28($sp)

addiu $a0,$a0,1
addiu $a1,$a1,-2

jal isPalindrome

lw $ra,28($sp)
addiu $sp,$sp,32
jr $ra

ret1:
li $v0, 1
jr $ra

nije_pal:
li $v0, 0
jr $ra


.globl partition

partition:
#$a0 -> pointer na niz, $a1 -> duzina niza, $a2 -> predicate
#proslijedjujemo niz, niz+size-1 i predicate
addiu $sp,$sp,-32
sw $ra,28($sp)

sll $t1,$a1,2
addu $a1,$a0,$t1
addiu $a1,$a1,-4
jal partition_impl

lw $ra,28($sp)
addiu $sp,$sp,32
jr $ra


partition_impl:

bne $a0,$a1,continue
jr $ra

continue:
addiu $sp,$sp,-64
sw $ra,60($sp)
sw $a0,56($sp)
sw $a1,52($sp)
sw $a2,48($sp)

lw $a0,($a0)
lw $a2,48($sp)

jalr $a2


beq $v0,$0,else

lw $a0,56($sp)
lw $a1,52($sp)

jal swap

lw $a1,52($sp)
addiu $a1,$a1,-4
sw $a1,52($sp)

j rekurzija

else:

lw $a0,56($sp)
addiu $a0,$a0,4
sw $a0,56($sp)

rekurzija:
lw $a0,56($sp)
lw $a1,52($sp)
lw $a2,48($sp)

jal partition_impl

lw $ra,60($sp)
addiu $sp,$sp,64
jr $ra


.globl fib
fib:

#$a0 -> n

slti $t0, $a0, 2
beq $t0,$0,else

li $v0,1
jr $ra

else:
addiu $sp, $sp, -64
sw $ra, 60($sp)

addiu $a0, $a0, -1
sw $a0, 56($sp)

jal fib

sw $v0, 52($sp)
lw $a0, 56($sp)

addiu $a0, $a0, -1

jal fib

lw $t0, 52($sp)
addu $v0, $v0, $t0
jr $ra


lw $ra,60($sp)
addiu $sp, $sp, 64
jr $ra
