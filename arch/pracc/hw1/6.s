.data
a: .hword 10
b: .hword 4

.text
.globl main
.globl exchange

main:
addiu $sp,$sp,-4
sw $ra,($sp)

la $a0,a
la $a1,b
lh $a1,($a1)
jal exchange

end: # bpoint for debugging
lw $ra,($sp)
addiu $sp,$sp,4
li $v0,0
jr $ra

exchange:
lh $t0,($a0)
sh $a1,($a0)
addu $v0,$0,$t0
jr $ra
