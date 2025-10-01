#include <stdio.h>

int main(void)
{
    int start, end;

    // Solicita o tamanho inicial
    do
    {
        printf("Start size: ");
        scanf("%d", &start);
    } while (start < 9);

    // Solicita o tamanho final
    do
    {
        printf("End size: ");
        scanf("%d", &end);
    } while (end < start);

    // Calcula o número de anos até atingir a população final
    int years = 0;
    int population = start;

    while (population < end)
    {
        int born = population / 3;
        int died = population / 4;
        population = population + born - died;
        years++;
    }

    // Imprime o número de anos
    printf("Years: %d\n", years);
    return 0;
}
