.rodata
nums: .double 200.12, -1.0, 5.7, 9.4, 0.148, 7.1, 8.2, 10.5, 13.9, -2.5, 200.11
string: .string "MyMax: %f\n"

.text
.globl main
main:

addiu $sp, $sp, -256
sw $ra, 252($sp)

la $a2, nums

#double start,  const double* nums, uint32_t size
#$f12           $a2                 $a3

l.d $f12,($a2)
addiu $a3, $0, 10

jal mymax

mfc1 $a2,$f0
mfc1 $a3,$f1

la $a0,string

jal printf

lw $ra, 252($sp)
addiu $sp, $sp, 256
jr $ra



