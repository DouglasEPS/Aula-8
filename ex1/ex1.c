#include <stdio.h>

// FUNÇÕES 

// Exibe o menu
void exibirMenu() {
    printf("\n=== CALCULADORA ===\n");
    printf("1. Somar\n");
    printf("2. Subtrair\n");
    printf("3. Multiplicar\n");
    printf("4. Dividir\n");
    printf("0. Sair\n");
}

// Obtém a opção escolhida pelo usuário
int obterOpcao() {
    int op;
    printf("Opcao: ");
    scanf("%d", &op);
    return op;
}

// Lê dois números (passagem por referência)
void obterNumeros(float *a, float *b) {
    printf("Digite o primeiro número: ");
    scanf("%f", a);
    printf("Digite o segundo número: ");
    scanf("%f", b);
}

// Operações matemáticas (passagem por valor)
float somar(float x, float y) {
    return x + y;
}
float subtrair(float x, float y) {
    return x - y;
}
float multiplicar(float x, float y) {
    return x * y;
}
float dividir(float x, float y) {
    if (y == 0) {
        printf("Erro: divisão por zero!\n");
        return 0; // Valor simbólico
    }
    return x / y;
}

// Exibe o resultado
void exibirResultado(float resultado) {
    printf("Resultado: %.2f\n", resultado);
}

// FUNÇÃO PRINCIPAL 
int main() {
    int opcao;
    float n1, n2, resultado;

    do {
        exibirMenu();
        opcao = obterOpcao();

        switch (opcao) {
            case 1:
                obterNumeros(&n1, &n2);
                resultado = somar(n1, n2);
                exibirResultado(resultado);
                break;

            case 2:
                obterNumeros(&n1, &n2);
                resultado = subtrair(n1, n2);
                exibirResultado(resultado);
                break;

            case 3:
                obterNumeros(&n1, &n2);
                resultado = multiplicar(n1, n2);
                exibirResultado(resultado);
                break;

            case 4:
                obterNumeros(&n1, &n2);
                resultado = dividir(n1, n2);
                if (n2 != 0) exibirResultado(resultado);
                break;

            case 0:
                printf("Fim do programa\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
