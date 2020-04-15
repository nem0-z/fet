.text
.globl mymax
mymax:

#double start,  const double* nums, uint32_t size
#$f12           $a2                 $a3

li $t0,0      #my counter

loop:

beq $t0,$a3,out   #counter!=size

l.d $f4,($a2)     #nums[i]
c.le.d $f4,$f12   #nums[i] > start 

#if false just go increment
bc1t incrementing

#else start = nums[i]
mov.d $f12,$f4

incrementing:
addiu $a2,$a2,8
addiu $t0,$t0,1
j loop

out:
mov.d $f0,$f12
jr $ra
