.data
a: .hword 10
b: .hword 4

.text
.globl main
.globl exchange


exchange:
lh $s0,($a0)
sh $a1,($a0)
addu $v0,$0,$t0
jr $ra

main:
addiu $sp,$sp,-20
sw $ra,16($sp)

la $a0,a
la $a1,b
lh $a1,($a1)
jal exchange

end: # bpoint for debugging
lw $ra,16($sp)
addiu $sp,$sp,20
li $v0,0
jr $ra

