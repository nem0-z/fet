.text
.globl main
.globl fun
main:
addiu $sp,$sp,-21
sw $sp,17($sp)
sw $ra,13($sp)
li $t0,4
sw $t0,9($sp)
li $t0,7
sb $t0,8($sp)   #storing stuff on stack

lw $a0,9($sp)
lb $a1,8($sp)   #load function arguments

jal fun         #call

sw $v0,4($sp)   #store return-value on stack

lb $a0,8($sp)
lw $a1,9($sp)   #load function arguments

jal fun       #call

sw $v0,($sp)    #store return-value on stack

lw $sp,17($sp)
lw $ra,13($sp)
addiu $sp,$sp,21  #"leave no stack unturned" :PPPP
jr $ra        

fun:
ori $t0,$a0,2
addi $t1,$t1,0xfffe
and $t1,$a1,$t1
mult $t0,$t1
mflo $t1
addu $t1,$t0,$t1
addu $v0,$0,$t1
li $v0,0
jr $ra
