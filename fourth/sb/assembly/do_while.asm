.section .data
  I: .quad 0
  A: .quad 0
.section .text
.globl _start
_start:
  movq $0, I
  movq $0, A
  movq I, %rax
  do_while:
    movq A, %rdi
    addq %rax, %rdi 
    movq %rdi, A
    addq $1, %rax
    movq %rax, I
    cmpq $10, %rax
    jge end_while
    jmp do_while
  end_while:
    movq $60, %rax
    syscall
