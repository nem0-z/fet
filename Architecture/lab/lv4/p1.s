#Dat je proizvoljan niz od 10 16-bitnih brojeva. sabrati sve elemente niza it1,
#rezultat smjestiti na lokaciju suma. najmanji element smjesti na lokaciju
#najmanji

#const int16_t niz[10] = {12, 3, -9, 1200, -2400, 490, 800, -23, 5, 22};
#int suma;
#int16_t najmanji;

.rodata
niz: .hword 12, 3, -9, 1200, -2400, 490, 800, -23, 5, 22 #u .rodata jer je const niz

.data
suma: .word 0
najmanji: .hword -1

.text
.globl main
main:
  addiu $t0, $0, 0  #t0 -> i (counter)
  addiu $t2, $0, 0  #t2 -> suma
  
  la $t7, niz

  lh $t8,($t7) #ucitavamo prvi iz niza -> min = niz[0]
  
uslov:
  sltiu $t1, $t0, 10 # i<10
  beq $t1, $0, kraj #if i==10 goto kraj
  
  sll $t4, $t0, 1 #kao inkrementiramo brojac, ali ustvari ga povecavamo
  #za velicinu svakog elementa u prvoj iteraciji = 0 
  addu $t4,$t4,$t7

  lh $t3, ($t4)   #dohvatanje elementa
  addu $t2, $t2, $t3  #suma

  slt $t5, $t3, $t8
  beq $t5,$0,next
  addu $t8, $0, $t3

next:
  addiu $t0, $t0, 1 #inkrementiranje brojaca

  j uslov

#x - examine
#x/2h(format opciono) $t1 citaj mi 2 half worda sa $t1
#x/2i $pc citaj mi 2 instrukcije iz $pc

kraj:
la $t1, suma
la $t3, najmanji
sw $t2, ($t1)
sh $t8, ($t3)

li $v0,0
jr $ra
