/*Faça um algoritmo que leia um número positivo e imprima seus divisores. Exemplo:
Os divisores do número 66 são: 1, 2, 3, 6, 11, 22, 33 e 66.*/
#include<stdio.h>
int main(){

    int n1;
    printf("Informe um numero:");
    scanf("%d", &n1);
    printf("Os divisores do numeros %d sao:", n1);
    
    for(int i = 1; i<=n1; i++){
        if(i%2 ==0){
            printf("%d ", i);
        }
    }


    return 0;
}