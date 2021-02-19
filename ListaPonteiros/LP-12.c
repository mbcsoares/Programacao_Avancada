#include<stdio.h>
#include<stdlib.h>

int soma(int a, int b)
{
	return a + b;
}

int maior(int a, int b)
{
	if (a>b)
	{
		return a;
	}

	return b;
}

int menor(int a, int b)
{
	if (a < b)
	{
		return a;
	}

	return b;
}

int executa(int (*ptr)(int, int), int m, int n)
{
	return ptr(m, n);
}

void funcaoPrincipal(void)
{
	int num = 2, x, Maximo, Minimo, Total = 0;

	printf("\n-----PROGRAMA PARA APLICACAO-----\n\n");

	printf("Digite o numero de inteiros a serem trabalhados (maior ou igual a 2): ");
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++)
	{
		printf("Digite um inteiro: ");
		scanf_s("%d", &x);

		if (i == 0)
		{
			Maximo = x;
			Minimo = x;
		}

		printf("Maior numero digitado: %d; \n", Maximo = executa(maior, Maximo, x));
		printf("Menor numero digitado: %d; \n", Minimo = executa(menor, Minimo, x));
		printf("Total acumulado: %d; \n", Total = executa(soma, Total, x));
	}
}

void main(void)
{
	printf("LISTA DE EXERCICOS (PONTEIROS) - QUESTAO 12 \n\n");

	printf("Um ponteiro (= apontador = pointer) eh um tipo especial de variavel que armazena um endereco de memoria, que pode esta relacioando a outra variavel. \n");
	printf("Um ponteiro tambem pode ter o valor null, endereco vazio, que iviabiliza as operacoes com este.\n");
	printf("Para acessar o conteudo de uma posicao de memoria, cujo endereço esta armazenado em um ponteiro, usa-se o operador de derreferencia (*). \n\n");
	printf("Uma funcao eh um conjunto de instrucoes armazenadas na memoria. Assim, pode-se acessar uma funcao por meio de um ponteiro que aponte para onde esta funcao esta na memoria.\n");
	printf("O uso de ponteiros para funcoes em C serve principalmente para definir, em tempo de execucao, qual funcao sera executada, sem a necessidade de escrever o nome desta funcao de forma explicita naquele ponto do codigo. \n");
	printf("Com isso, permite-se a criacao de codigos mais genericos. \n\n");
	printf("Formato de um ponteiro para funcao: tipo_de_retorno (*nome_do_parametro)(lista_de_tipos_de_entrada)\n");
	printf("Exemplo: int *ptr(int, int) => Ponteiro para uma funcao qualquer que, obrigatoriamente, retorne um inteiro e receba como parametros dois inteiros. \n\n");
	printf("Outra caracteristica importante de ponteiros para funcoes eh que eles viabilizam que funcoes recebam como paramentros outras funcoes. \n");
	printf("Exemplo: int FuncaoPrincipal(int (*ptr)(int, int), int x, int y){ return ptr(x, y); } => Funcao que recebe como parametro uma funcao qualquer que, obrigatoriamente, retorne um inteiro e receba como parametros dois inteiros. \n\n");

	funcaoPrincipal();

	system("pause");
}