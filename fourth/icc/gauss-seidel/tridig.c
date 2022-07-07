#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 5

void tridig(float *c, float *d, float *a, float *b, float *x, uint n, float tol){
  float erro = 1.0f + tol;
  int it = 0;
  while(erro > tol && it < 5){
    float xOld[n];
    memcpy(xOld, x, sizeof(float) * n);

    x[0] = (b[0] - c[0] * x[1])/d[0];
    for(int i = 1; i < n - 1; i++)
      x[i] = (b[i] - a[i - 1] * x[i - 1] - c[i] * x[i + 1]) / d[i];
    x[n-1] = (b[n-1] - a[n - 2] * x[n - 2]) / d[n-1];

    float max = fabs(xOld[0] - x[0]);
    for(int i = 1; i < n; i++){
      float dif = fabs(xOld[i] - x[i]);
      if(dif > max) max = dif;
    }

    erro = max;
    it++;
  }
}

int main(void){
  float b[N] = {1, 2, 3, 4, 5};
  float a[N - 1] = {2, 7, 8, 9};
  float c[N - 1] = {2, 3, 4, 5};
  float d[N] = {10, 13, 14, 15, 16};
  float x[N] = {0, 0, 0, 0, 0};

  tridig(c, d, a, b, x, N, 1.0e-8);

  for(int i = 0; i < N; i++){
    printf("%f ", x[i]);
  }

  printf("\n");

}