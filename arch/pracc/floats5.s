.rodata
str: .string "%d"

.text
.globl main
.globl foo

main:
  addiu $sp, $sp, -64
  sw $ra, 60($sp)
  
  
  #0x4016

  li $t0, 0
  li $t1, 0x40160000

  mtc1 $t0, $f12
  mtc1 $t1, $f13

  li $a2, 2
  li $a3, 2

  jal foo
  
  la $a0, str
  move $a1, $v0

  jal printf

  lw $ra, 60($sp)
  addiu $sp, $sp, 64
  li $v0, 0
  jr $ra








foo:

  #int foo(double,int,int);

mtc1 $a2, $f6
mtc1 $a3, $f8

cvt.d.w $f6, $f6
cvt.d.w $f8, $f8

add.d $f6, $f6, $f8
add.d $f0, $f6, $f12

trunc.w.d $f0, $f0
mfc1 $v0, $f0

jr $ra
