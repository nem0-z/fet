
#void foo(float x,double* pd,double d)
#{
#  // $f12 -> x, $a1 -> *pd, $a2$a3 -> d
#  int y = 4;
#  y = y + 2.f * x - d;
#  *pd = y;
#}
.rodata
str: .string "%f"

.text
.globl main
main:

  #double x = 932.99;
  #foo(46.8,&x,2.5);
  #printf("%f",x);
  #return 0;
addiu $sp, $sp, -64
sw $ra, 60($sp)
#0x408D27EB 851EB852
li $t0, 0x851eb852
li $t1, 0x408d27eb

sw $t0, 52($sp)
sw $t1, 56($sp)

#46.8
#0x423B3333

li $t2, 0x423b3333
mtc1 $t2, $f12

addi $a1, $sp, 52

#0x4004000000000000

li $a2, 0
li $a3, 0x40040000

jal foo

la $a0, str
lw $a2, 52($sp)
lw $a3, 56($sp)

jal printf

lw $ra, 60($sp)
addiu $sp, $sp, 64
li $v0, 0
jr $ra

.globl foo
foo:

addi $t0, $0, 4

addi $t1, $0, 2
mtc1 $t1, $f6
cvt.s.w $f6, $f6

mul.s $f8, $f12, $f6

mtc1 $t0, $f4
cvt.s.w $f4, $f4

add.s $f4, $f4, $f8
cvt.d.s $f4, $f4

mtc1 $a2, $f10
mtc1 $a3, $f11

sub.d $f4, $f4, $f10
trunc.w.d $f4, $f4
cvt.d.w $f4, $f4
s.d $f4, ($a1)

jr $ra
