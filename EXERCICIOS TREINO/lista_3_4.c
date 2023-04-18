#include<stdio.h>
int main(){
    int n1, i, nimpar = 9;
    printf("Digite um numero inteiro: ");
    scanf("%d", &n1);

    for(i=0; i<n1; i++){
        nimpar += 2;
        if(nimpar > n1){
            break;
        }
        printf("%d\n", nimpar);
    }
    return 0;
}