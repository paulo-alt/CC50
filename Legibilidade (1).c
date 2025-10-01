#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(char text[]);
int count_words(char text[]);
int count_sentences(char text[]);

int main(void)
{
    char text[1000];

    // Solicita o texto ao usuário
    printf("Texto: ");
    fgets(text, sizeof(text), stdin);

    // Conta letras, palavras e frases
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Cálculo do índice de Coleman-Liau
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    // Resultado
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

    return 0;
}

// Conta letras do texto (A-Z ou a-z)
int count_letters(char text[])
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Conta palavras (começa com 1 e soma espaços)
int count_words(char text[])
{
    int count = 1;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Conta sentenças (ponto, exclamação, interrogação)
int count_sentences(char text[])
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
