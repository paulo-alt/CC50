#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Função para validar se todos os caracteres do argumento são dígitos
int only_digits(char *text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (!isdigit(text[i]))
        {
            return 0;
        }
    }
    return 1;
}

// Função principal
int main(int argc, char *argv[])
{
    // Verifica se o usuário forneceu exatamente um argumento (além do nome do programa)
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Converte o argumento (string) para inteiro
    int key = atoi(argv[1]);
    key = key % 26; // Normaliza para evitar giros desnecessários

    // Solicita o texto simples
    char plaintext[1000];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Criptografa o texto
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char c = plaintext[i];

        // Se for letra maiúscula
        if (isupper(c))
        {
            printf("%c", (c - 'A' + key) % 26 + 'A');
        }
        // Se for letra minúscula
        else if (islower(c))
        {
            printf("%c", (c - 'a' + key) % 26 + 'a');
        }
        // Se for outro caractere (espaço, pontuação...), imprime como está
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}
