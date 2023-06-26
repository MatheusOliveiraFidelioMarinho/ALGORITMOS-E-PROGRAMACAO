#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

typedef struct {
    int id;
    char nome[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char sexo[MAX_NAME_LENGTH];
    char endereco[MAX_ADDRESS_LENGTH];
    double altura;
    int vacina;
} Usuario;

Usuario usuarios[MAX_USERS];
int totalUsuarios = 0;

void incluirUsuario() {
    if (totalUsuarios == MAX_USERS) {
        printf("O NUMERO TOTAL DE USUARIOS FOI ATINGIDO.\n");
        return;
    }
   
    Usuario novoUsuario;
   
    printf("Digite seu nome completo: ");
    fgets(novoUsuario.nome, MAX_NAME_LENGTH, stdin);
    printf("Digite o seu email: ");
    fgets(novoUsuario.email, MAX_EMAIL_LENGTH, stdin);
    printf("Digite o sexo (Feminino, Masculino, Outros): ");
    fgets(novoUsuario.sexo, MAX_NAME_LENGTH, stdin);
    printf("Digite o seu endereço: ");
    fgets(novoUsuario.endereco, MAX_ADDRESS_LENGTH, stdin);
    printf("Digite sua altura: ");
    scanf("%lf", &novoUsuario.altura);
    printf("Voce tomou vacina? (1 - Sim // 0 - Nao): ");
    scanf("%d", &novoUsuario.vacina);
    getchar();
   
    novoUsuario.id = rand();
   
    usuarios[totalUsuarios] = novoUsuario;
    totalUsuarios++;
   
    printf("Usario cadastrado com sucesso, selecione a opção 5 para saber o ID do mesmo!\n");
}

void editarUsuario() {
    int idUsuario;
    printf("Digite o ID do usuario que deseja editar: ");
    scanf("%d", &idUsuario);
    getchar();
   
    int i;
    for (i = 0; i < totalUsuarios; i++) {
        if (usuarios[i].id == idUsuario) {
           
            printf("Digite o novo nome completo: ");
            fgets(usuarios[i].nome, MAX_NAME_LENGTH, stdin);
            printf("Digite o novo email: ");
            fgets(usuarios[i].email, MAX_EMAIL_LENGTH, stdin);
            printf("Digite o novo sexo (Feminino, Masculino, Outros): ");
            fgets(usuarios[i].sexo, MAX_NAME_LENGTH, stdin);
            printf("Digite o novo endereço: ");
            fgets(usuarios[i].endereco, MAX_ADDRESS_LENGTH, stdin);
            printf("Digite a nova altura: ");
            scanf("%lf", &usuarios[i].altura);
            printf("Voce tomou vacina? (1 - Sim // 0 - Nao): ");
            scanf("%d", &usuarios[i].vacina);
            getchar();
           
            printf("Usuario editado com sucesso!\n");
            return;
        }
    }
   
    printf("Usuario nao existe.\n");
}

void excluirUsuario() {
    int idUsuario;
    printf("Digite o ID do usuário que deseja excluir: ");
    scanf("%d", &idUsuario);
    getchar();

    int i;
    for (i = 0; i < totalUsuarios; i++) {
        if (usuarios[i].id == idUsuario) {
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
    char emailUsuario[MAX_EMAIL_LENGTH];
    printf("Digite o email do usuario que deseja buscar: ");
    fgets(emailUsuario, MAX_EMAIL_LENGTH, stdin);
   
    int i;
    for (i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].email, emailUsuario) == 0) {
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s", usuarios[i].nome);
            printf("Email: %s", usuarios[i].email);
            printf("Sexo: %s", usuarios[i].sexo);
            printf("Endereço: %s", usuarios[i].endereco);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            printf("Vacina: %s\n", usuarios[i].vacina ? "Sim" : "Nao");
           
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
        printf("Endereco: %s", usuarios[i].endereco);
        printf("Altura: %.2lf\n", usuarios[i].altura);
        printf("Vacina: %s\n", usuarios[i].vacina ? "Sim" : "Nao");
        printf("------------------------\n");
    }
}

void fazerBackup() {
    // Falta colocar uma lógica para fazer backup dos usuários cadastrados aqui
    printf("Backup realizado com sucesso!\n");
}

void restaurarDados() {
    /// Falta colocar uma lógica para restaurar os dados a partir de um backup aqui
    printf("Dados restaurados com sucesso!\n");
}

int main() {
    char opcao;
   
    do {
        printf("Escolha uma opcao:\n");
        printf("1 - Incluir usuario\n");
        printf("2 - Editar usuario\n");
        printf("3 - Excluir usuario\n");
        printf("4 - Buscar usuario por email\n");
        printf("5 - Imprimir usuarios cadastrados\n");
        printf("6 - Fazer backup\n");
        printf("7 - Restaurar dados\n");
        printf("0 - Sair\n");
       
        printf("Opcao: ");
        scanf(" %c", &opcao);
        getchar();
       
        switch (opcao) {
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
                printf("Fechando o programa...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != '0');
   
    return 0;
}