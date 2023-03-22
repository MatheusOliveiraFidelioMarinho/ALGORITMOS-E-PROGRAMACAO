/*3. Faça um algoritmo que leia um numero inteiro, dois números reais (um float, com 3
casas depois da vírgua, e um double), um caracter (uma única letra), uma string
(conjunto de caracteres) e um endereço de memória, em hexadecimal. Na
sequência, imprima todos com a formatação abaixo.
Numero inteiro: “valor”
Numeros reais:
“valor”
“valor”
Letra: “valor”
String: “valor”
Endereço: “valor”
*/

#include<stdio.h>
int main(){
    int numeroInteiro;
    float numeroRealFloat;
    double numeroRealDouble;
    char umaLetra;
    char umaString[100];

    scanf("%d", &numeroInteiro);
    scanf("%f", &numeroRealFloat);
    scanf("%lf", &numeroRealDouble);
    scanf("%c", &umaLetra);
    scanf("%s", &umaString);
    //gets(umaString);
    fgets(umaString, 100, stdin);

    printf("%3d: inteiro\n", numeroInteiro);
    printf("float: %.3f\n", numeroRealFloat);
    printf("double: %lf\n", numeroRealDouble);
    printf("char: %c", umaLetra);
    printf("string: %s", umaString);


    return 0;
}