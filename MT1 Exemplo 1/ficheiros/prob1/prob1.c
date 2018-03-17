#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"
#include "fila.h"

/****************************************************/
/*              Funcoes a implementar               */
/****************************************************/

/*** problema 1.1 ***/
lista* encontra_nomes(lista *lst1, lista *lst2)
{
	/* complexidade do algoritmo: O(N²) - Um ciclo for dentro de outro ciclo for */

	l_elemento *nome1, *nome2;
	//int aux2;
	lista *aux = lista_nova();

	if(lst1 == NULL || lst2 == NULL)
	{
		//printf("Erro na leitura das listas\n");
		return NULL;
	}

	for (int i=0; i < lst1->tamanho; ++i)	
	{
		nome1 = lista_elemento(lst1, i);
		
		for (int j = 0; j < lst2->tamanho; ++j)
		{
			nome2 = lista_elemento(lst2, j);

			if (strcmp(nome1->str, nome2->str) == 0)
			{
				lista_insere(aux, nome1->str, NULL);	
			}
		}
	}
	//aux2 = lista_tamanho(aux);
	//printf("Resultado: %d\n", aux2);
	return aux;

	//outra hipótese de resolução

	/* complexidade do algoritmo: N^2  */

	/*lista *aux = lista_nova();
	l_elemento *nome1, *nome2;

	if(lst1 == NULL || lst2 == NULL)
	{
		return NULL;
	}

	nome1 = lst1->inicio;
	while (nome1 != NULL)
	{
		nome2 = lst2->inicio;
		while (aux2 != NULL)
		{
			if(strcmp(nome1->str,nome2->str) == 0)
			{
				lista_insere(aux,nome1->str,NULL);
			}
			nome2 = nome2->proximo;
		}
		nome1 = nome1->proximo;
	}

	return aux;*/
}

/*** problema 1.2 ***/
int lista_remove_longos(lista *lst, int nomes)
{
/*	//Verifica se há erro de leitura das listas
	if(lst == NULL)
	{
		//printf("Erro na leitura das listas\n");
		return -1;
	}

	//Verifica se lista de entrada tem tamanho zero
	if (lista_tamanho(lst) == 0)
	{
		//printf("Lista de entrada com tamanho zero\n");
		return -1;
	}

	int i, aux, j=0;
	l_elemento *nome;


	for (int i=0; i < lst->tamanho; ++i)	
	{
		nome = lista_elemento(lst, i);
		
    	char *palavra = strtok(nome->str, " "); //Retorna o primeiro espaço
   
    	for (aux = 0; palavra != NULL; ++aux)
    	{
    		palavra = strtok(NULL, " "); //Conta cada palavra que há em cada string
    	}
    	//printf("Palavras:%d\n", aux);

		if (aux>nomes)
		{
			//lista_remove(lst, nome);
			j++;		
		}
	}
	printf("Tamanho da lista: %d\n", lista_tamanho(lst));
	printf("O número de contactos eliminados é: %d\n", j);
	return 	j;*/
	return NULL;
}

/*** problema 1.3 ***/
fila* pesquisa_nomes(lista *lst, char *nome)
{
	//Verifica se há erro de leitura das listas
	if(lst == NULL)
	{
		//printf("Erro na leitura das listas\n");
		return NULL;
	}

	//Verifica se lista de entrada tem tamanho zero
	if (lista_tamanho(lst) == 0)
	{
		//printf("Lista de entrada com tamanho zero\n");
		return NULL;
	}

	lista *aux = lista_nova();
	l_elemento *nomes;
	int i;
	nomes = lista_elemento(lst, i);

	for (i = 0; i < lst->tamanho; ++i) 
	{
		//Apontador para o elemento da lista
		nomes = lista_elemento(lst, i);
    	if (strstr(nomes->str, nome) != NULL) 
        {
        	//na lista_insere, NULL dá a posição em que ainda não existe nada e onde pretendemos inserir string
        	if (lista_insere(aux, nomes->str, NULL) == NULL)
        	{
        		return NULL;
            	//printf("Ocorreu um erro ao inserir uma string na pesquisa parcial\n");
        	}
    	}
	}
	return aux;
}

/****************************************************/
/*     Funcoes ja implementadas (nao modificar)     */
/****************************************************/

lista* lerParaLista(FILE* ficheiro)
{
	char buffer[256], *nlptr;
	lista* l;

	if (ficheiro == NULL)
		return NULL;

	l = lista_nova();

	while(fgets(buffer, 255, ficheiro) != NULL)
	{
		nlptr = strchr(buffer, '\n');
		if (nlptr)
		*nlptr = '\0';
		lista_insere(l,buffer,NULL);
	}

	return l;
}

int main()
{
	FILE *f;
	lista *l1=NULL, *l2=NULL, *l=NULL;
	fila *resultado=NULL;
	l_elemento *e;
	int removidos;

	/* testes */
	f = fopen("nomes1.txt","r");
	if(f == NULL)
	{
		printf("Erro ao ler ficheiro de entrada.\n");
		return 1;
	}
	l1 = lerParaLista(f);
	fclose(f);

	f = fopen("nomes2.txt","r");
	if(f == NULL)
	{
		printf("Erro ao ler ficheiro de entrada.\n");
		return 1;
	}
	l2 = lerParaLista(f);
	fclose(f);

	/* inicio teste prob1.1 */
	l = encontra_nomes(l1, l2);
	if(l)
		printf("\nLista resultante contem %d nomes.\n", lista_tamanho(l));
	else
		printf("\nencontra_nomes retornou NULL\n");
	/* fim teste prob1.1 */

	/* inicio teste prob1.2 */
	removidos = lista_remove_longos(l1, 4);
	if(removidos!=-1)
	{
		printf("\nNomes longos removidos (total %d).\n", removidos);
		if(lista_tamanho(l1) != 224)
			printf("Nem todos os nomes longos foram removidos da lista (tamanho: %d; esperado: 19)\n", lista_tamanho(l1));
	}
	else
	printf("\nlista_remove_longos retornou ERRO\n");
	/* fim teste prob1.2 */

	/* inicio teste prob1.3 */
	resultado = pesquisa_nomes(l2, "SILVA");
	if(resultado)
	{
		int n=0;
		printf("\nNomes encontrados (%d): \n", fila_tamanho(resultado));
		while (!fila_vazia(resultado) && n<3) {
			printf("%s\n", fila_front(resultado));
			fila_pop(resultado);
			n++;
		}
		if(fila_tamanho(resultado) > 2)
		{
			puts("...");
			while (fila_tamanho(resultado) > 1)
				fila_pop(resultado);
			printf("%s\n", fila_front(resultado));
			fila_pop(resultado);
		}
		else {
			while (!fila_vazia(resultado)) {
					printf("%s\n", fila_front(resultado));
					fila_pop(resultado);
				}
		}
	}
	else
		printf("\npesquisa_nomes retornou NULL\n\n");
	/* fim teste prob1.3 */

	lista_apaga(l);
	lista_apaga(l1);
	lista_apaga(l2);
	fila_apaga(resultado);

	return 0;
}
