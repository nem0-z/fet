.rodata
foo_str: .string "foo\n"
bar_str: .string "bar\n"

.text
.globl main
main:

addiu $sp,$sp,-4
sw $ra,($sp)
jal foo
jal bar
lw $ra,($sp)
addiu $sp,$sp,4
jr $ra

foo:
addiu $sp,$sp,-20
sw $ra,16($sp)
la $a0,foo_str
jal printf
jal bar
lw $ra,16($sp)
addiu $sp,$sp,20
jr $ra

bar:
addiu $sp,$sp,-20
sw $ra,16($sp)
la $a0,bar_str
jal printf
lw $ra,16($sp)
addiu $sp,$sp,20
li $v0,0
jr $ra
