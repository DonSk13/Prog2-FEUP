#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n=0, i, l=0;
	char c, *max, *p;

	max = (char*) malloc(sizeof(char));
	p = (char*) malloc(sizeof(char));

	printf("Frase? ");
	
	while (scanf("%c", &c) == 1)
		{
			if (c == ' ' || c == '\n')
			{
				if (strlen(p) > strlen(max))
				{
					max = (char*) realloc(max, sizeof(char)*strlen(p));
					strcpy(max,p);
				}
				n++;
				i=0;

				if (c == '\n')
				{
					break;
				}
			}
			else
			{
				p = (char*) realloc(p, sizeof(char)*(i+1));
				p[i] = c;
				l++;
				i++;
			}
		}

	printf("Número de palavras: %d\n", n);
	printf("Palavra maior: %s\n", max);
	printf("Comprimento médio: %.1f\n", (float) l/(float) n);
	return 0;
}
