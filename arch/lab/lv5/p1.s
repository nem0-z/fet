#funkcija uzima dva argumenta
#pointer na mem lokaciju gdje se nalazi vrijednost koju trebamo stepenovati
#stepen

.rodata
str: .asciiz "Rezultat: %d\n"

.text
#.globl main
#main:

#addiu $sp,$sp,-32
#sw $ra,28($sp)
#addiu $t0, $0, 15
#addiu $t1, $0, 19

#mult $t0, $t1

#mflo $a1
#la $a0, str

#jal printf

#div $t0, $t1

#mflo $a1 #rezultat
#mfhi $a2 #ostatak

#jal printf

#lw $ra,28($sp)
#addiu $v0, $0, 0
#addiu $sp, $sp, 32
#jr $ra


.globl power
power:

addiu $sp,$sp,-32
sw $ra,28($sp)

lw $t0,($a0) 
addu $t2,$0,$t0

li $t1, 1 #prepare counter at 1 because we need exp-1 iterations through loop

loop:
beq $t1,$a1,out
mult $t2,$t0
mflo $t2
addiu $t1,$t1,1
j loop

out:
sw $t2,($a0)
lw $ra,28($sp)
addiu $sp,$sp,32
li $v0,0
jr $ra





