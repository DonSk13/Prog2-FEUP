#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int *pi, i, n;
		pi = (int *) malloc (n*sizeof(int)); //aloca espaço para n inteiros
	printf("Número de elementos?\n");
	scanf("%d", &n);

	for (i=0; i<n; i++)
	{
		printf("Introduza o %dºelemento\n", i+1);
		scanf("%d", &pi[i]);
	}

	printf("Vetor original: [");

		for (i=0; i<n; i++)
		{
			printf(" %d ", pi[i]);
		}
	printf("]\n");

	printf("Números pares: [");

	for (i=0; i<n; i++)
	{
		if(pi[i]%2==0) 
		{
			printf(" %d ", pi[i]);
		}
	}
	printf("]\n");

	printf("Números impares: [");

	for (i=0; i<n; i++)
	{
		if(pi[i]%2!=0) 
		{
			printf(" %d ", pi[i]);
		}
	}
	printf("]\n");
	free(pi);
}
