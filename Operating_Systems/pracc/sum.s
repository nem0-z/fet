.globl sum

.section .rodata
str: .string "(sum) Sum is equal to: %d\n"

.section .text
sum:
  pushl %ebp
  movl %esp, %ebp 
  
  pushl %ebx

  movl $0, %eax #total
  movl $0, %ebx #counter
  movl 8(%ebp), %ecx #array
  movl 12(%ebp), %edx #size
  
loop: #exit when ebx = edx
  cmp %edx, %ebx
  je print
  addl (%ecx, %ebx, 4), %eax
  inc %ebx
  jmp loop

print:
  pushl %eax
  pushl $str
  call printf

end:
  addl $4, %esp
  popl %eax
  popl %ebx
  leave
  ret


