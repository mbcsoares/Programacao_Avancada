//#include<stdio.h>
//#include<stdlib.h>
//
//void main(void)
//{
//	float vet[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
//	float *f;
//	int i;
//	f = vet;

//	printf("LISTA DE EXERCICOS (PONTEIROS) - QUESTAO 06 \n\n");

//	printf("contador / valor / valor / endereco / endereco \n");
//
//	for (i = 0; i <= 4; i++)
//	{
//		printf("i = %d / ", i);
//		printf("vet[%d] = %.1f / ", i, vet[i]); //valor de vet[i]
//		printf("*(f + %d) = %.1f / ", i, *(f + i)); //valor armazenada no endereco (f + i) = vet[0 + i]
//		printf("&vet[%d] = %x / ", i, &vet[i]); //endereco de vet[i]
//		printf("(f + %d) = %x \n", i, f + i); //f -> endereco do primeiro elemento da cadeia vet = endereco de vet[0] de vet[0]; (f + i) -> endereco de vet[0 + i]
//	}
//
//	system("pause");
//}