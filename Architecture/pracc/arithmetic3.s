.section .text
.set noreorder
.globl main
main:
#0xff4589 * 2340 - 0xabcde12 + 0xffffbd3a / 31500

lui $t0,0x00ff
ori $t0,$t0,0x4589 #0xff4589 = 16 729 481
addiu $t1,$0,2340
multu $t0,$t1 #=39 146 985 540
#check $hi and $lo
mflo $t1
mfhi $t2
#no point in considering decimal values after this mult
#hi is just "extending" lo
#add $t1,$t1,$t2 #this should add those 2 and get us our result -> haha yes
#we have to stack hi at the end of lo and that's our result, but that can't
#fit in 32-bit register, ############try this later

#until then -> 0xff4589 * 20 - 0xabcde12 + 0xffffbd3a / 31500
addiu $t1,$0,20
multu $t0,$t1
mflo $t2
lui $t3,0x0abc
ori $t3,$t3,0xde12
subu $t2,$t2,$t3
#addiu $t4,$0,0xbd3a #0xffffbd3a = 4 294 950 202 HAHAHHAHAHA GLUPANE GDJE SI POLETIO S OVIM BROJEM 
lui $t4,0x7fff
ori $t4,$t4,0xbd3a # 0x7fffbd3a = 2 147 466 554
addiu $t5,$0,31500
divu $t4,$t5 #= 68173 + remainder
mflo $t0 #result
mfhi $t1 #remainder 
li $v0,0
jr $ra
