.data
a: .word 5
c: .float 2.5
.globl c

.text
.globl foo
foo:
  la $t0, a
  la $t1, c

  l.s $f4, ($t0)

  cvt.s.w $f4, $f4

  l.s $f6, ($t1)

  add.s $f4, $f4, $f6

  l.s $f6, ($a0)

  add.s $f4, $f4, $f6

  s.s $f4, ($a0)

  jr $ra
