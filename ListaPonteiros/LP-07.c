#include<stdio.h>
#include<stdlib.h>

void main(void)
{
	int pulo[10];

	printf("LISTA DE EXERCICOS (PONTEIROS) - QUESTAO 07 \n\n");

	for (int i = 0; i < 10; i++)
	{
		pulo[i] = i + 1;

		printf("pulo[%d] = %d ; &pulo[%d] -> %p \n", i, pulo[i], i, &pulo[i]);
	}

	printf("\n*(pulo + 2) = %d => Correto! \n", *(pulo + 2));
	printf("*(pulo + 4) = %d \n", *(pulo + 4));
	printf("pulo + 4 -> %p \n", pulo + 4);
	printf("pulo + 2 -> %p \n", pulo + 2);

	system("pause");
}