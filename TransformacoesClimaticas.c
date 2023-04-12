#include<stdio.h>

int main(){
float cel, fah;
printf("Escreva uma temperatura em celsius: ");
scanf("%f", &cel);
printf("Escreva uma temperatura em Fahrenheit: ");
scanf("%f", &fah);

fah = (9 * cel/5) + 32;
cel = (fah - 32) * 5/9;

printf("%.2f graus Celsius equivalem a %.2f gruas Fahrenheit\n", cel, fah);
printf("%.2f graus Fahrenheit equivalem a %.2f gruas Celsius\n", fah, cel);

return 0;
}