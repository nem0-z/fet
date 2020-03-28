#faktorijel proslijedjenog argumenta i vrati ga 

#def function = factoriel(num)
#if num<2
# return 1;
#else
# return num*factoriel(num-1)
#end

.text
.globl factoriel
factoriel:
  slti $t0,$a0,2
  beq $t0, $0, racunaj
  li $v0, 0
  jr $ra

  racunaj:
  
  addiu $sp, $sp, -64
  sw $ra, 60($sp)
  sw $a0, 56($sp)

  addiu $a0,$a0,-1
  jal factoriel
  #rez u $v0
  
  lw $a0,56($sp) #vracamo $a0 posto smo ga mijenjali

  mult $a0,$v0
  mflo $v0

  lw $ra,60($sp)
  addiu $sp, $sp, 64
  jr $ra

