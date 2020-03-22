.data
number: .word 45
result: .word 0

.text
.globl main
main:

la $t0,number
la $t1,result

lw $t0,($t0)

#1. check if even or odd
#andi $t0,$t0,1
#sw $t0,($t1)

#2. numberx22
#sll $t2,$t0,4
#sll $t3,$t0,2
#sll $t4,$t0,1
#addu $t2,$t2,$t3
#addu $t2,$t2,$t4
#sw $t2,($t1)

#3. numberx7
#sll $t2,$t0,2
#sll $t3,$t0,1
#addu $t2,$t2,$t3
#addu $t2,$t2,$t0
#sw $t2,($t1)

#4. number%8
#andi $t2,$t0,7
#sw $t2,($t1)


#5. number%32
#andi $t2,$t0,31
#sw $t2,($t1)





li $v0,0
jr $ra

