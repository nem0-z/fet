.globl median
.section .text

median:
  pushl %ebp
  movl %esp, %ebp
  # arr -> 8(%ebp)
  # size -> 12(%ebp)
  movl $1, %eax #counter
  movl 8(%ebp), %edx #array*

loop: #exit wen? i >= size
  cmp 12(%ebp), %eax
  jge result
  movl (%edx, %eax, 4), %ecx #arr[i], exit if arr[i-1] > arr[i]
  cmp %ecx, -4(%edx, %eax, 4)
  jg not_sorted
  inc %eax
  jmp loop

result: #first check size if even or odd
  movl 12(%ebp), %ecx
  movl %ecx, %eax
  sar $1, %ecx
  andl $1, %eax
  cmp $1, %eax
  jne even
  movl (%edx, %ecx, 4), %eax
  jmp end

even:
  movl (%edx, %ecx, 4), %eax
  addl -4(%edx, %ecx, 4), %eax
  sar $1, %eax
  jmp end

not_sorted:
  movl $-1, %eax
end:
  popl %ebp
  ret
  
