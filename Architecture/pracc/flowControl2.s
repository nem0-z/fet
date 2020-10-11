.bss
f : .word
#be careful with bss
#variables from bss are sent to data and init to 0 during runtime
#thing is bss doesn't contribute as much to final image size
#in this case c will not be set to 0 unless we do it manually
#check more!
.data
a : .word 4
d : .hword -1
c : .byte 0
.text
.globl main
main:
#let i,j,k and A be allocated in memory
#load them in $t0,$t1,$t2 and $t3 respectively
#write following C code in assembly : while (A[i] == k) i+=j;

#body:
#addiu $s0,$t3,4 #this line seems shady, check more!
#lw $s0,($s0)
#bne $s0,$t2,exit
#addu $t0,$t0,$t1
#j body:
#exit:
#nop

#slt
li $t1,10
li $t2,14
slt $t3,$t1,$t2  #we store in $t3 result of asking if $t1<$t2

#slti
slti $t3,$t1,8
slti $t3,$t1,14

#sltu / sltiu -> doesn't account first bit as a sign
#in this case u->unsigned
lui $t4,0xffff
ori $t4,$t4,0xabcd
sltiu $t5,$t4,0x7fff #this immediate on right gets filled to the left with strongest bit
slti $t5,$t4,0x7fff

#do --c ++d while a>d
la $t0,a
lw $t0,($t0)
la $t1,d
lh $t1,($t1)
la $t2,c
lb $t2,($t2)

tijelo:
addiu $t2,$t2,-1
addiu $t1,$t1,1
slt $t3,$t1,$t0
bne $t3,$0,tijelo


li $v0,0
jr $ra
