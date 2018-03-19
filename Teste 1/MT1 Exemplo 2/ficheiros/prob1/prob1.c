#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vetor.h"
#include "lista.h"

/****************************************************/
/*              Funcoes a implementar               */
/****************************************************/

/*** problema 1.1 ***/
float comprimento_medio(lista *lst)
{
	/* complexidade do algoritmo: O(n) - Só existe um ciclo na função implementada */

	//Verificação de parâmetros
	if(lst == NULL || lista_tamanho(lst) == 0)
	{
		//printf("Erro!");
		return 0;
	}

	//Iniciação de variáveis
	int i, len, size;
	float avg, total=0;
	l_elemento *aux;

	size = lista_tamanho(lst); //Atribui a size o tamanho da lista
	//printf("Tamanho da lista: %d\n", lista_tamanho(lst));

	//ciclo para percorrer a lista
	for (i=0; i < lst->tamanho; ++i)
	{
		aux = lista_elemento(lst, i); //atribui a aux o conteúdo da lista lst na posição i
		len = strlen(aux->str);	//Atribui a len o comprimento da string
		//printf("%s\n", aux->str); //Imprime a lista de freguesias
		//printf("%d\n", len); //Imprime tamanho de cada freguesia
		total = total + len; //Contabiliza o tamanho total de todas as strings
		//printf("%d\n", total); //Imprime tamanho total
	}

	avg = (total/size);
	return avg;
}

/*** problema 1.2 ***/
lista* filtra_nomes(lista *lst, char *existe)
{
	//Verificação de parâmetros
	if(lst == NULL || lista_tamanho(lst) == 0)
	{
		//printf("Erro!\n");
		return NULL;
	}

	//Iniciação de variáveis
	lista *aux = lista_nova(); //declaração de lista nova
	l_elemento *nomes;
	int i;

	nomes = lista_elemento(lst, i);

	//ciclo para percorrer a lista
	for (i = 0; i < lst->tamanho; ++i) 
	{
		//Apontador para o elemento da lista
		nomes = lista_elemento(lst, i);	//atribui a nomes o conteúdo da lista lst na posição i

		//Se o conteúdo de existe for diferente da string 
    	if (strstr(nomes->str, existe) != NULL) 
        {
        	lista_insere(aux, nomes->str, NULL);	//Insere esse conteúdo numa nova lista aux
        	lista_remove(lst, nomes);	//Remove elementos da lista
    	}
	}
	return aux;
    	
}

/*** problema 1.3 ***/
const char* mais_palavras(vetor *vec)
{
	//Verificação de parâmetros
	if(vec == NULL || vetor_tamanho(vec) == NULL)
	{
		//printf("Erro!\n");
		return NULL;
	}
	
	//iniciação de variáveis
	int i, j, max=0, i_max;
	const char *aux;
	char *palavra;

	//ciclo para percorrer o vetor enquanto menor que o tamanho
	for (i = 0; i < vetor_tamanho(vec); i++)
	{
		aux = vetor_elemento(vec,i);

		int count = 1; //Para contar a primeira palavra

    	for (j = 0; j < strlen(aux); ++j) //Percorre caractere a caractere o vetor
    	{
    		//se encontrar um espaço contabiliza mais uma palavra
    		if (aux[j] == ' ')
    		{
    			count++;
    		}
    	}
    	// se o número de palavras for maior que o máximo
    	//novo máximo passa a ser o número de palavras atual 
    	if (count > max) 
    	{
    		max = count;
    		i_max = i;
    	}
	}

	vetor_elemento(vec, i_max);
}

/****************************************************/
/*     Funcoes ja implementadas (nao modificar)     */
/****************************************************/

vetor* lerParaVetor(FILE* ficheiro)
{
	char buffer[256], *nlptr;
	vetor* v;
	
	if (ficheiro == NULL)
		return NULL;

	v = vetor_novo();

	while(!feof(ficheiro)) 
	{	
		fgets(buffer, 255, ficheiro);
		nlptr = strchr(buffer, '\n');
		if (nlptr) 
			*nlptr = '\0';
		
		vetor_insere(v,buffer,v->tamanho);
	}

	return v;
}

lista* lerParaLista(FILE* ficheiro)
{
	char buffer[256], *nlptr;
	lista* l;
	
	if (ficheiro == NULL)
		return NULL;

	l = lista_nova();
	
	while(!feof(ficheiro)) 
	{	
		fgets(buffer, 255, ficheiro);
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
    vetor *v;
    lista *l, *resultado;
    l_elemento *e;
    const char *nome;
    int i;
    double comp;
    
	/* testes */
	f = fopen("freguesias.txt","r");
	if(f == NULL)
	{
		printf("Erro ao ler ficheiro de entrada.\n");
		return 1;
	}
	l = lerParaLista(f);
		
	/* testa comprimento_medio */
	comp = comprimento_medio(l);
	if(comp)
		printf("\nComprimento medio das palavras: %.1f\n", comp);
	else
	   	printf("\ncomprimento_medio retornou 0\n");

	/* testa filtra_nomes */
    resultado = filtra_nomes(l, "Mamede");
    
	if(resultado)
	{
            printf("\nNomes filtrados (total de %d):\n", lista_tamanho(resultado));
            for (e = resultado->inicio; e != NULL; e = e->proximo)
                printf("%s\n", e->str);

            if(lista_tamanho(l) != 4230)
            	printf("Nem todos os nomes foram removidos do vetor (tamanho: %d; esperado: 4218)\n", lista_tamanho(l));
    }
	else
		printf("\nfiltra_nomes retornou NULL\n");

	/* testa mais_palavras */
	rewind(f);
	v = lerParaVetor(f);    
	nome = mais_palavras(v);
	if(nome)
	  	printf("\nNome com mais palavras: %s\n\n", nome);
	else
	   	printf("\nmais_palavras retornou NULL\n\n");
	
	vetor_apaga(v);
	lista_apaga(l);
	lista_apaga(resultado);
	
	fclose(f);
		
	return 0;
}
