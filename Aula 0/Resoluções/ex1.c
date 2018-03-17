#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float parabola(float a, float x)
{
	return a*x*x;
}

int main()
{
	float i, p, x1, x2, b, aux;

	printf("Qual o valor de a? ");
	scanf("%f", &p);
	printf("Qual o intervalo? ");
	scanf("%f %f", &x1, &x2);
	printf("Qual o incremento? ");
	scanf("%f", &b);

	for (i=x1; i<=x2; i=i+b)
	{
		aux=parabola(p,i);
		printf("f(");
		printf("%.1f", i);
		printf(")=");
		printf("%.1f\n", aux);						
	}
}
