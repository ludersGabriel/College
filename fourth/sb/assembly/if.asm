.section .data
  A: .quad 0
  B: .quad 0
.section .text
.globl _start
_start:
  movq $5, A
  movq A, %rdi
  movq $6, B
  movq B, %rax
  if:
    cmpq %rax, %rdi # ask about order of comparison a > b ?
    jnge else
    addq %rax, %rdi
    movq %rdi, A
    jmp end_if
  else:
    subq %rax, %rdi # rdi := rdi - rax => A = A - B
    movq %rdi, A
  end_if:
  movq $60, %rax
  syscall
