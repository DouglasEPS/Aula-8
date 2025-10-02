#include <stdio.h>

#define ALUNOS 5
#define DISCIPLINAS 4
#define MEDIA_APROVACAO 6.0

// FUNCOES 

// Inserir todas as notas (por referencia)
void inserir_notas(float notas[][DISCIPLINAS]) {
    for (int i = 0; i < ALUNOS; i++) {
        printf("\nAluno %d:\n", i + 1);
        for (int j = 0; j < DISCIPLINAS; j++) {
            printf("Digite a nota da disciplina %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }
}

// Exibir matriz de notas (por valor)
void exibir_notas(const float notas[][DISCIPLINAS]) {
    printf("\n=== Tabela de Notas ===\n");
    printf("Aluno\t");
    for (int j = 0; j < DISCIPLINAS; j++) {
        printf("D%d\t", j + 1);
    }
    printf("\n");

    for (int i = 0; i < ALUNOS; i++) {
        printf("%d\t", i + 1);
        for (int j = 0; j < DISCIPLINAS; j++) {
            printf("%.1f\t", notas[i][j]);
        }
        printf("\n");
    }
}

// Calcular media de um aluno especifico (por valor)
float calcular_media_aluno(const float notas[][DISCIPLINAS], int aluno) {
    float soma = 0;
    for (int j = 0; j < DISCIPLINAS; j++) {
        soma += notas[aluno][j];
    }
    return soma / DISCIPLINAS;
}

// Calcular media de uma disciplina especifica (por valor)
float calcular_media_disciplina(const float notas[][DISCIPLINAS], int disciplina) {
    float soma = 0;
    for (int i = 0; i < ALUNOS; i++) {
        soma += notas[i][disciplina];
    }
    return soma / ALUNOS;
}

//  situacao do aluno (Aprovado/Reprovado)
const char* situacao_aluno(const float notas[][DISCIPLINAS], int aluno) {
    float media = calcular_media_aluno(notas, aluno);
    return (media >= MEDIA_APROVACAO) ? "Aprovado" : "Reprovado";
}

// Exibir relatorio completo
void exibir_relatorio_final(const float notas[][DISCIPLINAS]) {
    printf("\n=== Relatorio Final ===\n");
    for (int i = 0; i < ALUNOS; i++) {
        float media = calcular_media_aluno(notas, i);
        printf("Aluno %d - Media: %.2f - %s\n", i + 1, media, situacao_aluno(notas, i));
    }

    printf("\nMedias por disciplina:\n");
    for (int j = 0; j < DISCIPLINAS; j++) {
        float media = calcular_media_disciplina(notas, j);
        printf("Disciplina %d - Media: %.2f\n", j + 1, media);
    }
}

// Exibir menu
void exibir_menu() {
    printf("\n=== SISTEMA DE GESTAO DE NOTAS ===\n");
    printf("1. Inserir notas\n");
    printf("2. Exibir notas\n");
    printf("3. Calcular medias por aluno\n");
    printf("4. Calcular medias por disciplina\n");
    printf("5. Exibir aprovados/reprovados\n");
    printf("0. Sair\n");
}

//  FUNCAO PRINCIPAL 
int main() {
    float notas[ALUNOS][DISCIPLINAS] = {0};
    int opcao;

    do {
        exibir_menu();
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir_notas(notas);
                break;
            case 2:
                exibir_notas(notas);
                break;
            case 3:
                for (int i = 0; i < ALUNOS; i++) {
                    printf("Aluno %d - Media: %.2f\n", i + 1, calcular_media_aluno(notas, i));
                }
                break;
            case 4:
                for (int j = 0; j < DISCIPLINAS; j++) {
                    printf("Disciplina %d - Media: %.2f\n", j + 1, calcular_media_disciplina(notas, j));
                }
                break;
            case 5:
                exibir_relatorio_final(notas);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
