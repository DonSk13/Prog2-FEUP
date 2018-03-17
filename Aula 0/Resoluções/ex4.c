#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ordenado(int src[], int n)
{
   int i, aux;

   aux = src[0];

   for(i = 0; i < n-1; i++)
   { 
      if (src[i] < aux)
      {
         return  0;    
      }
      aux = src[i];
   }   
   return 1;     
}

int main()
{
   int n, i, *v;

   printf("Introduza o número de números: ");
   scanf("%d", &n);

   if (n>100)
   {
      printf("O número de números não pode ser superior a 100!\nEscolha um número inferior.\n");
      n=100;
   }

   else
   {
      v = (int*) malloc(sizeof(int)*n);

      for (i = 0; i < n; i++)
      {
         printf("Introduza %dº número: ", i+1);
         scanf("%d", &v[i]);
      }

      if (ordenado(v, n))
      {
         printf("\nO vetor está ordenado!\nElementos do vetor por orderm decrescente:\n");
         printf("{");

         for (i = n-1; i >= 0; i--)
         {
            printf("%d", v[i]);

            if (i>0)
            {
            printf(",");
            }
         }
         printf("}");
      }
      else
      {
         printf("\nO vetor não está ordenado!\n");
      }
   }
}