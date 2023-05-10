/*Faça um algoritmo que leia um vetor de até 80 elementos. 
Após a leitura de todos os dados, leia um número e verifique se existem elementos no vetor iguais ao número lido. 
Se existirem, escrever, em uma tela limpa, quantas vezes eles aparecem e quais as posições em que eles estão armazenados no vetor.*/

#include<stdio.h>
int main(){
    int vetor[6], i, nBusca, posicao[6], contador = 0;

    //preencher o vetor de numeros inteiros
    for(i=0;i<6;i++){
       printf("Digite o valor:\n");
       scanf("%d", &vetor[i]);
       
    }
    printf("Digite o numero: ");
    scanf("%d", &nBusca);
    for(i=0;i<6;i++){
        if(nBusca == vetor[i]){
            posicao[contador] = i;
            contador++;
        }

    }
        printf("quantidade de vezes que o numero %d aparece: %d", nBusca, contador);
        for(i=0;i<contador;i++)
            printf("%d", posicao[i]);

            return 0;

}