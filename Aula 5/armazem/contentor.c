#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "contentor.h"

/* alinea a) */
/**
 *  \brief cria um novo contentor
 *  \param dest destino do contentor
 *  \param val valor das mercadorias no contentor
 *  \return apontador para o contentor; NULL se erro
 */
contentor* contentor_novo(char* dest, float val)
{
	contentor *result;
	int size;
	
	result = (contentor*)malloc(sizeof(contentor));
	
	if (result == NULL)
	{
		return NULL;
	}

	size = strlen(dest);
	result->destino = malloc((size+1)*(sizeof(char))); //Acontece devido ao "/0"
	
	strcpy(result->destino, dest);
	result->valor=val;
	//printf("Contentor: %s %.1f\n", result->destino, result->valor);
	return result;
}

/**
 *  \brief apaga contentor (liberta memoria correspondente)
 *  \param contr apontador para o contentor
 *  \remark se contr = NULL retorna sem fazer nada
 */
void contentor_apaga(contentor* contr)
{
	if (contr == NULL)
	{
		return;
	}

	free(contr->destino);
	free(contr);
}

/**
 *  \brief imprime dados do contentor
 *  \param contr apontador para o contentor
 */
void contentor_imprime(contentor* contr)  {
	if (contr == NULL)
		printf("Contentor nulo\n");
	else
		printf("Destino: %s, valor da carga: %.2f K Euros\n", contr->destino, contr->valor);
}
