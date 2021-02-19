//#include<stdio.h>
//#include<stdlib.h>
//
//void main(void) {
//	int valor;
//	int *p1;
//	float temp;
//	float *p2;
//	char aux;
//	char *nome = "Ponteiros";
//	char *p3;
//	int idade;
//	int vetor[3];
//	int *p4;
//	int *p5;

//	printf("LISTA DE EXERCICOS (PONTEIROS) - QUESTAO 05 \n\n");

//	/* (a) */
//	valor = 10;
//	p1 = &valor;
//	*p1 = 20; //=> valor = 20
//	printf("%d \n", valor);
//
//	/* (b) */
//	temp = 26.5;
//	p2 = &temp;
//	*p2 = 29.0; //=> temp = 29.0
//	printf("%.1f \n", temp);
//
//	/* (c) */
//	p3 = &nome[0];
//	aux = *p3; //=> aux = P
//	printf("%c \n", aux);
//
//	/* (d) */
//	p3 = &nome[4];
//	aux = *p3; //=> aux = e
//	printf("%c \n", aux);
//
//	/* (e) */
//	p3 = nome; //p3 -> endereco do primeiro caracter da cadeia de char nome
//	printf("%c \n", *p3); //*p3 = P
//
//	/* (f)*/
//	p3 = p3 + 4; //p3 -> endereço 0 + 4 = 4 - > endereco do quinto caracter da cadeia de char nome
//	printf("%c \n", *p3); //*p3 = e
//
//	/* (g) */
//	p3--;//p3 -> endereço 4-- = 4 - 1 = 3 - > endereco do quarto caracter da cadeia de char nome
//	printf("%c \n", *p3); //*p3 = t
//
//	/* (h) */
//	vetor[0] = 31;
//	vetor[1] = 45;
//	vetor[2] = 27;
//	p4 = vetor; //p4 -> endereco do primeiro elemento do array vetor
//	idade = *p4; //idade = *p4 = vetor[0] = 31
//	printf("%d \n", idade);
//
//	/* (i) */
//	p5 = p4 + 1; //p5 -> endereco do primeiro elemento de  vetor + 1 = segundo elemento de vetor
//	idade = *p5; //idade = *p5 = vetor[1] = 45
//	printf("%d \n", idade);
//
//	/* (j) */
//	p4 = p5 + 1; //p4 -> endereco do segundo elemento de vetor + 1 = terceiro elemento de vetor
//	idade = *p4; //idade = *p4 = vetor[2] = 27
//	printf("%d \n", idade);
//
//	/* (l) */
//	p4 = p4 - 1; //p4 -> endereco do terceiro elemento de vetor - 1 = segundo elemento de vetor
//	idade = *p4; //idade = *p4 = vetor[1] = 45
//	printf("%d \n", idade);
//
//	/* (m) */
//	p5 = &vetor[2] - 1; //p5 -> endereco do terceiro elemento de vetor - 1 = segundo elemento de vetor
//	printf("%d \n", *p5); //*p5 = vetor[1] = 45
//
//	/* (n) */
//	p5; ///p5 -> segundo elemento de vetor
//	printf("%d \n", *p5); //*p5 = vetor[1] = 45
//
//	system("pause");
//}