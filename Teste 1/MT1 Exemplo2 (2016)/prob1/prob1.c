#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vetor.h"
#include "lista.h"

/* problema 1.1 */
int tira_carta(lista* baralho, lista* ordem)
{
    if (baralho == 0 || ordem == 0)
    {
        return -1;
    }
    
    l_elemento *card, *aux;
    int i;

    card = baralho->inicio;

    for(i = 0, aux = ordem->inicio; aux; aux = aux->proximo, ++i)
    {
        if(strcmp(card->str, aux->str) == 0)
        {
            break;
        }
    }

    lista_remove(baralho,card);
    return i;
}

/* problema 1.2 */
char* faz_jogada(vetor *jogadores, lista *baralho, lista *ordem)
{
    if(jogadores == 0 || baralho == 0 || ordem == 0)
    {
        return 0;
    }

    int melhor = -1, card;
    char *nomeMelhor = 0;

    for(int i = 0; i < vetor_tamanho(jogadores); ++i)
    {
        card = tira_carta(baralho, ordem);

        if(card > melhor)
        {
            melhor = card;
            nomeMelhor = jogadores->elementos[i].str;
        }
    }

    return nomeMelhor;
}

/* problema 1.3 */
int numero_vitorias(vetor *vencedores, const char *nome)
{
    // NOTE: A complexidade do algoritmo é O(n)
    if(vencedores == 0 || nome == 0)
    {
        return -1;
    }

    int numVitorias = 0;

    for(int i = 0; i < vetor_tamanho(vencedores); ++i)
    {
        if(strcmp(vencedores->elementos[i].str, nome) == 0)
        {
            ++numVitorias;
        }
    }
    return numVitorias;
}

/***************************************************/
/*** não alterar o ficheiro a partir deste ponto ***/
/***************************************************/

char *nomes_[] = {"Ana", "Rui", "Miguel", "Sara"};
char *cartas_[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
int baralho_[] = { 11, 10, 1, 2, 9, 0, 2, 2, 12, 8, 1, 7, 6, 5, 12, 7, 6, 1, 5,
                   11, 10, 6, 6, 10, 9, 12, 10, 4, 11, 9, 3, 7, 4, 0, 8, 0,
                   0, 8, 1, 11, 5, 2, 3, 9, 7, 5, 3, 12, 4, 3, 8, 4 };
char *vencedores_[] = {"Rui", "Ana", "Ana", "Ana", "Rui", "Sara", "Miguel",
                       "Ana", "Ana", "Rui", "Sara", "Sara", "Sara"};

void insere_carta(lista* baralho, int valor)
{
    //printf("A inserir: %d:", valor);
    char str[4];
    if(valor < 8)
        sprintf(str, "%c", valor+'2');
    else if(valor == 8)
        strcpy(str, "10");
    else if(valor == 9)
        strcpy(str, "J");
    else if(valor == 10)
        strcpy(str, "Q");
    else if(valor == 11)
        strcpy(str, "K");
    else if(valor == 12)
        strcpy(str, "A");
    lista_insere(baralho, str, baralho->inicio);
    //printf(" %s\n", str);
}

int main()
{
    int i;
    vetor* jogadores;
    lista* baralho;
    lista* ordem;
    vetor* jogadas;

    jogadores = vetor_novo();
    for(i=0; i<4; i++)
        vetor_insere(jogadores, nomes_[i], i);

    baralho = lista_nova();
    for(i=0; i<52; i++)
        insere_carta(baralho, baralho_[i]);

    ordem = lista_nova();
    for(i=0; i<13; i++)
        lista_insere(ordem, cartas_[i], NULL);

    /* testa alínea 1.1 */
    fprintf(stderr, "Valor da primeira carta: %d\n", tira_carta(baralho, ordem));
    fprintf(stderr, "Valor da segunda carta: %d\n", tira_carta(baralho, ordem));
    fprintf(stderr, "Valor da terceira carta: %d\n", tira_carta(baralho, ordem));
    insere_carta(baralho, baralho_[49]);
    insere_carta(baralho, baralho_[50]);
    insere_carta(baralho, baralho_[51]);

    /* testa alínea 1.2 */
    jogadas = vetor_novo();
    for(i=0; i<13; i++)
    {
        char *str = faz_jogada(jogadores, baralho, ordem);
        if(str != NULL)
            vetor_insere(jogadas, str, i);
        if(vetor_tamanho(jogadores) != 4)
            fprintf(stderr, "Aviso: esta' a alterar a fila de jogadores.\n");
    }
    printf("\nVencedores das primeiras 3 jogadas:\n");
    for(i=0; i<jogadas->tamanho && i<3; i++)
        fprintf(stderr, "Jogada %d: %s\n", i+1, vetor_elemento(jogadas,i));
    vetor_apaga(jogadas);

    /* testa alínea 1.3 */
    jogadas = vetor_novo();
    for(i=0; i<13; i++)
        vetor_insere(jogadas, vencedores_[i], i);
    puts("");
    for(i=0; i<4; i++)
        fprintf(stderr, "Numero de vitorias do/a %s: %d\n", nomes_[i], numero_vitorias(jogadas, nomes_[i]));

    vetor_apaga(jogadores);
    lista_apaga(baralho);
    lista_apaga(ordem);
    vetor_apaga(jogadas);

    return 0;
}
