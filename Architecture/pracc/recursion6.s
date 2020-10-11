
#int sum(int a, int b){
#  if(b==0) return a;
#  else return sum(a+1,b-1);
#}

.text
.globl sum
sum:

beq $a1, $0, a

addiu $sp, $sp, -16
sw $ra, 12($sp)
addiu $a0, $a0, 1
addiu $a1, $a1, -1

jal sum

lw $ra, 12($sp)
addiu $sp, $sp, 16
jr $ra

a:
move $v0, $a0
jr $ra

