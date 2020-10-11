.text
.global baz
baz:

#f12 a1  a2  a3
#f1  *p1 f2  n

l.d $f4, ($a1)
mtc1 $a2, $f6
mtc1 $a3, $f8

#presjek stanja na putevima
#f1 je u f12
#p1 je u f4
#f2 je u f6
#n je u f8


li.d $f16,0.
c.eq.d $f4,$f16
cvt.s.w $f8,$f8
bc1t justDoIt

add.s $f10,$f12,$f6

c.lt.s $f10,$f8
bc1f else

justDoIt:
mul.s $f20,$f6,$f8
add.s $f0,$f12,$f20
cvt.d.s $f0,$f0
jr $ra

else:
c.eq.d $f4,$f16
bc1t out

mul.s $f20,$f6,$f8
sub.s $f20,$f12,$f20
cvt.d.s $f20,$f20
div.d $f0,$f20,$f4
jr $ra

out:
cvt.d.s $f12,$f12
cvt.d.s $f6,$f6
cvt.d.s $f8,$f8

mul.s $f0,$f12,$f4
add.s $f0,$f0,$f8
add.s $f0,$f0,$f6
jr $ra
