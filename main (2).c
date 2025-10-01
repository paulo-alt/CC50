#include <stdio.h>
//Activity code 1 of the Harvard C Programming course
int main() {
    int tamanho;

    // Execute 8 times, or as many times as you want to test.
    for (int i = 0; i < 8; i++) {
        printf("Tamanho:");
        scanf("%d", &tamanho);

        // Generates a ladder based on the entered value
        for (int linha = 1; linha <= tamanho; linha++) {
            for (int j = 0; j < linha; j++) {
                printf("#");
            }
            printf("\n");
        }

        printf("\n"); // space between blocks
    }

    return 0;
}
