#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Verifica se a chave é válida
int is_valid_key(char *key)
{
    // Verifica o comprimento
    if (strlen(key) != 26)
    {
        return 0;
    }

    int seen[26] = {0}; // Array para checar letras repetidas

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return 0;
        }

        // Converte a letra para maiúscula para evitar duplicatas como 'A' e 'a'
        int index = toupper(key[i]) - 'A';

        if (seen[index])
        {
            return 0; // Letra já apareceu antes
        }
        seen[index] = 1;
    }

    return 1;
}

// Função principal
int main(int argc, char *argv[])
{
    // Valida argumento
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    char *key = argv[1];

    if (!is_valid_key(key))
    {
        printf("Key must contain 26 unique alphabetical characters.\n");
        return 1;
    }

    // Solicita texto simples
    char plaintext[1000];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Criptografa
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char c = plaintext[i];

        if (isupper(c))
        {
            int index = c - 'A';
            printf("%c", toupper(key[index]));
        }
        else if (islower(c))
        {
            int index = c - 'a';
            printf("%c", tolower(key[index]));
        }
        else
        {
            printf("%c", c); // Não alfabético
        }
    }

    printf("\n");
    return 0;
}
