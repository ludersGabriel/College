#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void destroyInt(void* el){
  free(el);
}

int main() {

  stack* myStack = stackConstructor(
    sizeof(int),
    10,
    (void (*)(void*)) destroyInt
  );

  int* el = malloc(sizeof(int));
  int* el2 = malloc(sizeof(int));

  *el = 10;
  *el2 = 20;

  push(myStack, el);
  push(myStack, el2);

  int el3 = *(int*) top(myStack);

  printf("%d\n", el3);

  stackDestructor(myStack);

  return 0;
}