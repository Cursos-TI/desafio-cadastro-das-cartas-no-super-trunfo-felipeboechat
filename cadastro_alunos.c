#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ALUNOS 50
#define MAX_NOME 100
#define IDADE_MIN 16
#define IDADE_MAX 90

// Estrutura para armazenar os dados do aluno
struct Aluno {
    char nome[MAX_NOME];
    int idade;
    long long int matricula;
};

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para validar a idade
int validarIdade(int idade) {
    return (idade >= IDADE_MIN && idade <= IDADE_MAX);
}

// Função para validar a matrícula
int validarMatricula(long long int matricula) {
    return (matricula > 0);
}

// Função para cadastrar um novo aluno
void cadastrarAluno(struct Aluno alunos[], int *totalAlunos) {
    if (*totalAlunos >= MAX_ALUNOS) {
        printf("\nErro: Número máximo de alunos atingido!\n");
        return;
    }

    printf("\n=== Cadastro de Novo Aluno ===\n");
    
    // Validação do nome
    do {
        printf("Nome do aluno: ");
        if (fgets(alunos[*totalAlunos].nome, MAX_NOME, stdin) == NULL) {
            printf("Erro ao ler o nome. Tente novamente.\n");
            continue;
        }
        alunos[*totalAlunos].nome[strcspn(alunos[*totalAlunos].nome, "\n")] = 0;
        if (strlen(alunos[*totalAlunos].nome) == 0) {
            printf("Erro: Nome não pode estar vazio!\n");
            continue;
        }
        break;
    } while (1);
    
    // Validação da idade
    do {
        printf("Idade do aluno (%d-%d anos): ", IDADE_MIN, IDADE_MAX);
        if (scanf("%d", &alunos[*totalAlunos].idade) != 1) {
            printf("Erro: Idade inválida! Digite apenas números.\n");
            limparBuffer();
            continue;
        }
        if (!validarIdade(alunos[*totalAlunos].idade)) {
            printf("Erro: Idade deve estar entre %d e %d anos!\n", IDADE_MIN, IDADE_MAX);
            continue;
        }
        break;
    } while (1);
    
    // Validação da matrícula
    do {
        printf("Matrícula do aluno: ");
        if (scanf("%lld", &alunos[*totalAlunos].matricula) != 1) {
            printf("Erro: Matrícula inválida! Digite apenas números.\n");
            limparBuffer();
            continue;
        }
        if (!validarMatricula(alunos[*totalAlunos].matricula)) {
            printf("Erro: Matrícula inválida! Deve ser um número positivo.\n");
            continue;
        }
        break;
    } while (1);

    limparBuffer();
    (*totalAlunos)++;
    printf("\nAluno cadastrado com sucesso!\n");
}

// Função para listar todos os alunos cadastrados
void listarAlunos(struct Aluno alunos[], int totalAlunos) {
    if (totalAlunos == 0) {
        printf("\nNenhum aluno cadastrado!\n");
        return;
    }

    printf("\n=== Lista de Alunos Cadastrados ===\n");
    for (int i = 0; i < totalAlunos; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Matrícula: %lld\n", alunos[i].matricula);
    }
}

// Função para buscar um aluno pela matrícula
void buscarAluno(struct Aluno alunos[], int totalAlunos) {
    long long int matricula;
    int encontrado = 0;

    do {
        printf("\nDigite a matrícula do aluno: ");
        if (scanf("%lld", &matricula) != 1) {
            printf("Erro: Matrícula inválida! Digite apenas números.\n");
            limparBuffer();
            continue;
        }
        if (!validarMatricula(matricula)) {
            printf("Erro: Matrícula inválida! Deve ser um número positivo.\n");
            continue;
        }
        break;
    } while (1);

    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            printf("\n=== Dados do Aluno ===\n");
            printf("Nome: %s\n", alunos[i].nome);
            printf("Idade: %d\n", alunos[i].idade);
            printf("Matrícula: %lld\n", alunos[i].matricula);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nAluno não encontrado!\n");
    }
    limparBuffer();
}

// Função para exibir o menu principal
void exibirMenu() {
    printf("\n=== Sistema de Cadastro de Alunos ===\n");
    printf("1. Cadastrar novo aluno\n");
    printf("2. Listar todos os alunos\n");
    printf("3. Buscar aluno por matrícula\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    struct Aluno alunos[MAX_ALUNOS];
    int totalAlunos = 0;
    int opcao;
    char entrada[10];

    do {
        exibirMenu();
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            printf("\nErro ao ler a opção. Tente novamente.\n");
            continue;
        }

        // Verifica se a entrada está vazia
        if (entrada[0] == '\n') {
            printf("\nErro: Nenhuma opção selecionada! Digite um número de 1 a 4.\n");
            continue;
        }

        // Converte a entrada para número
        opcao = atoi(entrada);

        switch (opcao) {
            case 1:
                cadastrarAluno(alunos, &totalAlunos);
                break;
            case 2:
                listarAlunos(alunos, totalAlunos);
                break;
            case 3:
                buscarAluno(alunos, totalAlunos);
                break;
            case 4:
                printf("\nSaindo do sistema...\n");
                break;
            default:
                printf("\nOpção inválida! Digite um número de 1 a 4.\n");
        }
    } while (opcao != 4);

    return 0;
} 