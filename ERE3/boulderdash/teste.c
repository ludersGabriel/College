#include <stdlib.h>
#include <stdio.h>

enum mapF{
  SOMA, MULT, SUB
};

void soma(int a, int b){
  fprintf(stderr, "a + b = %d\n", a + b);
}

void mult(int a, int b){
  fprintf(stderr, "a * b = %d\n", a * b);
}

void sub(int a, int b){
  fprintf(stderr, "a - b = %d\n", a - b);
}

int main () {
  void (*map[])(int, int) = {soma, mult, sub};

  map[SOMA](1, 2);
  map[SUB](1, 2);
  map[MULT](1, 2);

  return 0;
}