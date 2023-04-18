#include<stdio.h>
#include<string.h>//necessario para o calculo da string

// int main(){

// char str1[100], str2[100];
// //int ler;
// printf("Digite seu nome: ");
// fgets(str1, 100, stdin);

// printf("Digite seu sobrenome: ");
// fgets(str2, 100, stdin);

// //ler = strlen(str1)-1;
// printf("A sua palavra tem %d caracteres. \n", strlen(str1) + strlen(str2)-2);

// return 0;

// }

// int main (){
// char nome[20], sobrenome[20];
// printf("Digite seu nome: ");
// scanf("%s", nome);

// printf("Digite seu sobrenome: ");
// scanf("%s", sobrenome);

// printf("%d", strlen(nome) + strlen(sobrenome));

// return 0;

// }

int main(){
 char nome[20];
 char sobrenome[20];

printf("Digite seu nome: ");
scanf("%s", nome);

printf("Digite seu sobrenome: ");
scanf("%s", sobrenome);

if(strlen(nome) > strlen(sobrenome)) {
    printf("O nome e maior que o sobrenome");}
else if(strlen(nome) < strlen(sobrenome)); 
printf("O sobrenome e maior que o nome");
if(strlen(nome) == strlen(sobrenome))printf("O nome e o sobrenome tem o mesmo tamanho");

return 0;

}