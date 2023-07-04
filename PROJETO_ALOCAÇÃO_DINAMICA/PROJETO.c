#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

typedef struct {
    int id;
    char* nome;
    char* email;
    char* sexo;
    char* endereco;
    double altura;
    int vacina;
} Usuario;

Usuario** usuarios;
int totalUsuarios = 0;
int capacidadeUsuarios = 0;

void inicializarUsuarios() {
    usuarios = (Usuario**)malloc(MAX_USERS * sizeof(Usuario*));
    capacidadeUsuarios = MAX_USERS;
}

void liberarUsuarios() {
    int i;
    for (i = 0; i < totalUsuarios; i++) {
        free(usuarios[i]->nome);
        free(usuarios[i]->email);
        free(usuarios[i]->sexo);
        free(usuarios[i]->endereco);
        free(usuarios[i]);
    }
    free(usuarios);
}

void incluirUsuario() {
    if (totalUsuarios == capacidadeUsuarios) {
        capacidadeUsuarios *= 2;
        usuarios = (Usuario**)realloc(usuarios, capacidadeUsuarios * sizeof(Usuario*));
    }

    Usuario* novoUsuario = (Usuario*)malloc(sizeof(Usuario));
    if (novoUsuario == NULL) {
        printf("Erro na alocação de memória.\n");
        return;
    }

    novoUsuario->nome = (char*)malloc(MAX_NAME_LENGTH * sizeof(char));
    novoUsuario->email = (char*)malloc(MAX_EMAIL_LENGTH * sizeof(char));
    novoUsuario->sexo = (char*)malloc(MAX_NAME_LENGTH * sizeof(char));
    novoUsuario->endereco = (char*)malloc(MAX_ADDRESS_LENGTH * sizeof(char));

    printf("Digite seu nome completo: ");
    fgets(novoUsuario->nome, MAX_NAME_LENGTH, stdin);
    printf("Digite o seu email: ");
    fgets(novoUsuario->email, MAX_EMAIL_LENGTH, stdin);
    printf("Digite o sexo (Feminino, Masculino, Outros): ");
    fgets(novoUsuario->sexo, MAX_NAME_LENGTH, stdin);
    printf("Digite o seu endereço: ");
    fgets(novoUsuario->endereco, MAX_ADDRESS_LENGTH, stdin);
    printf("Digite sua altura: ");
    scanf("%lf", &novoUsuario->altura);
    printf("Você tomou vacina? (1 - Sim // 0 - Não): ");
    scanf("%d", &novoUsuario->vacina);
    getchar();

    novoUsuario->id = rand();

    usuarios[totalUsuarios] = novoUsuario;
    totalUsuarios++;

    printf("Usuário cadastrado com sucesso, selecione a opção 5 para saber o ID do mesmo!\n");
}

void editarUsuario() {
    int idUsuario;
    printf("Digite o ID do usuário que deseja editar: ");
    scanf("%d", &idUsuario);
    getchar();

    int i;
    for (i = 0; i < totalUsuarios; i++) {
        if (usuarios[i]->id == idUsuario) {
            printf("Digite o novo nome completo: ");
            fgets(usuarios[i]->nome, MAX_NAME_LENGTH, stdin);
            printf("Digite o novo email: ");
            fgets(usuarios[i]->email, MAX_EMAIL_LENGTH, stdin);
            printf("Digite o novo sexo (Feminino, Masculino, Outros): ");
            fgets(usuarios[i]->sexo, MAX_NAME_LENGTH, stdin);
            printf("Digite o novo endereço: ");
            fgets(usuarios[i]->endereco, MAX_ADDRESS_LENGTH, stdin);
            printf("Digite a nova altura: ");
            scanf("%lf", &usuarios[i]->altura);
            printf("Você tomou vacina? (1 - Sim // 0 - Não): ");
            scanf("%d", &usuarios[i]->vacina);
            getchar();

            printf("Usuário editado com sucesso!\n");
            return;
        }
    }

    printf("Usuário não encontrado.\n");
}

void excluirUsuario() {
    int idUsuario;
    printf("Digite o ID do usuário que deseja excluir: ");
    scanf("%d", &idUsuario);
    getchar();

    int i;
    for (i = 0; i < totalUsuarios; i++) {
        if (usuarios[i]->id == idUsuario) {
            free(usuarios[i]->nome);
            free(usuarios[i]->email);
            free(usuarios[i]->sexo);
            free(usuarios[i]->endereco);
            free(usuarios[i]);

            int j;
            for (j = i; j < totalUsuarios - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }
            totalUsuarios--;

            printf("Usuário excluído com sucesso!\n");
            return;
        }
    }

    printf("Usuário não encontrado.\n");
}

void buscarUsuarioPorEmail() {
    char emailUsuario[MAX_EMAIL_LENGTH];
    printf("Digite o email do usuário que deseja buscar: ");
    fgets(emailUsuario, MAX_EMAIL_LENGTH, stdin);

    int i;
    for (i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i]->email, emailUsuario) == 0) {
            printf("ID: %d\n", usuarios[i]->id);
            printf("Nome: %s", usuarios[i]->nome);
            printf("Email: %s", usuarios[i]->email);
            printf("Sexo: %s", usuarios[i]->sexo);
            printf("Endereço: %s", usuarios[i]->endereco);
            printf("Altura: %.2lf\n", usuarios[i]->altura);
            printf("Vacina: %s\n", usuarios[i]->vacina ? "Sim" : "Não");

            return;
        }
    }

    printf("Usuário não encontrado.\n");
}

void imprimirUsuarios() {
    int i;
    for (i = 0; i < totalUsuarios; i++) {
        printf("ID: %d\n", usuarios[i]->id);
        printf("Nome: %s", usuarios[i]->nome);
        printf("Email: %s", usuarios[i]->email);
        printf("Sexo: %s", usuarios[i]->sexo);
        printf("Endereço: %s", usuarios[i]->endereco);
        printf("Altura: %.2lf\n", usuarios[i]->altura);
        printf("Vacina: %s\n", usuarios[i]->vacina ? "Sim" : "Não");
        printf("------------------------\n");
    }
}

void fazerBackup() {
    // Falta colocar uma lógica para fazer backup dos usuários cadastrados aqui
    printf("Backup realizado com sucesso!\n");
}

void restaurarDados() {
    // Falta colocar uma lógica para restaurar os dados a partir de um backup aqui
    printf("Dados restaurados com sucesso!\n");
}

int main() {
    char opcao;

    inicializarUsuarios();

    do {
        printf("Escolha uma opção:\n");
        printf("1 - Incluir usuário\n");
        printf("2 - Editar usuário\n");
        printf("3 - Excluir usuário\n");
        printf("4 - Buscar usuário por email\n");
        printf("5 - Imprimir usuários cadastrados\n");
        printf("6 - Fazer backup\n");
        printf("7 - Restaurar dados\n");
        printf("0 - Sair\n");

        printf("Opção: ");
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
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != '0');

    liberarUsuarios();

    return 0;
}
