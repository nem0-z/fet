.rodata
threehalfs: .float 1.5

.text
.globl q_rsqrt
q_rsqrt:

addiu $sp, $sp, -128

#moj num je u $f12

li.s $f4,0.5
mul.s $f4,$f12,$f4

s.s $f4,124($sp)    #x2 = number*0.5

s.s $f12,120($sp)   #y = number

lw $t2,120($sp)     #i = *(long*)&y;

lui $t1,0x5f37
ori $t1, $t1, 0x59df  #load this weird number

sra $t2,$t2,1         #shift my i

subu $t2,$t1,$t2      #weird number - shifted i

sw $t2,116($sp)       #save it on stack

l.s $f6,116($sp)      #load it from stack but on c1 *(float*)&i;

l.s $f4,124($sp)      #load our x2 just in case

mul.s $f4,$f4,$f6  #x2*y
mul.s $f4,$f4,$f6  #x2*y*y

la $t4,threehalfs
l.s $f8,($t4)         #threehalfs in $f8

sub.s $f8,$f8,$f4     #threehalfs - whatever up there

mul.s $f0,$f6,$f8     #mult with y

addiu $sp, $sp, 128
jr $ra




