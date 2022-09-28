#include <stdio.h>
#include <stdlib.h>

int main() {
	system("color 5B");
	char nome[100];
	int idade;
	float altura;
	char endereco[100];
	char cpf[30];
	char nascimento[20];
	
	printf("QUAL SEU NOME? ");
	scanf("%[^\n]s", &nome);
	
	printf("QUAL SUA IDADE? ");
	scanf("%d", &idade);
	
	printf("QUAL SUA ALTURA? ");
	scanf("%f", &altura);
	
	printf("QUAL SEU ENDERECO? ");
	scanf(" %[^\n]s", &endereco);
	
	printf("QUAL SEU CPF? ");
	scanf(" %s", &cpf);
	
	printf("QUAL SUA DATA DE NASCIMENTO? ");
	scanf(" %s", &nascimento);
	
	printf("+__________________________________________________+\n");
	printf("|               TABELA DE DADOS                    |\n");
	printf("+__________________________________________________+\n");
	printf("|NOME: %s\n", nome);
	printf("|IDADE: %d\n", idade);
	printf("|ALTURA: %.2f\n", altura);
	printf("|ENDERECO: %s\n", endereco);
	printf("|CPF: %s\n", cpf);
	printf("|DATA DE NASCIMENTO: %s\n", nascimento);
	printf("+__________________________________________________+\n");

	return 0;
}