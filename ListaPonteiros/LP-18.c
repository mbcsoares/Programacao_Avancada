#include<stdio.h>
#include<stdlib.h>

void MultiplicacaMatrizes(int nLinhasA, int nColunA, int nColunB, float **matrizA, float **matrizB, float **matrizRes)
{
	for (int i = 0; i < nLinhasA; i++)
	{
		for (int j = 0; j < nColunB; j++)
		{
			for (int l = 0; l < nColunA; l++)
			{
				*(*(matrizRes +i) + j) = *( *(matrizA + i) + l) * ( *( *(matrizB + l) + i) );
			}
		}
	}
}

void EscreverElementos(int numL, int numC, float **matriz, char nome[15])
{
	printf("\n%s = [", nome);
	int i, j;

	for (i = 0; i < numL - 1; i++)
	{
		for (j = 0; j < numC - 1; j++)
		{
			printf("%d, ", *(*(matriz + i) + j));
		}

		printf("%d \n ", *(*(matriz + i) + j));
	}
}

//void AlocarMatriz(int numL, int numC, int **matriz)
//{
//	matriz = malloc(numL * sizeof(int*));
//	*matriz = malloc(numL * numC * sizeof(int));
//
//	for (int i = 1; i < numL; i++)
//	{
//		*(matriz + i) = *(matriz + i - 1) + numC;
//	}
//}

void EscreverMatriz(int numL, int numC, float **matriz, char nome[10])
{
	for (int i = 0; i < numL; i++)
	{
		for (int j = 0; j < numC; j++)
		{
			printf("%s[%d][%d] = ", nome, i, j);
			scanf_s("%d", (*(matriz + i) + j));
		}
	}
}

//void DefinirMatriz(int numL, int numC, int **matriz, char nome[10])
//{
//	AlocarMatriz(numL, numC, matriz);
//	EscreverMatriz(numL, numC, matriz, nome);
//}

void main(void)
{
	float **MatrizA, **MatrizB, **MatrizR;
	int nLA, nCA, nLB, nCB;

	printf("LISTA DE EXERCICOS (PONTEIROS) - QUESTAO 18 \n\n");

	printf("Matriz A \n");
	printf("Insira o numero de linhas: ");
	scanf_s("%d", &nLA);
	printf("Insira o numero de colunas: ");
	scanf_s("%d", &nCA);

	printf("Matriz B \n");
	printf("Insira o numero de linhas: ");
	scanf_s("%f", &nLB);
	printf("Insira o numero de colunas: ");
	scanf_s("%f", &nCB);

	MatrizA = malloc(nLA * sizeof(float*));
	*MatrizA = malloc(nLA * nCA * sizeof(float));

	for (int i = 1; i < nLA; i++)
	{
		*(MatrizA + i) = *(MatrizA + i - 1) + nCA;
	}

	MatrizB = malloc(nLB * sizeof(float*));
	*MatrizB = malloc(nLB * nCB * sizeof(float));

	for (int i = 1; i < nLA; i++)
	{
		*(MatrizB + i) = *(MatrizB + i - 1) + nCB;
	}

	MatrizR = malloc(nLA * sizeof(float*));
	*MatrizR = malloc(nLA * nCB * sizeof(float));

	for (int i = 1; i < nLA; i++)
	{
		*(MatrizR + i) = *(MatrizR + i - 1) + nCB;
	}

	EscreverMatriz(nLA, nCA, MatrizA, "MatrizA");
	EscreverMatriz(nLB, nCB, MatrizB, "MatrizB");

	MultiplicacaMatrizes(nLA, nCA, nCB, MatrizA, MatrizB, MatrizR);

	EscreverElementos(nLA, nCA, MatrizA, "MatrizA");
	EscreverElementos(nLB, nCB, MatrizB, "MatrizB");
	EscreverElementos(nLA, nCB, MatrizR, "MatrizResposta");

	free(*MatrizA);
	free(MatrizA);
	free(*MatrizB);
	free(MatrizB);
	free(*MatrizR);
	free(MatrizR);
}