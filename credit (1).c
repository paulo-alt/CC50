#include <stdio.h>

int main(void)
{
    long long numero;
    printf("Número: ");
    scanf("%lld", &numero);

    int soma = 0;
    int contador = 0;
    long long numero_copia = numero;
    int primeiro_digito = 0;
    int primeiros_dois_digitos = 0;

    while (numero_copia > 0)
    {
        int digito = numero_copia % 10;

        if (contador % 2 == 0)
        {
            soma += digito;
        }
        else
        {
            int produto = digito * 2;
            soma += (produto / 10) + (produto % 10);
        }

        if (numero_copia < 100 && numero_copia > 9)
        {
            primeiros_dois_digitos = numero_copia;
        }

        if (numero_copia < 10)
        {
            primeiro_digito = numero_copia;
        }

        numero_copia /= 10;
        contador++;
    }

    if (soma % 10 == 0)
    {
        if (contador == 15 && (primeiros_dois_digitos == 34 || primeiros_dois_digitos == 37))
        {
            printf("AMEX\n");
        }
        else if (contador == 16 && (primeiros_dois_digitos >= 51 && primeiros_dois_digitos <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((contador == 13 || contador == 16) && primeiro_digito == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
