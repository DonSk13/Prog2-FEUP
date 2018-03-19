#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pilha.h"

#define BUFFER 256

/****************************************************/
/*              Funcoes a implementar               */
/****************************************************/

/*** problema 2 ***/
float* avalia_expressoes(FILE *ficheiro, int *N)
{
	//Verificação de parâmetros
	if (ficheiro == NULL || N == NULL)
	{
		//printf("Erro!\n");
		return NULL;
	}

	//Declaração de variáveis
	char str[BUFFER];
	pilha *p;
	float a,b,c, *ptr;
	int i, j = 0;

	p = pilha_nova();

	//Lê o ficheiro
	while(fgets(str,BUFFER,ficheiro) != NULL)
	{
		for (i=0; i <= strlen(str); i++) //conta também o carater final '\0' !
		{
			/*operando*/
			if(str[i] >= '0' && str[i] <= '9') //verificar se é um caracter entre 0 e 9
			{
				pilha_push(p,atoi(&str[i])); //converte a string em numerário (float)
			}

			/*operador*/
			else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') //Verifica se é um operador
			{
				a = pilha_top(p);
				pilha_pop(p);
				b = pilha_top(p);
				pilha_pop(p);

				switch(str[i])
				{
					case '+': c = b + a; break;
					case '-': c = b - a; break;
					case '*': c = b * a; break;
					case '/': c = b / a; break;
				}
				
				pilha_push(p,c);
			}
			
			else if (str[i] == '\0') //quando se chega ao fim da string
			{
				ptr = realloc(ptr,(j+1)*sizeof(float));
				ptr[j]=pilha_top(p);
				j++;
			}
		}
	}

	*N = j;
	pilha_apaga(p);
	return ptr;
}

/****************************************************/
/*     Funcoes ja implementadas (nao modificar)     */
/****************************************************/

#define BUFFER 256

int main()
{
	FILE *fin;
	float *resultados;
	char expressao[BUFFER];
	int i, n=0;

	fin = fopen("expressoes.txt", "r");
	if(fin == NULL)
	{
		printf("Erro ao abrir ficheiro.\n");
		return 1;
	}

	if((resultados = avalia_expressoes(fin, &n)) != NULL)
	{
		rewind(fin);
		for(i=0; i<n && fgets(expressao, BUFFER, fin) != NULL; i++)
		{
			expressao[strlen(expressao)-1] = '\0';
			printf("%s -> %f\n", expressao, resultados[i]);
		}
	}
	else
		printf("Funcao retornou erro.\n");

	fclose(fin);

	return 0;
}
