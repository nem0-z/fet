.text
.globl rekurzija
rekurzija:

addiu $sp,$sp,-512 #i will take as much as I want fk off
sw $ra,508($sp)

#short rekurzija(short a, short b){
#if( a < 1 ) return 0;
#else if(b < 2) return 0;
#return a + b + rekurzija(a-1, b-2);
#}

slti $t0,$a0,1
bne $t0,$0,zero

slti $t0,$a1,2
bne $t0,$0,zero

sh $a0,506($sp)
sh $a1,504($sp)

addiu $a0,$a0,-1
addiu $a1,$a1,-2

jal rekurzija

lhu $a0,506($sp)
lhu $a1,504($sp)
addu $a0,$a0,$a1
addu $v0,$a0,$v0
j end

zero:
li $v0,0

end:
lw $ra,508($sp)
addiu $sp,$sp,512
jr $ra
