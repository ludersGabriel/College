#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 5

int main(void){
	float soma1 = 0.0f, soma2 = 0.0f;

	for(int i = 1; i <= 200; i++){
		soma1 += 1.0f / (i * i);
	}

	for(int i = 200; i >= 1; i--){
		soma2 += 1.0f / (i * i); 
	}

	printf("(soma1, soma2) = (%.15f, %.15f)\n", soma1, soma2);

	printf("%.15f\n", soma2 - soma1);
}
