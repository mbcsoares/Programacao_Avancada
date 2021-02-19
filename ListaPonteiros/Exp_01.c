#include<stdio.h>
#include<stdlib.h>

void trocaErrada(int a, int b) {
	int tmp = 0;

	printf("FuncTrocaErrada -> a = %d; b = %d \n", a, b);

	tmp = a;
	a = b;
	b = tmp;

	printf("FuncTrocaErrada -> a = %d; b = %d \n", a, b);
}

void trocaCerta(int *a, int *b) {
	int tmp = 0;

	printf("FuncTrocaCerta -> a = %d; b = %d \n", *a, *b);

	tmp = *a;
	*a = *b;
	*b = tmp;

	printf("FuncTrocaCerta -> a = %d; b = %d \n", *a, *b);
}

int mainExp01(void){
	int x = 3;
	int y = 4;

	printf("Prog -> x = %d; y = %d \n", x, y);

	trocaCerta(&x, &y);

	printf("Prog -> x = %d; y = %d \n", x, y);
	system("pause");
	return 0;
}

void mainExp02(void)
{
	int *x, i;
	x = malloc(10 * sizeof(int));

	for ( i = 0; i < 10; i++)
	{
		x[i] = 101 * i;
	}

	x[1] = 3;

	for (i = 0; i < 10; i++)
	{
		printf("%d, ", x[i]);
	}

	system("pause");
}