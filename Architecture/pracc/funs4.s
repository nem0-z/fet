.text
.globl foo
foo:

#lw $t0,20($sp)
#mtc1 $t0,$f0
#cvt.d.w $f0,$f0

l.s $f0,20($sp)
#cvt.s.w $f0,$f0

jr $ra
