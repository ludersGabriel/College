#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

stack* stackConstructor(
  int memSize, 
  int arrSize,
  void (*destroyEl) (void*),
  void (*printEl) (void*)
){
  if(arrSize < 1) arrSize = 1;
  
  stack* novo = malloc(sizeof(stack));
  novo->memSize = memSize;
  novo->arrSize = arrSize;
  novo->destroyEl = destroyEl;
  novo->printEl = printEl;
  novo->elements = 0;
  novo->dataArr = malloc(sizeof(memSize) * arrSize);
  return novo;
}

void printElements(stack* pilha){
  if(pilha->elements <= 0){
    printf("Pilha vazia!\n");
    return;
  }
  
  int i;
  for(i = 0; i < pilha->elements; i++){
    pilha->printEl(pilha->dataArr[i]);
  }
}

void stackDestructor(stack* pilha){
  if(!pilha) return;

  for(int i = 0; i < pilha->elements; i++){
    pilha->destroyEl(pilha->dataArr[i]);
  }
  free(pilha->dataArr);
  free(pilha);
}

void* pop(stack* pilha){
  if(!pilha) return NULL;

  if(pilha->elements == 0){
    printf("Stack underflow\n");
    exit(1);
  }
  pilha->elements--;
  return pilha->dataArr[pilha->elements];
}

void* top(stack* pilha){
  if(!pilha) return NULL;

  if(pilha->elements == 0){
    printf("Stack underflow\n");
    exit(1);
  }
  return pilha->dataArr[pilha->elements - 1];
}

void push(stack* pilha, void* el){
  if(!pilha) return;

  if(pilha->elements == pilha->arrSize){
    pilha->arrSize *= 2;
    pilha->dataArr = realloc(pilha->dataArr, pilha->arrSize * pilha->memSize);
  }
  pilha->dataArr[pilha->elements] = el;
  pilha->elements++;
}