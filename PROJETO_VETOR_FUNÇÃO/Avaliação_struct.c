#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 1
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

struct User {
    int id;
    char nome[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char sexo[MAX_NAME_LENGTH];
    char endereco[MAX_ADDRESS_LENGTH];
    double altura;
    int vacina;
};

struct User usuarios[MAX_USERS];
int totalUsuarios = 0;

void incluirUsuario() {
    if (totalUsuarios == MAX_USERS) {
        printf("Limite maximo de usuarios atingido.\n");
        return;
    }
    
    struct User novoUsuario;
    
    printf("Digite o nome completo: ");
    fgets(novoUsuario.nome, MAX_NAME_LENGTH, stdin);
    printf("Digite o email: ");
    fgets(novoUsuario.email, MAX_EMAIL_LENGTH, stdin);
    printf("Digite o sexo (Feminino/Masculino/Indiferente): ");
    fgets(novoUsuario.sexo, MAX_NAME_LENGTH, stdin);
    printf("Digite o endereço: ");
    fgets(novoUsuario.endereco, MAX_ADDRESS_LENGTH, stdin);
    printf("Digite a altura (entre 1 e 2 metros): ");
    scanf("%lf", &novoUsuario.altura);
    printf("Recebeu vacina? (1 - Sim / 0 - Não): ");
    scanf("%d", &novoUsuario.vacina);
    
    novoUsuario.id = rand();
    
    usuarios[totalUsuarios] = novoUsuario;
    totalUsuarios++;
    
    printf("Usuario cadastrado com sucesso!\n");
}

void editarUsuario() {
    int id;
    printf("Digite o ID do usuário que deseja editar: ");
    scanf("%d", &id);
    
    int i;
    for (i = 0; i < totalUsuarios; i++) {
        if (usuarios[i].id == id) {

            printf("Digite o novo nome completo: ");
            fgets(usuarios[i].nome, MAX_NAME_LENGTH, stdin);
            printf("Digite o novo email: ");
            fgets(usuarios[i].email, MAX_EMAIL_LENGTH, stdin);
            printf("Digite o novo sexo (Feminino/Masculino/Indiferente): ");
            fgets(usuarios[i].sexo, MAX_NAME_LENGTH, stdin);
            printf("Digite o novo endereço: ");
            fgets(usuarios[i].endereco, MAX_ADDRESS_LENGTH, stdin);
            printf("Digite a nova altura (entre 1 e 2 metros): ");
            scanf("%lf", &usuarios[i].altura);
            printf("Recebeu vacina? (1 - Sim / 0 - Não): ");
            scanf("%d", &usuarios[i].vacina);
            
            printf("Usuario editado com sucesso!\n");
            return;
        }
    }
    
    printf("Usuario nao encontrado.\n");
}

void excluirUsuario() {
    int id;
    printf("Digite o ID do usuário que deseja excluir: ");
    scanf("%d", &id);
    
    int i;
    for (i = 0; i < totalUsuarios; i++) {
        if (usuarios[i].id == id) {
            int j;
            for (j = i; j < totalUsuarios - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }
            totalUsuarios--;
            
            printf("Usuario excluido com sucesso!\n");
            return;
        }
    }
    
    printf("Usuario nao encontrado.\n");
}

void buscarUsuarioPorEmail() {
    char email[MAX_EMAIL_LENGTH];
    printf("Digite o email do usuario que deseja buscar: ");
    fgets(email, MAX_EMAIL_LENGTH, stdin);
    
    int i;
    for (i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].email, email) == 0) {

            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s", usuarios[i].nome);
            printf("Email: %s", usuarios[i].email);
            printf("Sexo: %s", usuarios[i].sexo);
            printf("Endereço: %s", usuarios[i].endereco);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            printf("Vacina: %s\n", usuarios[i].vacina ? "Sim" : "Não");
            
            return;
        }
    }
    
    printf("Usuario nao encontrado.\n");
}

void imprimirUsuarios() {
    int i;
    for (i = 0; i < totalUsuarios; i++) {
        printf("ID: %d\n", usuarios[i].id);
        printf("Nome: %s", usuarios[i].nome);
        printf("Email: %s", usuarios[i].email);
        printf("Sexo: %s", usuarios[i].sexo);
        printf("Endereço: %s", usuarios[i].endereco);
        printf("Altura: %.2lf\n", usuarios[i].altura);
        printf("Vacina: %s\n", usuarios[i].vacina ? "Sim" : "Não");
        printf("------------------------\n");
    }
}

void fazerBackup() {
    // Implemente a lógica para fazer backup dos usuários cadastrados aqui
    // Por exemplo, copiar o vetor usuarios para outro vetor de backup
    printf("Backup realizado com sucesso!\n");
}

void restaurarDados() {
    // Implemente a lógica para restaurar os dados a partir de um backup aqui
    printf("Dados restaurados com sucesso!\n");
}

int main() {
   char opcao;
    
    do {
        printf("Selecione uma opcao:\n");
        printf("1. Incluir usurio\n");
        printf("2. Editar usuario\n");
        printf("3. Excluir usuario\n");
        printf("4. Buscar usuario por email\n");
        printf("5. Imprimir usuarios cadastrados\n");
        printf("6. Fazer backup dos usuarios\n");
        printf("7. Restaurar dados\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);
        getchar();
        
        switch(opcao) {
            case '1':
                incluirUsuario();
                break;
            case '2':
                editarUsuario();
                break;
            case '3':
                excluirUsuario();
                break;
            case '4':
                buscarUsuarioPorEmail();
                break;
            case '5':
                imprimirUsuarios();
                break;
            case '6':
                fazerBackup();
                break;
            case '7':
                restaurarDados();
                break;
            case '0':
                printf("Encerrando o programa. Obrigado!\n");
                break;
            default:
                printf("Opção invalida. Tente novamente.\n");
        }
    } while(opcao != '0');
    
    return 0;
}