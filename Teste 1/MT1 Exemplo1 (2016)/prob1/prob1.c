#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vetor.h"
#include "lista.h"

/****************************************************/
/*              Funcoes a implementar               */
/****************************************************/

void retira_duplicados(vetor *vec)
{   
    //Verificação de parâmetros
    if (vec == NULL)
    {
	   return;
    }

    //Declaração de variáveis
    v_elemento *nome1, *nome2;

    //Ciclo que vai percorrer o ficheiro desde o inicio
    for (int i = 0; i < vetor_tamanho(vec); ++i)
    {
       nome1 = vetor_elemento(vec, i);
       //printf("%s\n", nome1); //Imprime vetor1 no ecrã

       //ciclo que vai percorrer o ficheiro a partir da segunda linha
       for (int j = i+1; j < vetor_tamanho(vec); ++j)
       {
            nome2 = vetor_elemento(vec, j);
            //printf("%s\n", nome2); //Imprime vetor 2 no ecrã

            if (strcmp(nome1, nome2) == 0)
            {
                //printf("%s\n", nome1);
                vetor_remove(vec,j);
                j--;
            }
        }
    }
}

vetor *interseta(lista *l1, lista *l2)
{
    //Verificação de parâmetros
    if (l1 == NULL || l2 == NULL)
    {
    	return NULL;
    }

    l_elemento *nome1, *nome2;
    v_elemento *nome_v;

    vetor *v;
    v = vetor_novo();

    if (v == NULL)
    {
        return NULL;
    }

    //ciclo para percorrer a lista 1
    for (int i = 0; i < lista_tamanho(l1); ++i)
    {
        nome1 = lista_elemento(l1, i);

        //Testes intermédios
        //printf("%s\n", nome1->str); //Imprime conteúdo da lista 1
        //vetor_insere(v, nome1->str, -1);
        //nome_v = vetor_elemento(v, i);
        //printf("%s\n", nome_v); //Imprime conteúdo do vetor

        //ciclo para percorrer a lista 2
        for (int j = 0; j < lista_tamanho(l2); ++j)
        {
            nome2 = lista_elemento(l2, j);
            //Testes intermédios
            //printf("%s\n", nome2->str); //Imprime conteúdo da lista 2
            //vetor_insere(v, nome2->str, -1);
            //nome_v = vetor_elemento(v, j);
            //printf("%s\n", nome_v); //Imprime conteúdo do vetor

            if (strcmp(nome1->str, nome2->str) == 0)
            {
                vetor_insere(v, nome1->str, -1);    //o conteúdo é inserido no vetor novo
            }
        }
    }

    return v;
}

vetor *anteriores(lista *lst, const int ano)
{
    if (lst == 0 || ano <0)
    {
        return NULL;
    }

	l_elemento *nome;

    vetor *v;
    v = vetor_novo();
    char *ano_char;
    int ano_int;

    if (v == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < lista_tamanho(lst); ++i)
    {
        nome = lista_elemento(lst, i);
        ano_char = strchr(nome->str, '(')+1;
        ano_int = atoi(ano_char);
        //printf("%d\n", ano_int); //Teste para imprimir inteiros

        if(ano_int < ano)
        {
            //printf("%s\n", nome->str); Imprime lista de filmes acima do ano indicado;
            vetor_insere(v, nome->str, -1);
        }
    }
    return v;
}


/****************************************************/
/*     Funcoes ja implementadas (nao modificar)     */
/****************************************************/

vetor *lerAtores(FILE *ficheiro) {
    char buffer[256], *nlptr;
    vetor *atores;

    if (ficheiro == NULL)
        return NULL;

    atores = vetor_novo();

    while (!feof(ficheiro)) {
        fgets(buffer, 255, ficheiro);
        nlptr = strchr(buffer, '\n');
        if (nlptr)
            *nlptr = '\0';

        vetor_insere(atores, buffer, atores->tamanho);
    }

    return atores;
}

lista *lerFilmes(FILE *ficheiro) {
    char buffer[256], *nlptr;
    lista *filmes;

    if (ficheiro == NULL)
        return NULL;

    filmes = lista_nova();

    while (!feof(ficheiro)) {
        fgets(buffer, 255, ficheiro);
        nlptr = strchr(buffer, '\n');
        if (nlptr)
            *nlptr = '\0';

        lista_insere(filmes, buffer, NULL);
    }

    return filmes;
}

int main() {
    FILE *fa, *ff, *ff2;
    vetor *atores, *resultado, *resultado1;
    lista *filmes, *filmes2;

    /* testes */
    fa = fopen("atores2.txt", "r");
    ff = fopen("filmes.txt", "r");
    ff2 = fopen("filmes2.txt", "r");

    atores = lerAtores(fa);
    filmes = lerFilmes(ff);
    filmes2 = lerFilmes(ff2);

    /* testa retira_duplicados */
    printf("Total inicial: %d\n", vetor_tamanho(atores));
    retira_duplicados(atores);
    printf("Unicos: %d (esperado: 30)\n\n", vetor_tamanho(atores));

    /* testa interseta */
    resultado = interseta(filmes, filmes2);
    if (resultado)
        printf("Intersecao: %d (esperado: 75)\n", vetor_tamanho(resultado));
    else
        printf("Intersecao: vetor NULL\n");

    /* testa anteriores */
    resultado1 = anteriores(filmes, 2000);
    if (resultado1)
        printf("\nAnteriores: %d (esperado: 106)\n", vetor_tamanho(resultado1));
    else
        printf("\nAnteriores: vetor NULL\n");

    vetor_apaga(atores);
    vetor_apaga(resultado);
    vetor_apaga(resultado1);
    lista_apaga(filmes);
    lista_apaga(filmes2);

    fclose(fa);
    fclose(ff);
    fclose(ff2);

    return 0;
}
