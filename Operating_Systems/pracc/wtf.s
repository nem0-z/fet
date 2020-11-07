.section .text
.globl wtf
wtf:
  pushl %ebp
  movl %esp, %ebp
  
  #8(%ebp) is arr pointer
  #12(%ebp) is arr size
  #16(%ebp) is 2
  
  #movl $4, %ecx
  #movl 8(%ebp), %eax
  #movl (%eax), %eax
  #movl 8(%ebp,%ecx), %edx

  movl 8(%ebp), %eax

  movl $0, %edx
loop:
  cmp $5, %edx
  jge end
  movl (%eax, %edx, 4), %ecx
  inc %edx
  jmp loop

end:
  movl %ebp, %esp
  popl %ebp
  ret
