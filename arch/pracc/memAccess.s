.data
a: .word 5
b: .hword 3
.text
.globl main
main:
la $t0,a
addiu $t2,$0,456
li $v0,0
jr $ra
#ok fk this for now
