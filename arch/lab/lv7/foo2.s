.data
a: .word 5

.text
.globl foo
foo:
  mtc1 $a2, $f6
  mtc1 $a3, $f7   #u $a2 i $a3 je proslijedjen nas double f

  la $t0, a
  
  l.s $f4, ($t0)

  cvt.d.w $f4, $f4

  add.d $f4, $f4, $f6

  l.d $f6, ($a0)

  add.d $f4, $f4, $f6

  s.d $f4, ($a0)

  jr $ra
