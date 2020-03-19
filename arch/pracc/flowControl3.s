#check flowControl3.c
.rodata
str: .string "i je %d\n"

.text
.globl main
main:
  addiu $sp, $sp, -28
  sw $ra, 20($sp)
  sw $0, 16($sp)

  lw $t0, 16($sp)
  j next1
  addiu $t0, $t0, 1

next1:
addiu $t0, $t0, 100

next2:
addiu $t0, $t0, 10
addiu $t0, $t0, 15
la $a0, str
addu $a1, $0, $t0
jal printf

  lw $ra, 20($sp)
  addiu $sp, $sp, 28
  jr $ra
  
