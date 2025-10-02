#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 100

// FUNCOES

// Le string do usuario
void lerString(char *str, int tamanho) {
    printf("Digite uma string: ");
    fgets(str, tamanho, stdin);
    // Remove \n 
    str[strcspn(str, "\n")] = '\0';
}

// Conta caracteres (por valor)
int contarCaracteres(const char *str) {
    return strlen(str);
}

// Inverte string (por referencia)
void inverterString(char *str) {
    int i, j;
    char temp;
    i = 0;
    j = strlen(str) - 1;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Converte para maiuscula (por referencia)
void paraMaiuscula(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

// Converte para minuscula (por referencia)
void paraMinuscula(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Conta palavras (por valor)
int contarPalavras(const char *str) {
    int count = 0;
    int dentroPalavra = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace((unsigned char)str[i]) && dentroPalavra == 0) {
            dentroPalavra = 1;
            count++;
        }
        else if (isspace((unsigned char)str[i])) {
            dentroPalavra = 0;
        }
    }
    return count;
}

// Exibe o menu
void exibirMenu() {
    printf("\n=== MANIPULADOR DE STRINGS ===\n");
    printf("1. Contar caracteres\n");
    printf("2. Inverter string\n");
    printf("3. Converter maiuscula\n");
    printf("4. Converter minuscula\n");
    printf("5. Contar palavras\n");
    printf("0. Sair\n");
}

// FUNCAO PRINCIPAL 
int main() {
    char texto[TAM];
    int opcao;

    lerString(texto, TAM);

    do {
        exibirMenu();
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                printf("A string possui %d caracteres.\n", contarCaracteres(texto));
                break;
            case 2:
                inverterString(texto);
                printf("String invertida: %s\n", texto);
                break;
            case 3:
                paraMaiuscula(texto);
                printf("String em maiuscula: %s\n", texto);
                break;
            case 4:
                paraMinuscula(texto);
                printf("String em minuscula: %s\n", texto);
                break;
            case 5:
                printf("A string possui %d palavras.\n", contarPalavras(texto));
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
