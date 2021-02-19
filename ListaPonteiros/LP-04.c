#include<stdio.h>
#include<stdlib.h>

void main(void) {
	int i = 5, j = 10;
	int *p, *q;

	printf("LISTA DE EXERCICOS (PONTEIROS) - QUESTAO 04 \n\n");
	printf("CONSIDERACOES: int i = 5, j = 10; &i = %p, &j = %p; int *p, *q \n\n", &i, &j);
	printf("A) p = &i -> %p => Ok! \n", p = &i);
	printf("B) *q = &j => Nao Ok! (O ponteiro para inteiro q nao foi declarado ate o momento. Portanto, nao representa nenhum espaco na memoria que possa ter seu valor alterado.) \n");
	printf("C) p = &*&i = &i -> %p => Ok! \n", p = &*&i);
	printf("D) i = (*&)j => Nao Ok! (Erro de sintaxe: os sinais operadores estao isolados da variavel j.) \n");
	printf("E) i = *&j = j = %d => Ok! \n", i = *&j);
	printf("F) i = &&j => Nao Ok! (Erro de sintaxe. Correcao: i = &(&j) = %d . Obs.: &j = %d) \n", i = &(&j), &j);
	printf("G) q = *p = %d => Ok! (*p em hexadecimal: %p = &j) ", q = *p, *p);
	printf("H) i = (*p)' + *q => Nao Ok! (Erro de sintaxe: O simbolo ' eh usado indentificar valores do tipo caracter. Correcao: i = (*p) + *q = %d) \n", i = (*p) + *q);

	system("pause");
}