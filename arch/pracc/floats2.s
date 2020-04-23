#HUGE FAIL
.text
.globl bar
bar:
  
  # $f12 -> f1 $f14 -> f2 $a2 i $a3 -> d1

  mtc1 $a2, $f8
  mtc1 $a3, $f9

  c.lt.s $f12, $f14
  bc1f elseif

  li.s $f4,2.
  ceil.w.s $f1,$f1
  cvt.s.w $f1, $f1

  mul.s $f0, $f1, $f4

  round.w.s $f14, $f14
  trunc.w.d $f8, $f8
  add.w $f8, $f14, $f8
  cvt.s.w $f8, $f8

  sub.s $f0, $f0, $f8
  jr $ra

  elseif:

  c.eq.s $f12, $f14
  bc1f out
  ceil.w.s $f12, $f12
  floor.w.s $f14, $f14
  trunc.w.s $f8, $f8

  sub.w $f12, $f12, $f14
  add.w $f0, $f12, $f8
  cvt.s.w $f0, $f0
  jr $ra

  out:
  cvt.s.d $f0, $f8
  jr $ra



