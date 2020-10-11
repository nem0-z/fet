.text
.globl bar
bar:

#f1  #f2  #d1
#f12 #f14 #a2-a3

mtc1 $a2,$f6
mtc1 $a3,$f7

c.lt.s $f12,$f14
bc1f elseif

li.s $f8,2.     #probaj bez tacke
ceil.w.s $f12,$f12
cvt.s.w $f12,$f12

mul.s $f8,$f8,$f12

round.w.s $f14,$f14
cvt.s.w $f14,$f14

sub.s $f8,$f8,$f14

trunc.w.d $f6,$f6
cvt.s.w $f6,$f6

add.s $f0,$f8,$f6
jr $ra

elseif:
c.eq.s $f12,$f14
bc1f out

ceil.w.s $f12,$f12
cvt.s.w $f12,$f12

floor.w.s $f14,$f14
cvt.s.w $f14,$f14

sub.s $f12,$f12,$f14

trunc.w.d $f6,$f6
cvt.s.w $f6,$f6

add.s $f0,$f12,$f6
jr $ra

out:
cvt.s.d $f0,$f6
jr $ra
