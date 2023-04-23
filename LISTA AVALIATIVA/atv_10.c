/*Faça um programa que leia 10 inteiros e imprima sua média.*/
#include <stdio.h>

int main() {
    int numeros[10], i, soma = 0;
    float media;
    printf("Digite 10 numeros inteiros:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }
    media = (float) soma / 10;
    printf("A media dos 10 números e: %.2f\n", media);
    return 0;
}