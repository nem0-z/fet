#napisati funkciju myabs koja uzima dva argumenta:
#1.adresa na koju ce smjestiti rezultat
#2.broj koji treba transformirati u njegovu aps vrijednost
#i rezultat snimiti na adresu na koju pokazuje prvi arg
.rodata
mystr : .asciiz "Abs: %d\n"

.text
.globl myabs
myabs:

  #hocemo da pozovemo printf
  #po konvenciji funkcija moze da koristi 16 nasih bajta
  #znaci uvijek zauzimamo koliko nam treba bajta+16

  addiu $sp, $sp, -20 #treba nam 4 bajta za pointer na mystr + 16 bajta
  sw $ra, 16($sp) #sacuvali $ra na steku
  
  slti $t0, $a1, 0
  beq $t0, $0, kraj
  neg $a1, $a1 #negiraj $a1
kraj:
  sw $a1, ($a0)
  
  la $a0, mystr
  
  jal printf

  #printf("abs: %d\n", 5);
  
  #sad vracamo $ra i $sp na pocetno
  lw $ra,16($sp)
  addiu $sp, $sp, 20
  jr $ra
