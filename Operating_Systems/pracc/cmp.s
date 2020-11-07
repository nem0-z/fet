.section .text
.globl main
main:
  pushl %ebp
  movl %esp, %ebp

  movl $3, %eax
  movl $3, %ecx

  cmp %eax, %ecx

#hmmm
  jz brate
  jne sike
  jmp end

brate:
  pushl %eax
  popl %eax

sike:
  pushl %ebx
  popl %ebx

end:
  leave
  ret
