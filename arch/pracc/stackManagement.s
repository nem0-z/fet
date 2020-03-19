# main-> int a = 4; short b; 

#.data
#x : .byte 0xfff #we don't worry, compiler will recognise error here

.rodata
mystr1: .asciiz "a = %d\n"
mystr2: .asciiz "b = %d\n"

.text
.globl main
main:

  addiu $sp, $sp, -30      #move stack 14 bytes down(int + short + 2*char*)
  sw $ra, 26($sp)         #push ra on stack

  li $t0, 4               #load 4 in temp reg
  sw $t0, 22($sp)         #4 bytes up are filled with word from $t0
  
  lw $t2,22($sp)
  lhu $t3,20($sp)     #load values from stack in $t2 and $t3, respectively

  la $a0, mystr1
  addu $a1,$0,$t2
  jal printf          #

  la $a0, mystr2
  addu $a1,$0,$t3
  jal printf          #basic printf calls

  lw $ra, 22($sp)
  addiu $sp, $sp, 26
  jr $ra              #end of function

  

  


