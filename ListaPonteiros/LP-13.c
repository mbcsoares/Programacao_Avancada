#include<stdio.h>
#include<stdlib.h>

void ordemCresc(int num, float *lista)
{
	float *Minimo, temp;

	temp = *lista;
	Minimo = lista;

	if (num != 1)
	{
		for (int i = 0; i < num; i++)
		{
			if (*Minimo > *(lista + i))
			{
				Minimo = (lista + i);
			}
		}

		*lista = *Minimo;
		*Minimo = temp;

		ordemCresc(num - 1, (lista + 1));
	}
}

void main(void)
{
	float *x;
	int n;

	printf("LISTA DE EXERCICOS (PONTEIROS) - QUESTAO 13 \n\n");

	printf("Digite o numero de valores do tipo float a serem oredenados: ");
	scanf_s("%d", &n);

	x = malloc(n * sizeof(float));

	for (int j = 0; j < n; j++)
	{
		printf("Deigite um valor: ");
		scanf_s("%f", (x + j));
	}

	ordemCresc(n, x);

	printf("Valores ordenados: \n");

	for (int i = 0; i < n; i++)
	{
		printf("%f; ", *(x + i));
	}

	free(x);

	system("pause");
}