.section .text
.set noreorder
.globl main #what happens if this is missing?
main:
#    destination,source,source/constant
addi $t0,$zero,100 #upisi 100 u t0
addi $t1,$zero,20 #upisi 20 u t1
sub $t2,$t0,$t1  #oduzmi vrijednost upisanu u t0 sa vrijednosti upisanom u t1 i smjesti u t2
addi $t3,$zero,5 #saberi vrijednost iz $zero(0) sa konstantom 5 i smjesti u t3
or $t4,$t3,$t2	#saberi(binarno ili) t3 i t2 i smjesti u t4
addiu $v0,$zero,0 #
jr $ra			#ove dvije linije = return 0 u C <==> li $v0,0

