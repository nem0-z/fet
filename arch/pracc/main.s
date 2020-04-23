.rodata
str: .string "%f"
.text
.globl main
main:
  
  addiu $sp, $sp, -64
  sw $ra, 60($sp)

  #0x405B A000 0000 0000 je 110.5
  #0000 0000 000A B504 je onako kako ga on vidi

  li $t1,0x405ba000
  li $t0,0

  mtc1 $t0,$f12
  mtc1 $t1,$f13

  jal foo

  la $a0, str
  
  mfc1 $a2, $f0
  mfc1 $a3, $f1

  jal printf

  lw $ra, 60($sp)
  addiu $sp, $sp, 64
  li $v0, 0
  jr $ra

.globl foo
foo:

  mov.d $f0, $f12

  jr $ra
