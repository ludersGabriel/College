#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "ZeroFuncao.h"

int main ()
{
  // 2x⁴ + 4x³ + 3x² − 10x − 15 = 0
  Polinomio p;
  p.grau = 4;
  p.p = malloc(sizeof(double) * p.grau);
  p.p[0] = -15;
  p.p[1] = -10;
  p.p[2] = 3;
  p.p[3] = 4;
  p.p[4] = 2;

  int it;
  double root, erro, tempo;
  
  tempo = timestamp();
  erro = bisseccao(p, 0, 3, EPS, &it, &root);
  tempo = timestamp() - tempo;
  printf("(method, maxIt, root, erro, tempo) = (bissecao, %03d, %.15f, %.15f, %.15f)\n", it, root, erro, tempo);

  tempo = timestamp();
  erro = newtonRaphson(p, 3, EPS, &it, &root);
  tempo = timestamp() - tempo;
  printf("(method, maxIt, root, erro, tempo) = (newton  , %03d, %.15f, %.15f, %.15f)\n", it, root, erro, tempo);

  tempo = timestamp();
  erro = secante(p, 3, 2, EPS, &it, &root);
  tempo = timestamp() - tempo;
  printf("(method, maxIt, root, erro, tempo) = (secante , %03d, %.15f, %.15f, %.15f)\n", it, root, erro, tempo);


  free(p.p);
  return 0;
}

