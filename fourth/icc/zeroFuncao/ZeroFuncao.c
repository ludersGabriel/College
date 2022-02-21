#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "ZeroFuncao.h"

double bisseccao (Polinomio p, double a, double b, double eps,
	       int *it, double *raiz)
{
	
	double currentXm, oldXm, erro = 0;
	double pxA, pxM;
	*it = 1;

	currentXm = (a + b)/2;
	calcPolinomio_rapido(p, a, &pxA, NULL);
	calcPolinomio_rapido(p, currentXm, &pxM, NULL);

	if(pxM * pxA < 0)
		b = currentXm;
	else if(pxM * pxA > 0)
		a = currentXm;
	else {
			*raiz = currentXm;
			return erro;
		}

	do{
		oldXm = currentXm;
		currentXm = (a + b) / 2;
		calcPolinomio_rapido(p, a, &pxA, NULL);
		calcPolinomio_rapido(p, currentXm, &pxM, NULL);

		erro = fabs((currentXm - oldXm) / currentXm) * 100;

		if(pxM * pxA < 0)
			b = currentXm;
		else if(pxM * pxA > 0)
			a = currentXm;
		else {
			*raiz = currentXm;
			return erro;
		}

		*it += 1;
	}while(erro > eps && *it < MAXIT);

	*raiz = currentXm;

	return erro;

}


double newtonRaphson (Polinomio p, double x0, double eps,
		   int *it, double *raiz)
{
	double newX = x0, oldX, px, dpx, oldDpx, erro;
	int criterio1, criterio2, criterio3;
	*it = 0;

	// Perguntar sobre primeira iteração -> div por 0

	do{
		oldX = newX;
		oldDpx = dpx;
		calcPolinomio_rapido(p, oldX, &px, &dpx);

		if(!(fabs(dpx) > DBL_MIN))
			dpx = oldDpx;

		newX = oldX - px / dpx;
		
		erro = fabs(oldX - newX);
		criterio1 = erro > eps;

		calcPolinomio_rapido(p, newX, &px, NULL);
		criterio2 = fabs(px) > eps;

		*it += 1;
		criterio3 = *it < MAXIT;

	}while(criterio1 && criterio2 && criterio3);

	*raiz = newX;
	return erro;
}


double secante (Polinomio p, double x0, double x1, double eps,
	     int *it, double *raiz)
{

	double newX = x1, oldX = x0, oldOldX, px, oldOldPx, subOldPx, erro;
	int criterio1, criterio2, criterio3;
	*it = 0;

	do{
		oldOldX = oldX;
		oldX = newX;

		calcPolinomio_rapido(p, oldX, &px, NULL);

		subOldPx = oldOldPx;
		calcPolinomio_rapido(p, oldOldX, &oldOldPx, NULL);

		if(!(fabs(px - oldOldPx) > DBL_MIN)){
			oldOldPx = subOldPx;
		}

		newX = oldX - (px * (oldX - oldOldX))/(px - oldOldPx);
		
		erro = fabs(oldX - newX);
		criterio1 = erro > eps;

		calcPolinomio_rapido(p, newX, &px, NULL);
		criterio2 = fabs(px) > eps;

		*it += 1;
		criterio3 = *it < MAXIT;

	}while(criterio1 && criterio2 && criterio3);

	*raiz = newX;
	return erro;

}


void calcPolinomio_rapido(Polinomio p, double x, double *px, double *dpx)
{
	double b = 0;
	double c = 0;
	for(int i = p.grau; i > 0; i--){
		b = b * x + p.p[i];
		c = c*x + b;
	}
	b = b * x + p.p[0];
	*px = b;
	if(dpx){
		*dpx = c;
	}
}


void calcPolinomio_lento(Polinomio p, double x, double *px, double *dpx)
{

}
