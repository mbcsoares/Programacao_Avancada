#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int comparaCrescente(const void *a, const void *b) //funcao de comparacao base para oredenacao com a funcao qsort
{
	if (*(float*)a == *(float*)b)
	{
		return 0; //a e b sao iguais
	}
	else
	{
		if (*(float*)a < *(float*)b)
		{
			return -1; //a deve vir antes de b
		}
		else
		{
			return 1; //a deve ficar depois de b
		}
	}
}

void Ordenacao(float* lista, int num, int (*ptr)(const void *a, const void *b))
{
	float* Menor, Primeiro;

	for (int i = 0; i < num; i++)
	{
		Primeiro = *(lista + i);
		Menor = (lista + i);

		for (int j = i + 1; j < num; j++)
		{
			if (ptr(Menor, (lista + j)) == 1)
			{
				Menor = (lista + i);
			}
		}

		*lista = *Menor;
		*Menor = Primeiro;
	}
}

void main(void)
{
	float tempo_1, tempo_2, *x_1, *x_2;
	time_t tInicio_1, tFim_1, tInicio_2, tFim_2;
	int n = 20000;

	printf("LISTA DE EXERCICOS (PONTEIROS) - QUESTAO 16 \n\n");

	x_1 = malloc(n * sizeof(float));
	x_2 = malloc(n * sizeof(float));

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			*(x_1 + i) = 1.01 * i;
			*(x_2 + i) = 1.05 * i;
		}
		else
		{
			*(x_1 + i) = 1.05 * i;
			*(x_2 + i) = 1.01 * i;
		}
	}

	printf("TESTES DE FUNCOES - COMPARACAO DE TEMPOS DE EXECUCAO \n\n");
	printf("1a - Funcao qsort() \n");

	tInicio_1 = time(NULL);

	qsort(x_1, n, sizeof(float), comparaCrescente);

	tFim_1 = time(NULL);

	for (int j = 0; j < n; j++)
	{
		printf("%.11f; ", *(x_1 + j));
	}

	tempo_1 = difftime(tFim_1, tInicio_1);

	printf("\nTempo de execucao: %.1f\n\n", tempo_1);


	printf("2a - Funcao Ordenacao() \n");

	tInicio_2 = time(NULL);

	Ordenacao(x_2, n, comparaCrescente);

	tFim_2 = time(NULL);

	for (int l = 0; l < n; l++)
	{
		printf("%.11f; ", *(x_1 + l));
	}

	tempo_2 = difftime(tFim_2, tInicio_2);

	printf("\nTempo de execucao: %.1f\n\n", tempo_2);

	system("pause");
}