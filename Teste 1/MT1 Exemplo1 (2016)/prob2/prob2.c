#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    char palavra[100];
    int ocorrencias;
} registo;

/****************************************************/
/*              Funcoes a implementar               */
/****************************************************/

/*** exercicio 2.1 ***/
registo *analisarFicheiro(FILE *ficheiro, int *num_palavras)
{
    //Verificação de parametros
    if (ficheiro == 0 || num_palavras == 0)
    {
        return;
    }

    //Declaração de variáveis
    registo *resultados=0, *aux;
    char word[100];
    int count=0;

    //while (fgets(palavra, 100, ficheiro)!=NULL)
    while (fscanf(ficheiro, "%s", word) == 1)
    {
        //printf("%s\n", palavra); //Teste
        for (int i = 0; i <= count; ++i)
        {
            if (i == count)
            {
                aux = realloc(resultados, sizeof(*resultados)*(count+1));

                if (aux == NULL)
                {
                    free (resultados);
                    return 0;
                }

                resultados = aux;
                strcpy(resultados[count].palavra, word);
                resultados[count].ocorrencias = 1;
                count++;
                break;
            }

            else if(strcmp(resultados[i].palavra, word) == 0)
            {
                ++resultados[i].ocorrencias;
                break;
            }
        }
    }

    *num_palavras = count; //Indicação do número de palavras
    return resultados; //retorna o vetor resultados
}

/*** exercicio 2.2 ***/
void gerarRelatorio(FILE *ficheiro, registo *resultados, int num_palavras)
{
    if (ficheiro == 0 || resultados == 0 || num_palavras == 0)
    {
        return;
    }

    registo *aux; //registo auxiliar

    fprintf(ficheiro, "Palavras encontradas:\n---------------------\n");

    //Ciclo que irá escrever no ficheiro enquanto houver palavras
    for (int i = 0; i < num_palavras; ++i)
    {
        aux = resultados+i; //avança nas palavras
        fprintf(ficheiro, "%d: %s (%d)\n", i+1, aux->palavra, aux->ocorrencias);
    }
}

/****************************************************/
/*     Funcoes ja implementadas (nao modificar)     */
/****************************************************/

int main() {
    FILE *fin, *fout;
    //char nomeIn[50], nomeOut[50];
    registo *resultados;
    int n;

/*  printf("Ficheiro de entrada? ");
    scanf("%s", nomeIn);
    printf("Ficheiro de saida? ");
    scanf("%s", nomeOut);*/

    fin = fopen("dialogo.txt", "r");
    if (fin == NULL)
        return 1;

    fout = fopen("relatorio.txt", "w");
    if (fout == NULL)
        return 1;

    resultados = analisarFicheiro(fin, &n);
    gerarRelatorio(fout, resultados, n);

    fclose(fin);
    fclose(fout);
    free(resultados);

    return 0;
}
