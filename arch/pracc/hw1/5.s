.rodata
str: .string "rotor"
palindrome_string: .string "Ova rijec je palindrom!"
not_palindrome_string: .string "Ova rijec nije palindrom!"
result: .byte 0

.text
.globl main
main:

addiu $sp,$sp,-20
sw $ra,16($sp)

la $t0,str
la $t8,result
li $t1,0  #we will save string size here
# we count from 1 so we save here size-1 value
#because we want to jump to last character in string

#ok forget about that 

get_size:
lb $t2,($t0)
beq $t2,$0,out
addiu $t0,$t0,1
addiu $t1,$t1,1
j get_size

out:
la $t0,str
addu $t4,$t0,$t1 #get the address of last
addiu $t4,$t4,-1 #go back 1 step cuz of '\0'
sra $t1,1 #size/2
li $t5,0 #new counter that will go 0-size/2 in case all chars are same


palindrome:
beq $t5,$t1,is_palindrome
lb $t2,($t0)
lb $t3,($t4)
bne $t2,$t3,not_palindrome
addiu $t0,$t0,1
addiu $t4,$t4,-1
addiu $t5,$t5,1
j palindrome

not_palindrome:
li $t0,0
j final

is_palindrome:
li $t0,1

final:
beq $t0,$0,nprint
la $a0,palindrome_string
j print

nprint:
la $a0,not_palindrome_string

print:
jal printf

sb $t0,($t8)

lw $ra,16($sp)
addiu $sp,$sp,20
li $v0,0
jr $ra


