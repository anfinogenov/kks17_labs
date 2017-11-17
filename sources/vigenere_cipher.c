#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../headers/vigenere_cipher.h"

char vigenere_shift_letter (char c, char letter)
{
    int shift = toupper(letter) - 'A';
    if (shift > 26 || shift < -26)
        shift = shift % 26;

    if (shift < 0)
        shift += 26;

    if (!isalpha(c)) return c;

    unsigned char temp = c + shift;

    if (islower(c) && temp > 'z')
        temp -= 'z'-'a'+1;
    else if (!islower(c) && temp > 'Z')
        temp -= 'z'-'a'+1;

    //printf("    %c %c %d %c\n", c, letter, shift, toupper(temp));
    return toupper(temp);
}

// 15 points TODO
void vigenere_encrypt_file (FILE* fin, FILE* fout, char* key)
{
    int key_i = 0;
    while (1)
    {
        char temp = fgetc(fin);
        if (temp == EOF)
            break;
        if (temp == ' ')
            continue;
        if (!isalpha(temp))
            key_i--;

        char errcatcher = fputc(vigenere_shift_letter(temp, key[key_i]), fout);
        if (errcatcher == EOF)
        {
            perror("fputc(enc_letter)");
            return;
        }

        while (key[key_i] == ' ') key_i++;
        if (key[++key_i] == 0)
            key_i = 0;
    }
}

// 10 points TODO
void vigenere_encrypt_string (char* str, char* key)
{
    int key_i = 0;
    for (int i = 0; str[i] != 0; i++)
    {
        if (str[i] == ' ')
            continue;
        if (!isalpha(str[i]))
            key_i--;
        str[i] = vigenere_shift_letter(str[i], key[key_i]);

        while (key[key_i] == ' ') key_i++;
        if (key[++key_i] == 0)
            key_i = 0;
    }
}

void vigenere_demo (int argc, char** argv)
{
    FILE* fin;
    FILE* fout;
    if (argc != 4)
    {
        printf("Vigenere demo: Invalid amount of arguments\n");
        return;
    }

    char* key = argv[3];

    fin = fopen(argv[1], "r");

    char* out_name = (char*)malloc(sizeof(char)*(strlen(argv[2])+10));
    snprintf(out_name, strlen(argv[2])+10, "videmo_%s", argv[2]);

    fout = fopen(out_name, "w");
    free(out_name);

    vigenere_encrypt_file(fin, fout, key);

    fclose(fin);
    fclose(fout);
}

