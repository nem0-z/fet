.text
.globl main
main:
# load 10100011 in t0, then try resetting, setting, toggling n-th bit
# load 10100011 in t0, try querying n-th bit
li $t0,0xa3
#set 3rd bit
li $t1,1
sll $t1,$t1,2
or $t1,$t0,$t1
#toggle 4th bit
li $t1,1
sll $t1,$t1,3
xor $t1,$t0,$t1
#reset 6th bit
li $t1,1
sll $t1,$t1,5 #100000 -> we have to NOT this in order to get 011111
#we could nor with 0 
nor $t1,$0,$t1 #obviously left side will be filled with 1's
#but we don't care because we will and that anyway with 0's
and $t1,$t1,$t0
#querry 3rd bit -> we don't care what value is in there
#if it's !=0, means that we queried 1 and vice versa
#check with jumping to different labels
li $t1,1
sll $t1,$t1,2
and $t1,$t0,$t1
beq $t1,$0,zero
j one
zero:
#placeholder
li $t2,5
one:
#placeholder
li $t2,6
li $v0,0
jr $ra
