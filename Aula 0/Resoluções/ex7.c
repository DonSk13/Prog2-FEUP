#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ler_notas (float *notas)
{
	int i=0;
	float nt, np;

	//printf("Introduza as notas:\n");

	while (scanf("%f %f", &nt, &np) == 2)
	{
		//vetor com as notas finais, em que i é igual à quantidade de notas
		notas[i] = (float) ((nt*0.6)+(np*0.4));
		i++;
	}
	return i;
}

float media(float *notas, int n)
{
	float sum=0;

	for (int i = 0; i < n; ++i)
	{
		if (notas[i]>=9.3 && notas[i]<9.5)
		{
			sum = sum+9.5;
		}

		else
		{
			sum = sum+notas[i];
		}
	}

	return sum / (float) n;;
}

int main()
{    
	//Como executar corretamento o ficheiro notas.txt?

/*	FILE *f;
	int m=0;
	char str[100];
	//Leitura do TXT
    f = fopen("notas.txt", "r");
    	if(f==NULL)
    	{
    		printf("Erro de ficheiro\n");
    		return 0;
    	}

    //Enquanto existirem linhas no TXT
    while (fgets(str, 100, f) != NULL) 
    {
    	str[strlen(str)-1] = '\0';
    	m++;
    	//printf("%s\n", str);
    }
*/
	float notas[100] = {0};
   	int n = ler_notas(notas);
    printf("A media das notas da turma foi %.2f\n", media(notas, n));
    return 0;
}
