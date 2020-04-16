.data
str: .string "testiramo: %d\n"

.text
.globl foo
.globl bar

foo:
addiu $sp, $sp, -64
sw $ra, 60($sp)

  li $t0,97
  sb $t0,($a0)

  li $t0,5
  sh $t0,2($a0)

  li $t0,100
  sw $t0,4($a0)

#move $a1,$a0
la $a0,str

jal printf

lw $ra, 60($sp)
addiu $sp, $sp, 64
  jr $ra

bar:
  addiu $sp, $sp, -64
  sw $ra, 60($sp)

  sra $a1,$a0,16
  la $a0,str

  jal printf

  sw $ra, 60($sp)
  addiu $sp, $sp, 64

  jr $ra
  
