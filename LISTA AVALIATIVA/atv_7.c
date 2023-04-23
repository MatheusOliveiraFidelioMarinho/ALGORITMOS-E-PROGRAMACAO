/*Escreva um programa que leia um número inteiro, maior ou igual a zero, do usuário.
Imprima o enésimo termo da sequência de Fibonacci. Essa sequência começa no termo de
ordem zero, e, a partir do segundo termo, seu valor é dado pela soma dos dois termos
anteriores. Alguns termos dessa sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34*/
#include<stdio.h>
int main(){

    signed int n1 = 0;
    signed int n2 = 1;
    int n3 = 0;

    printf("Insira um numero:");
    scanf("%d",&n3);
                
    printf("Sequencia de Fibonacci:\n");
    printf(" %i %i", n1, n2);

    for(int i = 0; i <= n3; i++){

        n1 += n2;
        n2 += n1;

        printf(" %i %i", n1, n2);

    }

    return 0; 
}