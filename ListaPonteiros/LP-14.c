//#include<stdio.h>
//#include<stdlib.h>
//
//int comparaCrescente(const void *a, const void	*b) //funcao de comparacao base para oredenacao com a funcao qsort
//{
//	if (*(float*)a == *(float*)b)
//	{
//		return 0; //a e b sao iguais
//	}
//	else
//	{
//		if (*(float*)a < *(float*)b)
//		{
//			return -1; //a deve vir antes de b
//		}
//		else
//		{
//			return 1; //a deve ficar depois de b
//		}
//	}
//}
//
//void main(void)
//{
//	float *x;
//	int n;
//
//	printf("LISTA DE EXERCICOS (PONTEIROS) - QUESTAO 14 \n\n");
//
//	printf("Digite o numero de valores do tipo float a serem oredenados: ");
//	scanf_s("%d", &n);
//
//	x = malloc(n * sizeof(float)); //definicao do array em locacao dinanima
//
//	for (int j = 0; j < n; j++) //alocacao dos valores digitados pelo usuario
//	{
//		printf("Deigite um valor: ");
//		scanf_s("%f", (x + j));
//	}
//
//	qsort(x, n, sizeof(float), comparaCrescente); //vetor x, numero de elementos de x (n), tamanho de cada elemento de x, funcao de comparacao
//
//	printf("Valores ordenados: \n");
//
//	for (int i = 0; i < n; i++) //escrita dos valores inseridos apos oredenacao
//	{
//		printf("%f; ", *(x + i));
//	}
//
//	free(x);
//
//	system("pause");
//}