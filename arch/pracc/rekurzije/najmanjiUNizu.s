.text
.globl najmanji
najmanji:

#u $a0 niz*, u $a1 nizSize

addiu $sp, $sp, -256
sw $ra, 252($sp)

li $t0,1 #za provjeru
beq $a1, $t0, glupan  #if velicina(reducirana) == 1 vrati niz[0] tj glupan

sw $a0, 248($sp)
; sw $a1, 244($sp)

addiu $a0, $a0, 4   #niz+1
addiu $a1, $a1, -1  #velicina-1

jal najmanji        #u $v0 je min_os


lw $a0, 248($sp)    #vrati adresu od prvog u nizu

lw $t8, ($a0)       #ucitaj prvi u nizu u $t8

slt $t2, $v0, $t8    #min_os < niz[0] i spremi u $t0
beq $t2, $0, glupan   

j finale


glupan:
lw $v0, ($a0)

finale:
lw $ra, 252($sp)
addiu $sp, $sp, 256
jr $ra

