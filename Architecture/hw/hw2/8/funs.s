.text
.globl roundtotick
.globl gettick
.globl calcamount

roundtotick:

#$a0 -> double* p
#$a1 -> uint32_t precision

l.d $f4,($a0)
mtc1 $a1, $f6
cvt.d.w $f6, $f6

mul.d $f8,$f4,$f6

trunc.w.d $f8, $f8
cvt.d.w $f8, $f8

div.d $f8, $f8, $f6
s.d $f8,($a0)

jr $ra

gettick:

#$f12 -> num

li.d $f4,0.
li.d $f6,1.
li.d $f8,10.
li.d $f10,100.
mul.d $f18,$f8,$f10

c.eq.d $f12,$f4

bc1f if1
mov.d $f0,$f4
jr $ra

if1:
c.lt.d $f12,$f8

bc1f if2
div.d $f0,$f6,$f18
jr $ra

if2:
c.lt.d $f12,$f10

bc1f if3
div.d $f0,$f6,$f10
jr $ra

if3:
c.lt.d $f12,$f18

bc1f final
div.d $f0,$f6,$f8
jr $ra

final:
mov.d $f0,$f6
jr $ra


calcamount:

#$f12 -> double price $a2 -> int quantity

addiu $sp, $sp, -256
sw $ra, 252($sp)
s.d $f12, 244($sp)

jal gettick

li.d $f8,1
div.d $f8,$f8,$f0   #1/gettick(price)

#preparing to call roundtotick
trunc.w.d $f8,$f8
mfc1 $a1,$f8      #truncation and send it to $a1

addiu $a0,$sp,244 #address of our double

jal roundtotick

#return price*quantity (price is on stack)
l.d $f8, 244($sp)
mtc1 $a2, $f10 
cvt.d.w $f10,$f10

mul.d $f0,$f8,$f10

lw $ra, 252($sp)
addiu $sp, $sp, 256
jr $ra






;
