#given an array of 10 32-bit integers find a sum and the smallest number
#short arr[10] = {5,8,177,39,4,4,10,16,2005,2020,18};
#min = arr[0]; //same as min = *arr;
#for(int i = 0; i<10; ++i)
#{
#  sum+=arr[i];
#  if (arr[i]<min) arr[i] = min;
#}
.data
arr: .word 5,8,177,39,4,10,16,2005,2020,18
sum: .word 0
min: .word 0

.text
.globl main
main:
addiu $sp,$sp,-12
sw $ra,8($sp)


la $t2,arr #load array adress

la $t4,sum
lw $t4,($t4) #prepare sum

lw $t6,($t2) #prepare min -> load first array value

li $t0,0 #set counter
li $t5,4  #increment for sizeof(int) times for counter

check:
slti $t1,$t0,9 #i<10 
#above logic maybe doesn't make sense why <9 but we increment counter at the very end
#so it will go through
beq $t1,$0,out #gtfo if i>=10

addu $t2,$t2,$t5 #add increment onto adress

lw $t3,($t2)  #load arr[i]
addu $t4,$t4,$t3 #sum+=arr[i]

slt $t7,$t3,$t6
beq $t7,0,next #check if min<arr[i], if not then just increment counter
addu $t6,$0,$t3 #new min

next:
addiu $t0,$t0,1
j check

out:
sw $t4,4($sp)
sw $t6,($sp) #store sum and min on stack

lw $ra,8($sp)
addiu $sp,$sp,12
li $v0,0
jr $ra #out
