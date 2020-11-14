.section .text
.globl main:
  pushl %ebp
  movl %esp, %ebp

  pushl -8(%ebp) #ovo pusha *vrijednost* sa -8(%ebp) na stack
  #tho ako nam treba samo adresa -8(%ebp) onda valja leal
  leal -8(%ebp), %eax
  pushl %eax

  leave
  ret
