#include<stdio.h>
#include<stdlib.h>

void main(void)
{
	float aloha[10], coisas[10][5], *pf, value = 2.2;
	int i = 3;

	printf("LISTA DE EXERCICOS (PONTEIROS) - QUESTAO 11 \n\n");

	printf("A) aloha[2] = value = %.1f => Ok!\n", aloha[2] = value);
	printf("B) -> Ok! (Na funcao scanf, o entdereco do primeiro elemento de aloha eh inserido para q o usuario altere o valor atribuido a esse elemento)");
	scanf("%f", &aloha);
	printf("C) aloha = \"value\" => Nao Ok! (Tipos diferentes: Associacao de um tipo array de float com cadeia de caracter, string) \n");
	printf("D) %.1f => Nao Ok! (Nao eh possivel converter hexadecimal em ponto flutuante) \n", aloha);
	printf("E) coisas[4][4] = aloha[3] = %.1f => Ok! (Associacao de dois valores do tipo float) \n", coisas[4][4] = aloha[3]);
	printf("F) coisas[5] = aloha => Ok! (Associacao entre dois arrays de float \n");
	printf("G) pf = value => Nao OK! (Tipos diferentes: um tipo ponteiro para float nao pode ser associado a um float) \n");
	printf("H) pf = aloha -> %p => Ok! (Atribuicao do endereco do priemiro elemento de aloha ao ponteiro pf) \n", pf = aloha);


	system("pause");
}