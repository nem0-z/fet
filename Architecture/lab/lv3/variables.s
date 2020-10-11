.section .data
a: .byte 25 #uint8_t a = 25
b: .byte -2 #int8_t b = -2
#.space numberOfBytes
c: .byte -10
d: .hword 40000
x: .word 3400
y: .word 2800
.section .bss
f: .word
g: .hword
h: .hword
i: .word
z: .word
.globl a
.globl b
.globl c
.globl d
.globl x
.globl y
.globl f
.globl g
.globl h
.globl i
.globl z
.section .text
.globl main
main:
la $t0,a #pseudo instrukcija neka, ucitaj adresu od a u t0 registar
lbu $t0,($t0) #zato jer upisujemo unsigned broj, hocemo da ostatak lijevo popuni nulama
#inace bi najjacim bitom popunio
addiu $t0,$t0,190
la $t1,f
sw $t0,($t1) #sw jer je f(na adresi iz $t1) unsigned int od 4 bajta
la $t0,b
lb $t1,($t0)
addiu $t0,$0,12
sub $t1,$t1,$t0
la $t2,g
sh $t1,($t2)
la $t0,c
lb $t0,($t0)
addiu $t0,$t0,15
la $t1,h
sh $t0,($t1)
la $t3,x
la $t4,y
la $t5,z
lw $t3,($t3)
lw $t4,($t4)
addu $t0,$t3,$t4
sw $t0,($t5)
li $v0,0
jr $ra

