.data
d: .double 10.25

.text
.globl foo
foo:
  mtc1 $a2, $f4         #f4 -> b
  mtc1 $a3, $f5

  mtc1 $a0, $f6         #f6 -> a

  cvt.d.w $f6, $f6      #f6 -> a konverzija u double
  
  c.lt.d $f4, $f6       #if b<a
  
  bc1f elseif             #ukoliko je rezultat poredjenja false, goto elseif
  
  add.d $f0, $f4, $f6

  la $t0, d               #ucitaj adresu od d
  l.d $f8, ($t0)          #ucitaj double d sa adrese

  sub.d $f0, $f0, $f8

  jr $ra

  elseif:

  c.eq.d $f4, $f6         #if b==a

  bc1f else
  
  add.d $f0, $f4, $f6

  jr $ra

  else:

  la $t0, d
  l.d $f8, ($t0)

  add.d $f0, $f4, $f6
  add.d $f0, $f0, $f8

  jr $ra


