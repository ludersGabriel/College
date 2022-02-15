.seciton .data
  I: .quad 0
  A: .quad 0
.section .text
.globl _start
_start:
  movq $0, I
  movq $10, A
  movq I, %rax
  movq A, %rdi
  for: 
    cmpq %rax, %rdi
    jge end_for
    addi $1, %rdi
    jmp for
  end_for:
    