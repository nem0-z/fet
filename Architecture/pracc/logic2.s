.text
.globl main
main:
li $t0,0x3a3b
sll $t0,$t0,5

addi $t1,$0,0xffff
sll $t1,$t1,3

li $t2,0x7b2
srl $t2,$t2,7

li $t2,0x7b2
sra $t2,$t2,7

lui $t3,0x9c2d
sra $t4,$t3,4
srl $t5,$t3,4

li $v0,0
jr $ra
