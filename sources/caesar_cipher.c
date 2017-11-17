#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../headers/caesar_cipher.h"

char caesar_shift_letter (char c, int shift) {
    if (shift > 26 || shift < -26) shift = shift % 26;
    if (shift < 0) shift += 26;

    if (!isalpha(c)) return c;

    unsigned char temp = c + shift;

    if (islower(c) && temp > 'z') temp -= 'z'-'a'+1;
    else if (!islower(c) && temp > 'Z') temp -= 'z'-'a'+1;

    return temp;
}

// 15 points
void caesar_encrypt_file (FILE* fin, FILE* fout, int shift) {
    while (1) {
        char temp = fgetc(fin);
        if (temp == EOF) break;

        char errcatcher = fputc(caesar_shift_letter(temp, shift), fout);
        if (errcatcher == EOF) {
            perror("fputc(enc_letter)");
            return;
        }
    }
}

// 10 points
void caesar_encrypt_string (char* str, int shift) {
    for (int i = 0; str[i] != 0; i++) {
        str[i] = caesar_shift_letter(str[i], shift);
    }
}

void caesar_demo (int argc, char** argv) {
    FILE* fin;
    FILE* fout;
    if (argc != 4) {
        printf("Caesar demo: Invalid amount of arguments\n");
        return;
    }

    int key = atoi(argv[3]);

    fin = fopen(argv[1], "r");

    char* out_name = (char*)malloc(sizeof(char)*(strlen(argv[2])+8));
    snprintf(out_name, strlen(argv[2])+8, "cademo_%s", argv[2]); 

    fout = fopen(out_name, "w");
    free(out_name);

    caesar_encrypt_file(fin, fout, key);

    fclose(fin);
    fclose(fout);
}

