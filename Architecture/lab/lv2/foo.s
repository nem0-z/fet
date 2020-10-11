.section .text
.set noreorder
.globl main
#de malo probaj enkapsulaciju u C-u, 
#static globalne varijable(funkcije) ogranicavaju vidljivost samo na taj fajl
#probaj main u nekom C fajlu kao static

#u t4 smjesti 17+7-31
main:
addi $t0,$zero,17
addi $t1,$zero,7
addi $t2,$zero,31 
add $t3,$t0,$t1
sub $t4,$t3,$t2
addiu $v0,$zero,0
jr $ra  
