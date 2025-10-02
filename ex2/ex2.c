#include <stdio.h>

#define TAM 10

// FUNÇÕES

// Preenche o array (por referência)
void preencherArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Exibe o array (passagem por valor, const para não alterar)
void exibirArray(const int arr[], int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", arr[i]);
        if (i < tamanho - 1) printf(", ");
    }
    printf("]\n");
}

// Retorna o maior valor (passagem por valor)
int maiorValor(const int arr[], int tamanho) {
    int maior = arr[0];
    for (int i = 1; i < tamanho; i++) {
        if (arr[i] > maior) {
            maior = arr[i];
        }
    }
    return maior;
}

// Retorna o menor valor (passagem por valor)
int menorValor(const int arr[], int tamanho) {
    int menor = arr[0];
    for (int i = 1; i < tamanho; i++) {
        if (arr[i] < menor) {
            menor = arr[i];
        }
    }
    return menor;
}

// Calcula a média (passagem por valor)
float mediaValores(const int arr[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += arr[i];
    }
    return (float)soma / tamanho;
}

// Ordena o array em ordem crescente (por referência)
void ordenarArray(int arr[], int tamanho) {
    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = i + 1; j < tamanho; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// FUNÇÃO PRINCIPAL 
int main() {
    int numeros[TAM];

    printf("Digite %d numeros:\n", TAM);
    preencherArray(numeros, TAM);

    printf("\nArray original: ");
    exibirArray(numeros, TAM);

    int maior = maiorValor(numeros, TAM);
    int menor = menorValor(numeros, TAM);
    float media = mediaValores(numeros, TAM);

    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);
    printf("Media: %.2f\n", media);

    ordenarArray(numeros, TAM);

    printf("Array ordenado: ");
    exibirArray(numeros, TAM);

    return 0;
}
