.section .rodata
print_fmt: .asciz "You entered: %d\n" 
scan_fmt: .asciz "%d"

.section .text
.globl main
main:
  #Prologue
  pushl %ebp
  movl %esp, %ebp

  #subl $4, %esp #Spustamo stack-pointer za 4 bajta, za nas integer #TREBA LI NAM OVO THO

  #Redoslijed pushanja argumenata za funkciju je obrnut redoslijedu u fji
  #Za scanf bi prvo pushali &i, a onda string 

  #xd
  pushl %esp #Na ovoj adresi je nas integer i u toku scanfa ce se tu i snimiti

  pushl $scan_fmt
  call scanf
  addl $8, %esp #Vracamo stack-pointer jer smo pushanjem ova 2 argumenta ga spustili za 8
  #Sad nam je stack nazad gdje je i bio nakon xd instrukcije, tu je nas int
  #(To nam je drugi argument ali cemo ga naopako pushati tako da *shrug* mozemo ga samo ostaviti tu)

  pushl $print_fmt  #Pushaj "value" sa printf_fmt labela
  call printf

  #Epilogue
  movl $0, %eax #Ili xorl %eax, %eax
  movl %ebp, %esp
  popl %ebp #Ove dvije funkcije su ekvivalentne f-ji leave
  ret
