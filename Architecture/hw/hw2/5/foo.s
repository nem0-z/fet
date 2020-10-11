.text
.globl foo
foo:

#d1  f1  f2
#f12 f14 a3

mtc1 $a3,$f8    #move f2 to $f8

cvt.d.s $f14,$f14 #moje f1
cvt.d.s $f8, $f8  #moje f2 ko biva
                  #d1 je vec u double i to u $f12
c.le.d $f12, $f8
bc1t else

add.d $f2,$f14,$f8
sub.d $f2,$f2,$f12

li.d $f4,3

div.d $f0,$f2,$f4
cvt.w.d $f0,$f0

mfc1 $v0,$f0
jr $ra

else:

c.eq.d $f12,$f8
bc1f elseif
c.eq.d $f12,$f14
bc1t elseif
li.d  $f6,0.
c.eq.d $f14,$f6
bc1t elseif

li.d $f6,3.
mul.d $f0,$f14,$f6
div.d $f0,$f0,$f12
cvt.w.d $f0,$f0

mfc1 $v0,$f0
jr $ra

elseif:

c.lt.d $f12,$f8
bc1f out
c.eq.d $f12,$f14
bc1f out
li.d $f6,0.
c.eq.d $f14,$f6
bc1t out

sub.s $f0,$f12,$f8
abs.s $f0,$f0
div.s $f0,$f0,$f14

cvt.w.d $f0,$f0
mfc1 $v0,$f0
jr $ra

out:
li.d $f6,12.
mul.s $f8,$f14,$f8
mul.s $f12,$f12,$f6
sub.s $f0, $f8, $f12

cvt.w.d $f0,$f0
mfc1 $v0,$f0
jr $ra


