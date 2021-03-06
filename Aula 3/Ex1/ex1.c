#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

//Função Imprime
void lista_imprime(lista *lst)
{
	int i, n = lst->tamanho;
	l_elemento *nome;

    for (i = 0; i < n; ++i) 
    {
    	nome = lista_elemento(lst, i);
        printf("Pos %d -> %s\n", i, nome->str);
    }
}

//Função de Pesquisa de Substring
lista *lista_pesquisa_substring(lista *lst, char *substring)
{
	//Apontador para a lista
	lista *aux = lista_nova();
	int i;
	l_elemento *nome;

	for (i = 0; i < lst->tamanho; ++i) 
	{
		//Apontador para o elemento da lista
		nome = lista_elemento(lst, i);
    	if (strstr(nome->str, substring) != NULL) 
        {
    		lista_insere(aux, nome->str, NULL);
    	}
	}

	return aux;
}

lista *lista_concatena(lista *lst1, lista *lst2)
{
	for (int i = 0; i < lst2->tamanho; i++)
	{
		l_elemento *e = lista_elemento(lst2, i);
		lista_insere(lst1, e->str, NULL);
	}

	return lst1;
}

int main() 

{
	//Declaração de Variáveis
    FILE *f;
    char str[100];
    int n = 0;

    lista *jogos = lista_nova();

    //Leitura do TXT
    f = fopen("arquivo.txt", "r");
    	if(f==NULL)
    	{
    		printf("Erro de ficheiro\n");
    		return 0;
    	}

	//Exercício a)
    //Enquanto existirem linhas no TXT
    while (fgets(str, 100, f) != NULL) 
    {
    	str[strlen(str)-1] = '\0';
    	lista_insere(jogos, str, NULL);
    	n++;
    	//printf("%s\n", str);
    }

    printf("Foram carregados %d jogos.\n", n);
    lista_imprime(jogos);



	//Exercício b)
    //Teste à função criada!
    //lista *ps2 = lista_nova();
    //printf("\nOs jogos PS2 são:\n");
    //ps2 = lista_pesquisa_substring(jogos,"PS2");
    //lista_imprime(ps2);


	//Exercício c)
    lista *jogos2 = lista_pesquisa_substring(jogos,"PS2");
    l_elemento *text;

    //Ciclo para percorrer a lista com os jogos todos!
    text = jogos->inicio;
    while (text != NULL)
    {
    	//Ciclo para percorrer  alista que contém jogos PS2
    	for (int j = 0; j < lista_tamanho(jogos2); ++j)
    	{
    		l_elemento *text2 = lista_elemento (jogos2, j);

    		if (strcmp(text->str, text2->str) == 0)
    		{
    			text = lista_remove(jogos, text);
    			//break;
    		}
    	}

    	text=text->proximo;
    }

    printf("\nApós remoção de jogos PS2, a lista contém %d jogos\n", jogos->tamanho);
    
    FILE *txtNovo = fopen ("jogos2.txt", "w");

    for (int i = 0; i < lista_tamanho(jogos); ++i)
    {
    	char *textFile = lista_elemento(jogos,i)->str;
    	fputs(textFile,txtNovo);
    	fputs("\n",txtNovo);
    }

    lista_imprime(jogos);
    //fclose(txtNovo);


	//Exercício d)
	//Declaração de Variáveis
    char str2[100];
    lista *jogos3 = lista_nova();

    //Leitura do TXT
	FILE *f2 = fopen ("oldies.txt", "r");
    	if(f==NULL)
    	{
    		printf("Erro de ficheiro\n");
    		return 0;
    	}

    //Enquanto existirem linhas no TXT
    while (fgets(str2, 100, f2) != NULL) 
    {
    	lista_insere(jogos3, str2, NULL);
    }
    
    printf("\n");
    printf("Foram carregados %d jogos antigos.\n", lista_tamanho(jogos3));
    lista_imprime(jogos3);

    lista_concatena(jogos, jogos3);
	
    printf("Após a concatenação, a lista final contém %d jogos.\n", lista_tamanho(jogos));
    lista_imprime(jogos);
	fclose(f2);


	//Exercício e)
	const char s[2] = "(";
	char *token;

	/* get the first token */
	token = strtok(str2, s);

    printf("Lista ordenada:\n");
    
	while(token) 
	{
		printf("%s\n", token);
    
		token = strtok(NULL, s);
	}
	
       /* walk through other tokens */
/*	while( token != NULL ) 
	{
		printf( " %s\n", token );
	}*/
    
     
    //Isto possivelmente está errado!!
/*	lista *jogos4 = lista_pesquisa_substring(jogos,"(3DS)");
	lista *jogos5 = lista_pesquisa_substring(jogos,"(PC)");
	lista *jogos6 = lista_pesquisa_substring(jogos,"(PS3)");
	lista *jogos7 = lista_pesquisa_substring(jogos,"(Wii)");
	lista *jogos8 = lista_pesquisa_substring(jogos,"(ZX_SPC)");
	lista_ordena(jogos4);
	lista_ordena(jogos5);
	lista_ordena(jogos6);
	lista_ordena(jogos7);
	lista_ordena(jogos8);
	lista_concatena(jogos4, jogos5);
	lista_concatena(jogos6, jogos7);
	lista_concatena(jogos4, jogos6);
	lista_concatena(jogos4, jogos8);
	lista_imprime(jogos4);*/

    //Esta função ordena os jogos alfabeticamente, mas o que se pede é ordenar primeiro por consola e depois alfabeticamente.
	//lista_ordena(jogos4;

	//Exercício f)

/*	for(int b=0; b < lista_tamanho(jogos4); b++)
	{
		l_elemento *e = lista_elemento(jogos4, b);
		if(e->str == 'Duke Nukem (PS3)')
			printf("O jogo Duke Nukem (PS3) encontra-se na posicao %d", lista_atribui(jogos4,b,e->str));
	}
	l_elemento *pos = lista_pesquisa(jogos, "Duke Nukem (PS3)", LISTA_INICIO);
	printf("O jogo Duke Nukem (PS3) encontra-se na posição %d", pos);*/

	fclose(f);
}
