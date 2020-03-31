#profesorov primjer fibonacci

#int fib(int n)
#{
#if ( n < 2 )
#return 1;
#else
#return fib(n-1)+fib(n-2);
#}

#int main()
#{
#fib(6);
#return 0;
#}

.rodata
num: .word 6
str: .string "Rezultat je %d\n"

.text
.globl fib
fib:

slti $t0,$a0,2
beq $t0,$0,racunaj
li $v0,1
jr $ra

racunaj:
addiu $sp,$sp,-16
sw $ra,12($sp)
addiu $a0,$a0,-1
sw $a0,8($sp)
jal fib
sw $v0,4($sp)
lw $a0,8($sp)
addiu $a0,$a0,-1
jal fib
lw $v1,4($sp)
addu $v0,$v0,$v1
lw $ra,12($sp)
addiu $sp,$sp,16
jr $ra

.globl main
main:

addiu $sp,$sp,-256 #i don't even care at this point
sw $ra,252($sp)

la $t0,num
lw $a0,($t0)

jal fib

addu $a1,$0,$v0
la $a0,str

jal printf

lw $ra,252($sp)
addiu $sp,$sp,256
li $v0,0
jr $ra

