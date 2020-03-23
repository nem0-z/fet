.data
size: .byte 7
array: .hword 1,2,7,8,9,11,13
result: .word 0

.text
.globl main
main:

#prepare variables
la $t0,size
lb $t0,($t0)

la $t1,array
la $t8,result

#set counter
li $t2,1 

check:
slt $t3,$t2,$t0
beq $t3,$0,continue #loop condition

lh $t3,($t1)
lh $t4,2($t1)     #check current and next element(to check if sorted)

slt $t5,$t3,$t4   #compare them
beq $t5,$0,not_sorted #gtfo if not sorted

addiu $t2,$t2,1
addiu $t1,$t1,2   #increment counter and adress
j check


not_sorted:
lui $t2,0xdead
ori $t2,$t2,0xfa11
sw $t2,($t8)
j end             #bye

continue:
la $t1,array
sra $t3,$t0,1
sll $t3,1 #hword
addu $t1,$t1,$t3    #prepare address+size/2 (will need in both cases)

#check if size is even or odd
andi $t2,$t0,1
beq $t2,$0,median_even  
sh $t1,($t8)  #in case of odd size, we already have address of median
j end

median_even:
addiu $t1,$t1,-2 #because it will then take arr[size/2-1] and arr[size/2]
lh $t2,($t1)    
lh $t3,2($t1)   #arr[size/2-1] and arr[size/2]
addu $t1,$t2,$t3
sra $t1,$t1,1   #find average of those two
sh $t1,($t8)

end:
li $v0,0
jr $ra
