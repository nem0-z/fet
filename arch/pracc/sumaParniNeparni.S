.section .data
  niz: .word 0,1,2,3,4,5,6
  sumaParni: .word 0
  sumaNeparni: .word 0
  i: .word 0
.section .text
.globl main
 main: 
  la $t0, i
  lw $s1, ($t0)

  la $t0, sumaParni
  lw $s2, ($t0)

  la $t0, sumaNeparni
  lw $s4, ($t0)

  la $s3, niz #adresa niz[0]
  lw $t1, ($s3) #t0 = niz[0] = 0

  addi $t8, $zero, 7
  j uslov

  paran:
   addu $s2, $s2, $t1

  index: 
   beq $s1, $t8, kraj
   addi $s1, $s1, 1
   sll $t7, $s1, 2
   add $t6, $s3, $t7
   lw $t1, ($t6)
    

  uslov:
    andi $t9, $t1, 1
    beq $t9, $zero, paran
    addu $s4, $s4, $t1
    j index
  kraj:
