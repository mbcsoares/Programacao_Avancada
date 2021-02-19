//#include<stdio.h>
//#include<stdlib.h>
//
//int main(void) {
//	int i = 3, j = 5;
//	int *p, *q;
//
//	p = &i; q = &j;
//
//	printf("LISTA DE EXERCICOS (PONTEIROS) - QUESTAO 02 \n\n");
//	printf("A) p == &i -> %d (0 -> Falso; 1 -> Verdadeiro) \n", p == &i);
//	printf("B) *p - *q -> %d \n", *p - *q);
//	printf("C) **&p -> %d \n", **&p);
//	printf("   p = &i -> %p (Guarda o enderecamento da variavel i) \n", p); 
//	printf("   &p -> %p (o enderecamento da variavel p) \n", &p);
//	printf("   *&p -> %p (conteudo do enderecamento &p = enderecamento de i) \n", *&p);
//	printf("   **&p -> %d (conteudo do conteudo do enderecamento &p = conteudo do enderecamento de i = valor de i) \n", **&p);
//	printf("D) 3 - *p/(*q) + 7 -> %d \n", 3 - *p / (*q) + 7);
//
//	system("pause");
//	return 0;
//}