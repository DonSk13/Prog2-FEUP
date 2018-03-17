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
	/* devolve nao ha' espaco */
	pilha *p= pilha_nova();

	if (armz == NULL || contr == NULL || armazem_cheio(armz)) 
	{
		return 0;
	}

	if (armz)
	return 0;

// (...)

}

/* alinea f) */
contentor* expedir_contentor(armazem* armz)
{
	return NULL;
}