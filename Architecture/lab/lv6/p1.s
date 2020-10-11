.text
.globl isPalindrome
isPalindrome:

  slti $t0, $a1, 2
  beq $t0,$0,else

  addiu $v0, $0, 1
  jr $ra

  else:

  lb $t0, ($a0) # s[0] -> t0
  
  addu $t7, $a0, $a1
  lb $t1, -1($t7) #s[len-1] -> t1

  beq $t0, $t1, rekurzija
  
  addiu $v0, $0, 0
  jr $ra

  rekurzija:

  addiu $sp, $sp, -64
  sw $ra, 60($sp)

  addiu $a0, $a0, 1
  addiu $a1, $a1, -2

  jal isPalindrome

  lw $ra, 60($sp)
  addiu $sp, $sp, 64
  jr $ra
