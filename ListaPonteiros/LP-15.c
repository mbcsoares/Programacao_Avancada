#include<stdio.h>
#include<stdlib.h>

//-1 -> Antes
//0 -> Iguais
//1 -> Depois

int comparaCrescente(float *a, float *b) //funcao de comparacao base para oredenacao com a funcao Ordenacao
{
	if (*a == *b)
	{
		return 0; //a e b sao iguais
	}
	else
	{
		if (*a < *b)
		{
			return -1; //a deve vir antes de b
		}
		else
		{
			return 1; //a deve ficar depois de b
		}
	}
}

int comparaDecrescente(float *a, float *b) //funcao de comparacao base para oredenacao com a funcao Ordenacao
{
	if (*a == *b)
	{
		return 0; //a e b sao iguais
	}
	else
	{
		if (*a < *b)
		{
			return 1; //a deve ficar depois de b
		}
		else
		{
			return -1; //a deve vir antes de b
		}
	}
}

void Ordenacao(float *lista, int num, int (*ptr)(float *a, float *b))
{
	float *Menor, Primeiro;

	Primeiro = *lista;
	Menor = lista;

	if (num != 1)
	{
		for (int i = 0; i < num; i++)
		{
			if (ptr(Menor, (lista + i)) == 1)
			{
				Menor = (lista + i);
			}
		}

		*lista = *Menor;
		*Menor = Primeiro;

		Ordenacao(lista + 1, num - 1, ptr);
	}
}


void main(void)
{
	float* x;
	int n, ordem;

	printf("LISTA DE EXERCICOS (PONTEIROS) - QUESTAO 15 \n\n");

	printf("Digite o numero de valores do tipo float a serem oredenados: ");
	scanf_s("%d", &n);

	x = malloc(n * sizeof(float)); //definicao do array em locacao dinanima

	for (int j = 0; j < n; j++) //alocacao dos valores digitados pelo usuario
	{
		printf("Deigite um valor: ");
		scanf_s("%f", (x + j));
	}

	printf("Digite uma opcao de ordem(0 para crescente; 1 para decrescente): ");
	scanf_s("%d", &ordem);

	if (ordem == 1)
	{
		Ordenacao(x, n, comparaDecrescente); //vetor x, numero de elementos de x (n), tamanho de cada elemento de x, funcao de comparacao
	}
	else
	{
		Ordenacao(x, n, comparaCrescente);
	}

	printf("Valores ordenados: \n");

	for (int i = 0; i < n; i++) //escrita dos valores inseridos apos oredenacao
	{
		printf("%f; ", *(x + i));
	}

	free(x);

	system("pause");
}