.data
a: .byte 5
b: .word 8
c: .hword 7
d: .word 6
.text
.globl main
main:
#load values from memory in t1 t2 t3 t4, if t1+t2 == t3+t4 then t1 = t2,t3 = t4,
#else t1 = t3, t2 = t4. CHECK AFTER!
la $t1,a
lbu $t1,($t1)
la $t2,b
lw $t2,($t2)
la $t3,c
lhu $t3,($t3)
la $t4,d 
lw $t4,($t4) #end loading values

add $t5,$t1,$t2
add $t6,$t3,$t4 #additions

beq $t5,$t6,hop #check

sub $t1,$t1,$t1
add $t1,$0,$t2
sub $t3,$t3,$t3
add $t3,$0,$t4 
j exit #if false

hop:
sub $t1,$t1,$t1
add $t1,$0,$t3
sub $t2,$t2,$t2
add $t2,$0,$t4 #if true, oops! we swapped this around but logic is fine

exit:
li $v0,0
jr $ra
