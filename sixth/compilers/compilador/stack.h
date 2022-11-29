#ifndef STACK_H
#define STACK_H

typedef struct STACK {  
  void** dataArr;
  int elements;
  int memSize;
  int arrSize;

  void (*destroyEl) (void*);
  void (*printEl) (void*);
} stack;

stack* stackConstructor(
  int memSize, 
  int arrSize,
  void (*destroyEl) (void*),
  void (*printEl) (void*)
);
void stackDestructor(stack* pilha);
void* pop(stack* pilha);
void* top(stack* pilha);
void push(stack* pilha, void* el);
void printElements(stack* pilha);

#endif
