.section .data
  I: .quad 0
  MAIOR: .quad 0
  DATA_ITEMS: .quad 3, 34, 67, 45, 75, 222, 54, 0
.section .text
.globl _start
_start: 
  movq $0, %rdi
  movq DATA_ITEMS(, %rdi, 8), %rbx # rbx contains maior
  movq %rbx, MAIOR
  movq $1, %rdi # contains I or the index of the array
  movq %rdi, I
  while:
    movq DATA_ITEMS(, %rdi, 8), %rax
    cmpq $0, %rax
    je end_while
    cmpq %rbx, %rax
    jle end_if
    if:
      movq %rax, %rbx
      movq %rbx, MAIOR  
    end_if:
    addq $1, %rdi
    movq %rdi, I
    jmp while
  end_while:
    movq MAIOR, %rdi
    movq $60, %rax
    syscall
