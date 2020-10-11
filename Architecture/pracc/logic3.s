#a and b global variables
#if(a==4 || a<3) fun1(b) //set b to 10;
#else if (a!=6 || a>7) fun2(b) // set b to 11;

.data
a: .hword 6
b: .hword 0

.text
.globl main
main:
addiu $sp,$sp,-4
sw $ra,($sp)  #secure $ra 

la $t0,a
lhu $t0,($t0) #load a in $t0

la $t7,b
lhu $t7,($t7) #load b in $t7

li $t5,7
li $t1,4  
li $t2,6  #load temp values for cases
#untidy but i needed for debugging

beq $t0,$t1,fun1 #if(a==4) goto fun1
slti $t3,$t0,3 #else compare a<3
bne $t3,$0,fun1 #if true, goto fun1

#if both cases were false, we go further

bne $t0,$t2,fun2 #if(a!=6) goto fun2
slt $t4,$t5,$t0  #else compare 4<a !(a>4)
bne $t4,$0,fun2 #if true goto fun2

#if both cases were false, we don't do anything and b should be 0

end:
lw $ra,($sp)
addiu $sp,$sp,4 #leave no stack unturned hehe
li $v0,0
jr $ra

fun1:
addu $t7,$0,10
j end 

fun2:
addu $t7,$0,11
j end

