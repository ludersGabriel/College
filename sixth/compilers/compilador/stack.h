#ifndef STACK_H
#define STACK_H

typedef struct ELEMENTO_TABELA_SIMBOLOS {
  char* token;
  struct {
    int nivelLexico;
    int offset;
  };
  int type;
} elTabelaSimbolos;

typedef enum STACK_TYPES {
  INT, CHAR, EL_TABELA_SIMBOLOS
}stackTypes;

typedef struct STACK {  
  void** dataArr;
  int elements;
  int memSize;
  int arrSize;

  void (*destroyEl) (void*);
} stack;

elTabelaSimbolos* elTabelaSimbolosConstructor(char* token, int nivelLexico, int offset, int type);
void elTabelaSimbolosDestructor(elTabelaSimbolos* el);

stack* stackConstructor(
  int memSize, 
  int arrSize,
  void (*destroyEl) (void*)
);
void stackDestructor(stack* pilha);
void* pop(stack* pilha);
void* top(stack* pilha);
void push(stack* pilha, void* el);

#endif
