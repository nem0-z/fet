.section .text
.set noreorder
.globl main
#(40+5-3)+(50|34)
#rezultat je 126 odnosno hex 0x7e
main:
addiu $t0,$zero,40
addu $t0,$t0,5
addiu $t0,$t0,-3
addiu $t1,$zero,50
addiu $t1,$t1,34
add $t1,$t1,$t0
#t1 - 40 + 30 | 20
#rezultat je 116 odnosno hex 0x74
addiu $t1,$t1,-40
addiu $t2,$zero,1
ori $t4,$t2,6
add $t3,$t1,$t4
#ucitaj neki broj tipa 0xff4a4c1
#addiu $t0,$zero,0xff4a4c1 #try this
lui $t0,0x0ff4
ori $t0,$t0,0xa4c1
li $v0,0
jr $ra





