addiu $12, $0, 16   #u registru 12 0x10
addiu $13, $0, 8    #u registru 13 0x8
addu $20, $12, $13  #u registru 20 0x18
subu $10, $20, $12  #u registru 10 0x8
and $14, $12, $13   #u registru 14 0
or $14, $12, $13    #u registru 14 0x18
sw $14, 0($15)
lw $18, 0($15)
j sinisa
addiu $2, $0, 3    #ovo se ne bi trebalo nikad izvrsit

sinisa:
beq $12, $13, ismet #ne bi trebalo skociti na ismeta
bne $13, $13, ismet #ne bi trebalo skociti na ismeta
addiu $6, $0, -25   #u registru 6 ffffffe7
sw $6, 0($2)

ismet:
addiu $15, $0, 5    
addiu $16, $0, 5
beq $15, $16, boris  #treba skociti na borisa
j test

boris:
ori $15, $0, 7
bne $15, $16, test   #treba skociti na test
subu $15, $15, $10   #ovo se ne bi trebalo nikad izvrsit

test:
lw $30, 0($2)    #u registru 30 ffffffe7
xori $25, $30, 0xffaa 
andi $7, $7, 0xffff  



