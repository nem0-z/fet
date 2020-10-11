.data
d: .word 0

.rodata
str1: .string "%c"
str2: .string "\n"

.text
.globl combinations

  combinations:
# $a0 -> array*     $a1 -> uint32_t size      $a2 -> uint32_t r(num of iterations)

addiu $sp, $sp, -256
sw $ra, 252($sp)
sw $a2, 248($sp)
sw $a1, 244($sp)
sw $a0, 240($sp)      #preserve arguments

move $a0, $a2         
jal malloc            #prepare and call malloc

la $t0, d
sw $v0,($t0)          #save return value of malloc in d

lw $a0, 240($sp)     
lw $a1, 248($sp)
lw $a2, 244($sp)      #load preserved arguments for next call preparation
lw $a3, 248($sp)

jal combinations_impl #call combinations_impl

lw $ra, 252($sp)
addiu $sp, $sp, 256
jr $ra                #function epilogue


  combinations_impl:
# $a0 -> array*          $a1 -> uint32_t maxr (max num of iterations)    
# $a2 -> uint32_t size   $a3 -> uint32_t r(num of iterations)
addiu $sp, $sp, -256
sw $ra, 252($sp)

bne $a3, $0, rekurzija    #if r!=0 goto rekurzija else call print_comb

move $a0, $a1
jal print_comb            #prepare and call print_comb

j endcombi                # <==> return;

rekurzija:

li $t0, 0           #my i counter

loopcombi:
beq $t0, $a2, endcombi    #if i == size get out

addu $t5, $a0, $t0        # chars+i
lb $t5, ($t5)             # chars[i]

subu $t6, $a1, $a3        # maxr - r

la $t1, d
addu $t6, $t1, $t6        # d + maxr - r

sb $t5, ($t6)             # d[maxr-r] = chars[i]

sw $t0, 248($sp)          
sw $a0, 244($sp)
sw $a1, 240($sp)
sw $a2, 236($sp)
sw $a3, 232($sp)        #preserve arguments for next call

addiu $a3, $a3, -1      #prepare a3 for recursive call

jal combinations_impl   #recursive call

lw $t0, 248($sp)          
lw $a0, 244($sp)
lw $a1, 240($sp)
lw $a2, 236($sp)
lw $a3, 232($sp)        #load preserved arguments 

addiu $t0, $t0, 1       #increment counter
j loopcombi             #loop it

endcombi:

lw $ra, 252($sp)
addiu $sp, $sp, 256
jr $ra                  #function epilogue



  print_comb:
# $a0 -> uint32_t maxr
addiu $sp, $sp, -128
sw $ra, 124($sp)

li $t0, 0

loopprint:
beq $t0, $a0, newline   #prepare counter and i<maxr

sw $t0, 120($sp)
sw $a0, 116($sp)        #preserve arguments

la $t2, d
addu $t4, $t2, $t0      # d+i

lb $a1, ($t4)
la $a0, str1            #prepare printf argument

jal printf              #call printf

lw $t0, 120($sp)
lw $a0, 116($sp)        #load preserved arguments

addiu $t0, $t0, 1
j loopprint

newline:

la $a0, str2            #prepare printf argument

jal printf              #call printf

lw $ra, 124($sp)
addiu $sp, $sp, 128
jr $ra                  #function epilogue

