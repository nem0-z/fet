.text
.globl foo
foo:

  # $f12 -> a, $a1 -> b

mtc1 $a1, $f4
cvt.s.w $f4, $f4

c.lt.s $f12, $f4
cvt.d.s $f12, $f12 
cvt.d.s $f4, $f4
bc1f else
add.d $f0, $f12, $f4
jr $ra

else:
sub.d $f0, $f12, $f4
jr $ra

