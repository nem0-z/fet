#funkcija uzima dva argumenta
#pointer na mem lokaciju gdje se nalazi vrijednost koju trebamo stepenovati
#stepen

.rodata
str: .asciiz "Rezultat: %d\n"

.text
.globl main
main:

addiu $sp,$sp,-32
sw $ra,28($sp)
addiu $t0, $0, 15
addiu $t1, $0, 19

mult $t0, $t1

mflo $a1
la $a0, str

jal printf

#probaj i div lol provjeri i rezultat dijeljenja i ostatak

lw $ra,28($sp)
addiu $v0, $0, 0
addiu $sp, $sp, 32
jr $ra



