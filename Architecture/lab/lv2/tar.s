.section .text
.set noreorder
.globl main
main:
#saberi 0xFFFFFF00 + 40000 + 100
addiu $t0,$zero,0xF000
ori $t1,$zero,0xFFFF #najveci broj koji sa addi mos strpat je 0x7FFF (raspisi ovo sebi binarno i hex)
#hocemo da saberemo 0xFFFFFF00+40000+100 kao unsigned (ono prvo F necemo uzimat kao predznak)
#fazon je kako ucitat ovaj prvi
#lui - load upper immediate, ucitaj najjacih 16 bita
lui $t2,0xFFFF 
ori $t2,$t2,0xFF00 #ili vrijednosti iz t2 sa konstantom(u nasem slucaju ostatkom broja) i smjestanje u t2 
addiu $t3,$zero,0xFF00 #on vidi najjaci bit i popuni ostatak registra s tim najjacim bitom jer add radi signed-> ekvivalent ove 2 instrukcije iznad
#'u' u addiu nema veze sa unsigned
ori $t4,$zero,40000
#morali smo ovde ori jer je njegov max 2^16-1 a max od addi je 2^15-1 radi onog bita predznaka (worst case scenario)
addiu $t5,$zero,100
add $t3,$t3,$t4
add $t3,$t3,$t5
lui $t6,0x7FFF
ori $t6,$t6,0xFFF0
addi $t6,$t6,20
#probaj ovo kompajlat; kad smo ovo gore sabrali, 
#profulali smo tj overflow napravili i on se prepo jer smo mu otjerali predznak i CPU bacio exception (frame exception, u MMU ispod CPU)
# C radi sa 'u' uvijek, da ne bi tog exceptiona bilo, pa onda sta bude bude, tvoje je da pazis kako ces sabirati
li $v0,0
jr $ra
