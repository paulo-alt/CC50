/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

int main() {
    int tamanho;

    // Executa 8 vezes, ou quantas vezes você quiser testar
    for (int i = 0; i < 8; i++) {
        printf("Tamanho:");
        scanf("%d", &tamanho);

        // Gera escada com base no valor digitado
        for (int linha = 1; linha <= tamanho; linha++) {
            for (int j = 0; j < linha; j++) {
                printf("#");
            }
            printf("\n");
        }

        printf("\n"); // espaço entre blocos
    }

    return 0;
}
