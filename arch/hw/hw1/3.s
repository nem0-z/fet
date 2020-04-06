.text
.globl main
main:

addiu $t0,$0,-1

lui $t1,0x77ff
ori $t1,$t1,0xbffe  

and $v0,$t0,$t3

jr $ra
