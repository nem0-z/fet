#Data je funkcija f(x)={ 0, za x <4; 2x-6 za x>=4}, x je cijeli broj. Izračunati vrijednost funkcije
#za 10 elemenata niza brojevi i rezultate smještati u niz rezultat.
#Rješenje:
#Realizovati bez korištenja stacka jer je ovo zadnja (leaf) funkcija u lancu pozivanja.

.data
brojevi: .word 2, 4, 8, 9, 5, 1, 4, 2, 5, 7
rezultat: .space 40

.text
.globl main
main:

addu $t8,$0,$ra #keep $ra safe hehe
la $s0,brojevi
la $s1,rezultat


li $t0,0
li $t1,10   #setup counter


check:
beq $t0,$t1,out
sll $t0,$t0,2
addu $s0,$s0,$t0
addu $s1,$s1,$t0
lw $a0,($s0)
jal f_rezultat
sw $v0,($s1)
addiu $t0,$t0,1
j check

out:
addu $ra,$0,$t8
li $v0,0
jr $ra

.globl f_rezultat
f_rezultat:

addu $t6,$0,$ra #keep $ra safe hehe
slti $t5,$a0,4
beq $t5,$0,double

li $v0,0
j end

double:
sll $a0,$a0,1
addu $v0,$0,$a0

end:
addu $ra,$0,$t6
jr $ra  #YOLO
