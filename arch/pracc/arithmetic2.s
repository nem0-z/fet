.section .text
.set noreorder
.globl main

main:
#(204*5)/2 with shifting bits
#addiu $t0,$0,204
#sll $t1,$t0,2
#add $t1,$t1,$t0
#srl $t2,$t1,1

#same as above with mips instructions
li $t0,204
li $t1,0x5
multu $t0,$t1
#mfhi $t2  #higher 32 bits
mflo $t3 #lower 32 bits
#since our mul result doesn't take more than 32 bits
#we will work directly with $lo -> well that worked out xD
# $lo and $t3 have same values now, but you can't work with $lo directly
#note that after mflo and mfhi, lo and hi don't get reset
addiu $t2,$0,2
div $t3,$t2
mflo $t0
li $v0,0
jr $ra
