#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int v1[5], v2[5], i, j;

	printf("Vetor 1:\n");
	for (int i = 1; i <= 5; i++)
	{
		printf("Introduza %dº número: ", i);
		scanf("%d", &v1[i]);
	}
	printf("\n");
	printf("Vetor 2:\n");

	for (j = 1; j <= 5; j++)
	{
		printf("Introduza %dº número: ", j);
		scanf("%d", &v2[j]);
	}
    printf("\nComuns: ");

	for (i=1; i<= 5; i++) 
	{ 
		for (j=1; j<= 5; j++)
		{	
			if (v1[i] == v2[j]) 
        	{
        		printf("%d ", v1[i]);
			}
		}	
	}
}
