.text
.globl foo
foo:

  #$f12 $f14 $a3
  #d1   f1   f2
  
  #odnosno f2 je u $f16

  mtc1 $a3, $f16

  cvt.d.s $f10, $f16

  c.le.d $f12, $f10
  bc1t if2
  
  add.s $f14, $f14, $f2
  cvt.d.s $f14, $f14
  sub.d $f14, $f14, $f12

  li $t0, 3
  mtc1 $t0, $f8
  cvt.d.w $f8, $f8

  div.d $f0, $f14, $f8
  trunc.w.d $f0, $f0
  mtc1 $v0, $f0
  jr $ra

  if2:
  cvt.d.s $f8, $f16
  c.eq.d $f16, $f8

  bc1f if3
  cvt.d.s $f6, $f14
  c.eq.d $f16, $f6

  bc1t if3
  li.d $f4,0.
  c.eq.d $f16, $f4

  bc1t if3
  li.d $f18, 3.
  mul.d $f0, $f18, $f6
  div.d $f0, $f0, $f12

  trunc.w.d $f0, $f0
  mfc1 $v0, $f0
  jr $ra
  
  if3:
  cvt.d.s $f20, $f16
  c.lt.d $f12, $f20

  bc1f else
  cvt.d.s $f20, $f14
  c.eq.d $f20, $f12

  bc1f else
  li.d $f10, 0.
  c.eq.d $f10, $f12
  bc1t else
  cvt.d.s $f20, $f16
  sub.d $f20, $f12, $f20

  abs.d $f20, $f20
  cvt.d.s $f8, $f14
  div.d $f8, $f20, $f8
  
  trunc.w.d $f8, $f8
  mfc1 $v0, $f8
  jr $ra


  else:
  mul.s $f10, $f14, $f16
  li.d $f4, 12.
  mul.d $f4, $f4, $f12
  sub.d $f0, $f10, $f4
  trunc.w.d $f0, $f0
  mfc1 $v0, $f0
  jr $ra

