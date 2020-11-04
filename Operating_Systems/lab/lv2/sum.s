.section .text
.globl sum
sum:
  pushl %ebp
  movl %esp, %ebp
  #eax ecx edx su neprezervirani registri, nama za sum trebaju 4
  pushl %ebx

  movl $0, %eax #sum -> ionako kroz eax vracamo vrijednost
  movl $0, %ebx #i -> counter
  #Argumenti uvijek pocinju na 8(%ebp) jer su prvih 8 bajta ebp i eip snimljeni
  movl 8(%ebp), %ecx #arr
  movl 12(%ebp), %edx #size

loop:
  #cmp, test
  cmp %edx, %ebx #Flipped od ove dole logike ebx >= edx
  jge wrapup
  #Napustamo petlju ukoliko je i >= size (ebx >= edx) -jump greater or equal
  addl (%ecx, %ebx, 4), %eax
  # ecx + 4 * edx, tj adresa + 4 * brojac
  # 4 * brojac pa zato jer ZASTO OVO UOPSTE ZAPISUJES GLUPANE OVO JE COMMON SENSE
  inc %ebx
  jmp loop

wrapup:
  popl %ebx
  movl %ebp, %esp
  popl %ebp
  ret


# Imm(R1, R2, scale)
