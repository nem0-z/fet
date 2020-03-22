.rodata
number: .word 21

.data
result: .byte 0

.text
.globl main
main:

la $t0,number
lw $t0,($t0)

la $t1,result

andi $t0,$t0,1

sb $t0,($t1) #1-odd, 0-even

li $v0,0
jr $ra



