#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100

void inverte(char *strOriginal, char *strInvertida)
{
	int i;

	for (i = 0; i < strlen(strOriginal); i++)
	{
		strInvertida[i] = strOriginal[strlen(strOriginal) - i - 1];
	}
}

int main()
{
	char strOriginal[M]={}, strInvertida[M]={};



	while (1)
	{
		printf("Palavra? ");
		scanf("%s", strOriginal);
		//printf("O tamanho é: %d\n", (unsigned)strlen(strOriginal));
		//printf("O tamanho é: %d\n", (unsigned)strlen(strInvertida));

		if (strcmp(strOriginal, ".") == 0)
		{
			return 0;
		}
		//colocar a strInvertida a zero antes de cada inversão
		memset(strInvertida, 0, M);
		inverte(strOriginal, strInvertida);
		//printf("O tamanho é: %d\n", (unsigned)strlen(strOriginal));
		//printf("O tamanho é: %d\n", (unsigned)strlen(strInvertida));

		if (strcmp(strOriginal, strInvertida) == 0)
		{
			printf("Resultado: %s é capicua\n", strOriginal);
			//printf("O tamanho é: %d\n", (unsigned)strlen(strOriginal));
		}
		else if (strcmp(strOriginal, strInvertida) != 0)
		{
			printf("Resultado: %s não é capicua\n", strOriginal);
			//printf("O tamanho é: %d\n", (unsigned)strlen(strOriginal));
		}
	}
}
