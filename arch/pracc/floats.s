.data
a: .word 5
c: .float 2.5
d: .double 10.25
.globl c

.text
.globl foo
foo:

la $t0,a
la $t1,c

l.s $f4,($t0)
l.s $f8,($t1)

cvt.s.w $f4,$f4

add.s $f4,$f4,$f8

l.s $f6,($a0)

add.s $f4,$f4,$f6

s.s $f4,($a0)

jr $ra

.globl bar
bar:

la $t0,d
l.d $f8,($t0)
#u $a0 je int a, dok je u $a2 i $a3 double b

mtc1 $a0,$f4
mtc1 $a2,$f6
mtc1 $a3,$f7


cvt.d.w $f4, $f4

c.lt.d $f6,$f4

bc1f elseif

add.d $f0,$f4,$f6


sub.d $f0,$f0,$f8
jr $ra

elseif:

c.eq.d $f6,$f4

bc1f else

add.d $f0,$f4,$f6
jr $ra

else:
add.d $f0,$f4,$f6
add.d $f0,$f0,$f8





