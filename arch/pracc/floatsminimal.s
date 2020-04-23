.text
.globl foo
foo:
  
  l.d $f4, ($a0)
  l.s $f6, ($a1)

  cvt.d.s $f6, $f6

  add.d $f0, $f4, $f6
  cvt.s.d $f0, $f0

  jr $ra
