.section .data
  A: .quad 0
  B: .quad 0
.section .text
.globl _start
soma:
  # always do these first instructions
  pushq %rbp
  movq %rsp, %rbp

  movq A, %rbx
  movq B, %rcx
  addq %rbx, %rcx
  movq %rcx, %rax # return in rax

  # always do these last two as well
  popq %rbp
  ret
_start:
  movq $4, A
  movq $15, B
  call soma # calls the method and saves the return in rax
  movq %rax, B
  movq B, %rdi

  # how we kill the program
  movq $60, %rax
  syscall
