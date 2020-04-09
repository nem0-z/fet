.rodata
str: .asciiz "p=%f\n"

.text
.globl main
main:
#10.2 raspisi u IEEE 754 aritmetici i ucitaj sa lui i ori obv jer je 32 bita
#10.2 = 0x41233333
  addiu $sp, $sp, -64
  sw $ra, 60($sp)

  lui $t0, 0x4123
  ori $t0, $t0, 0x3333      #p = 10.2

  sw $t0, 56($sp)
  
  addiu $a0, $sp, 56        #u $a0 je adresa naseg broja za foo(&p)

  jal foo

  la $a0, str

  lwc1 $f4, 56($sp)     #pocinjemo pretvarati float u double

  cvt.d.s $f4, $f4      #pretvaramo float u double
                        #nakon ovoga nas double je u $f4 i $f5
                        #sad ga moramo vratiti u $a2 i $a3 jer 
                        #tu proslijedjujemo arg po konvenciji

  mfc1 $a2, $f4         #priprema argumenata za printf
  mfc1 $a3, $f5         #moze i mfhc1 $a3, $f4 
                        #on ce skontat da uzme iz f4 + 8b 
                        #uzme taj kao drugi dio broja

  jal printf
  
  lw $ra, 60($sp)
  addiu $sp, $sp, 64
  li $v0, 0
  jr $ra

