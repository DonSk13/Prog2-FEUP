#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float avg(float x[])
{
   int aux1;
   float sum=0, avg;
   
   for(aux1 = 0; aux1 < 10; aux1++) 
   {
		sum = sum + x[aux1];
   }
   
   avg = sum / 10;

   return avg;
}

float max(float x[])
{
   int aux2;
   float max;

   max = x[0];

   for(aux2 = 1; aux2 < 10; aux2++) 
   {
		if (x[aux2] > max)
			max=x[aux2];
   }
   return max;
}

float min(float x[])
{
   int aux3;
   float min;

   min = x[0];
   
   for(aux3 = 1; aux3 < 10; aux3++) 
   {
		if (x[aux3] < min)
			min=x[aux3];
   }
   return min;
}

int main()
{
	int i;
	float v[10];

	for (i = 0; i < 10; i++)
	{
		printf("Introduza %dº número: ", i+1);
		scanf("%f", &v[i]);
	}
	
	printf("Média: %.2f\n", avg(v));  
	printf("Máximo: %.2f\n", max(v));
	printf("Mínimo: %.2f\n", min(v));	  
	printf("Vetor:");

	for (i=0; i<10; i++)
	{
		printf(" %.1f ", v[i]);
	}

return 0;
}
