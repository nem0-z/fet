.data
d: .double 6.28

.text
.globl foo
foo:
# pointer na double x u $a0, int n u $a1
l.d $f4, ($a0)
mtc1 $a1, $f6
cvt.d.w $f6, $f6

la $t0, d
l.d $f8, ($t0)

c.le.d $f4, $f6
bc1f else

add.d $f4, $f4, $f8
s.d $f4, ($a0)
l.d $f4, ($a0)   #save on stack 

li.s $f10, 3.
cvt.d.s $f10, $f10

mul.d $f0, $f4, $f10
cvt.s.d $f0, $f0
jr $ra

else:
sub.d $f4, $f4, $f8
s.d $f4, ($a0)
l.d $f4, ($a0)    #same

sub.d $f0, $f4, $f6
cvt.s.d $f0, $f0
jr $ra
