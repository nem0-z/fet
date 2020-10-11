.section .text
.set noreorder
.globl main
main:
#hocemo da triggerujemo onaj cpu exception
lui $t0,0x7fff
ori $t0,$t0,0xffff
#addi $t0,$t0,300
li $v0,0
jr $ra

