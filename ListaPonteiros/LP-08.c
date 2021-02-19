#include<stdio.h>
#include<stdlib.h>

void main(void)
{
	int mat[4], * p, x;

	printf("LISTA DE EXERCICOS (PONTEIROS) - QUESTAO 08 \n\n");

	for (int i = 0; i < 4; i++)
	{
		mat[i] = i + 1;

		printf("mat[%d] = %d ; &mat[%d] -> %p \n", i, mat[i], i, &mat[i]);
	}

	printf("\np = mat + 1 -> %p (Expressao valida pois atribui a uma variavel do tipo ponteiro o valor de um endereco de meomoria, referente ao segundo elelemnto do array mat) \n", mat + 1);
	printf("p = mat -> %p (Expressao valida pois atribui a uma variavel do tipo ponteiro o valor de um endereco de meomoria, referente ao primeiro elelemnto do array mat) \n", mat);
	printf("p = `mat (Erro de sintaxe: Sinal ` nao definico) \n");
	printf("x = (*mat) = %d (Expressao valida pois atribui a variavel inteira x o valor do primeiro elemento do array mat) \n", (*mat));

	system("pause");
}