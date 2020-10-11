.section .data
a: .byte 5
b: .byte 7
.section .bss
c: .hword
.section .text
.globl main
main:
#int t; ->pogledaj dole kod
#t se nije nigdje vracalo iz funkcije 
#kompajler skonto da mu je bolje koristiti registar za to
#ne mora na stack
#uint8_t a = 5;
#uint 8_t b = 7;
#int16_t c;
#main:
#int t;
#if(a == b) t = a;
#else t = b;
#c = (a+b)*2;
#return 0;
la $t0,a
la $t1,b
lbu $t0,($t0)
lbu $t1,($t1)
bne $t0,$t1,else
addiu $t2,$0,$t0
j kraj
else:
addiu $t2,$0,$t1
kraj:
addu $t3,$t0,$t1 
sll $t4,$t3,1
la $t1,c
sh $t4,($t1)
