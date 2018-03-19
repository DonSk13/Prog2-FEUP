#include "armazem.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * funcoes do armazem
 */
/* alinea b) */
armazem* armazem_novo(int comprimento, int altura)
{
	armazem *result;

	result = (armazem*)malloc(sizeof(armazem));

	if (result == NULL)
	{
		return NULL;
	}

	result->comprimento = comprimento;
	result->altura = altura;
	result->contentores = fila_nova();

	//printf("Armazém: %d %d\n", result->comprimento, result->altura);
	return result;
}

/* alinea c) */
int armazem_vazio(armazem* armz)
{
	if (armz == NULL || fila_tamanho(armz->contentores) == 0)
	{
		return 1;
	}

	return 0;
}

/* alinea d) */
int armazem_cheio(armazem* armz)
{
	/* devolve nao cheio */
	if (armazem_vazio(armz))
	{
		return 0;
	}

	if (fila_tamanho(armz->contentores) == armz->comprimento && fila_back(armz->contentores)->tamanho == armz->altura)
	{
		return 1;
	}
	return 0;
}

/* alinea e) */
int armazenar_contentor(armazem* armz, contentor* contr)
{
    pilha *atual = fila_back(armz->contentores);
    if(!atual || (atual->tamanho >= armz->altura && fila_tamanho(armz->contentores) < armz->comprimento))
    {
        atual = pilha_nova();
        fila_push(armz->contentores, atual);
    }

    if(atual->tamanho < armz->altura)
    {
        pilha_push(atual, contr);
        return 1;
    }

	return 0;

}

/* alinea f) */
contentor* expedir_contentor(armazem* armz)
{
   pilha *atual = fila_front(armz->contentores);
    if(!atual)
    {
        return 0;
    }

    contentor *topo = pilha_top(atual);
    contentor *novo = contentor_novo(topo->destino, topo->valor);
    pilha_pop(atual);
    if(pilha_tamanho(atual) == 0)
    {
        fila_pop(armz->contentores);
    }
    return novo;
}