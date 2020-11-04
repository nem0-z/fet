.globl median
.section .text

median:
  pushl %ebp
  movl %esp, %ebp
  
  movl $1, %edx #counter
  movl 8(%ebp), %ecx #arr
  pushl %esi #preserve %esi
  movl 12(%ebp), %esi #size

#edx = esi
loop:
  cmp %esi, %edx
  je continue
  pushl %ebx
  movl -4(%ecx, %edx, 4), %ebx
  cmp (%ecx, %edx, 4), %ebx 
  popl %ebx
  jg fallback
  inc %edx
  jmp loop

continue:
  #check if size is even or odd number
  pushl %ebx
  movl %esi, %ebx
  andl $1, %ebx
  popl %ebx
  je even

odd:
  sar $1, %esi 
  movl (%ecx, %esi, 4), %eax
  jmp end

even:
  sar $1, %esi 
  movl (%ecx, %esi, 4), %eax
  subl $1, %esi
  addl (%ecx, %esi, 4), %eax
  sar $1, %eax
  jmp end
  

fallback:
  movl $-1, %eax

end:
  popl %esi #get %esi back
  leave
  ret
  
