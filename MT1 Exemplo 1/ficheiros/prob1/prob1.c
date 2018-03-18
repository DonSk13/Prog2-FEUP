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
	/* complexidade do algoritmo: O(N²) - Um ciclo dentro de outro ciclo */

	//verificação de parâmetros
	if(lst1 == NULL || lst2 == NULL)
	{
		//printf("Erro na leitura das listas\n");
		return NULL;
	}

	//iniciação de variáveis
	l_elemento *nome1, *nome2;
	//int aux2;
	lista *aux = lista_nova();

	//ciclo para percorrer toda a lista1
	for (int i=0; i < lst1->tamanho; ++i)	
	{
		nome1 = lista_elemento(lst1, i); //atribui à variável o conteúdo de lst2 na posição i
		
		//ciclo para percorrer toda a lista2
		for (int j = 0; j < lst2->tamanho; ++j)
		{
			nome2 = lista_elemento(lst2, j); //atribui à variável o conteúdo de lst2 na posição i

			//Se os conteúdos forem iguas
			if (strcmp(nome1->str, nome2->str) == 0)
			{
				lista_insere(aux, nome1->str, NULL);	//o conteúdo é inserido na lista nova
			}
		}
	}
	//aux2 = lista_tamanho(aux);
	//printf("Resultado: %d\n", aux2);
	return aux;

	//outra hipótese de resolução com uma forma diferente de percorrer a lista

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
	//Verificação de parâmetros
	if(lst == NULL || lista_tamanho(lst) == 0 || nomes < 0)
	{
		//printf("Erro na leitura das listas\n");
		return -1;
	}

	// Iniciação de variáveis
	int i, n=0; //n é variável que conta número de palavras removidas!
	l_elemento *nome;

	nome = lst->inicio; // A variável nome é atribuida ao primeiro valor da lista
	// Enquanto existirem valores para ser lidos
	while (nome != NULL)
	{
		int aux = 1; //Conta palavra inicial!

		for (i = 0; i < strlen(nome->str); i++) ////Percorre caractere a caractere o vetor
		{
			//se encontrar um espaço contabiliza mais uma palavra
			if(nome->str[i] == ' ')
			{
				aux++;
			}
		}

		//Se o número de falavras for maior que o limite estabelecido
		if(aux > nomes)
		{
			nome = lista_remove(lst,nome); //importante! ...quando removes um elemento da lista ligada, deves guardar o apontador para o elemento seguinte ao que é eliminado
			n++; //conta numero de palavras removidas!
		}
		//Se não passar para o elemento seguinte
		else
		{
			nome = nome->proximo;
		}
	}
	return n;
}

/*** problema 1.3 ***/
fila* pesquisa_nomes(lista *lst, char *nome)
{
	//Verificação de parâmetros
	if(lst == NULL || lista_tamanho(lst) == 0 || nome == NULL)
	{
		//printf("Erro na leitura das listas\n");
		return NULL;
	}

	//Iniciação de variáveis
	lista *aux = lista_nova();
	l_elemento *nomes;
	int i;
	nomes = lista_elemento(lst, i);

	//Ciclo para percorrer toda a lista
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
