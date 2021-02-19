#include<stdio.h>
#include<stdlib.h>

void SomarVetores(int num, int* v1, int* v2, int* vsoma)
{
	for (int i = 0; i < num; i++)
	{
		*(vsoma + i) = *(v1 + i) + *(v2 + i);
	}
}

void EscreverElementos(int num, int *vetor, char nome[10])
{
	printf("\n%s = [", nome);
	int i;

	for (i = 0; i < num - 1; i++)
	{
		printf("%d, ", *(vetor + i));
	}

	printf("%d]; \n", *(vetor + i));

}

void main(void)
{
	int *vetor_1, *vetor_2, *vetorSoma;
	int n, verf = 0;
	
	printf("LISTA DE EXERCICOS (PONTEIROS) - QUESTAO 17 \n\n");

	printf("Insira o numero de elementos dos vetores: ");
	scanf_s("%d", &n);

	printf("Utilizar vetores com valores aleatorios? (Digite: 0 ou 1; 0 => Sim ou 1 => Nao): ");
	scanf_s("%d", &verf);

	vetor_1 = malloc(n * sizeof(int));
	vetor_2 = malloc(n * sizeof(int));
	vetorSoma = malloc(n * sizeof(int));

	if (verf == 1)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Vetor_1[%d] = ", j);
			scanf_s("%d", (vetor_1 + j));
			printf("Vetor_2[%d] = ", j);
			scanf_s("%d", (vetor_2 + j));
		}
	}
	else
	{
		for (int l = 0; l < n; l++)
		{
			if (l % 2 == 0)
			{
				*(vetor_1 + l) = 2 * l;
				*(vetor_2 + l) = 7 * l;
			}
			else
			{
				*(vetor_1 + l) = 11 * l;
				*(vetor_2 + l) = 1 * l;
			}
		}
	}

	SomarVetores(n, vetor_1, vetor_2, vetorSoma);

	EscreverElementos(n, vetor_1, "Vetor1");
	EscreverElementos(n, vetor_2, "Vetor2");
	EscreverElementos(n, vetorSoma, "VetorSoma");

	free(vetorSoma);
	free(vetor_2);
	free(vetor_1);
}