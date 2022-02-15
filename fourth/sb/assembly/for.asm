.seciton .data
  I: .quad 0
  A: .quad 0
.section .text
.globl _start
_start:
  movq $0, I
  movq $0, A
  movq I, %rax
  for:
    