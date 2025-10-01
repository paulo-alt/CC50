#include <stdio.h>

int main() {
    int altura;

    // Solicita ao usuário a altura
    printf("Altura: ");
    scanf("%d", &altura);

    // Imprime a escada dupla
    for (int i = 1; i <= altura; i++) {
        // Espaços antes da primeira escada
        for (int espaco = 0; espaco < altura - i; espaco++) {
            printf(" ");
        }

        // Primeira escada (à esquerda)
        for (int j = 0; j < i; j++) {
            printf("#");
        }

        // Espaço no meio
        printf("  ");

        // Segunda escada (à direita)
        for (int j = 0; j < i; j++) {
            printf("#");
        }

        // Pula para a próxima linha
        printf("\n");
    }

    return 0;
}