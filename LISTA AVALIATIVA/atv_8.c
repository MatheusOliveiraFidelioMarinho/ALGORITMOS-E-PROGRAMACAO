/*Elabore um programa que faça a leitura de vários números inteiros até que se digite
um número negativo. O programa tem de retornar o maior e o menor número lido*/
int main(){

    int n1 = 0;
    int memoria = 0;

    printf("Insira numeros:");
    scanf("%d",&n1);
    memoria = n1;

    while(n1 > 0){
        if(n1>memoria){
            memoria = n1;
        }
    }

    printf("%d", memoria);

    return 0;
}