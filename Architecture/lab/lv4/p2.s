#napisati program koji pretvara null terminirani string sa mem lokacije
#str tako da mala slova transformise u velika

#rezultat smjesta na memorijsku lokaciju res

.rodata
str: .asciiz "abCdEfgzh ?"

.data
res: .space 40 #zauzeli 40 bajta za nas char res[40];
#npr za int niz[50] islo bi niz: .space 200 (50*4)

.text
.globl main
main:
  la $t0, str       # s-> t0
  addiu $t1, $0, 0  # i-> t1
  la $t7, res
  
uslov:
  lb $t2,($t0)    #ucitaj s, to je kao da dereferenciras pointer (*s)
  beq $t2, $0, kraj #ako je s == null karakter, skoci na kraj
  
  slti $t3, $t2, 97
  bne $t3, $0, nijeMaloSlovo

  slti $t3, $t2, 123
  beq $t3, $0, nijeMaloSlovo

  addiu $t2, $t2, -32

nijeMaloSlovo:
  
  addu $t8, $t7, $t1
  sb $t2, ($t8)

  addiu $t1, $t1, 1
  addiu $t0, $t0, 1
  j uslov

#provjerio res u debuggeru sa x/10c &res 
#res je lokacija a 10 je broj karaktera koliko hocemo da ispise

kraj:
  li $v0,0
  jr $ra
