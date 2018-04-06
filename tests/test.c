#include <stdio.h>
#include <stdbool.h>

#include "../headers/caesar_cipher.h"
#include "../headers/vigenere_cipher.h"

FILE* fopen_s (const char* path, const char* r) 
{
    FILE* tmp = fopen(path, r);
    if (tmp == NULL) {
        char msg[100];
        snprintf(msg, 100, "Can't open file %s", path);
        perror(msg);
    }
    return tmp;
}

long file_size (const char* filename) 
{
    FILE* file = fopen(filename, "r");

    fseek(file, 0, SEEK_END);
    long result = ftell(file);

    fclose(file);
    return result;
}

int file_cmp (FILE* f1, FILE* f2)
{
    int byte_1 = 0, byte_2 = 0;
    fseek(f1, 0, SEEK_SET);
    fseek(f2, 0, SEEK_SET);
    do
    {
        if ((byte_1 = fgetc(f1)) != (byte_2 = fgetc(f2)))
            return 1;
    } while ((byte_1 != EOF) && (byte_2 != EOF));

    return 0;
}

int check_caesar (FILE* fin, FILE* ftmp, FILE** fcontrol)
{
    printf("Checking caesar shift 10... ");
    caesar_encrypt_file(fin, ftmp, 10);
    if (file_cmp(*fcontrol, ftmp)) {
        return 1;
    }
    printf("Passed!\n");

    fclose(*fcontrol);
    *fcontrol = fopen_s("./tests/encrypted_caesar_20_selftest.txt", "r");
    if (*fcontrol == NULL) return -1;

    fseek(fin, 0, SEEK_SET);
    fseek(ftmp, 0, SEEK_SET);

    printf("Checking caesar shift 20... ");
    caesar_encrypt_file(fin, ftmp, 20);

    if (file_cmp(*fcontrol, ftmp)) return 1;
    else printf("Passed!\n");
    return 0;
}

int check_vigenere (FILE* fin, FILE* ftmp, FILE* fcontrol)
{
    printf("Checking vigenere with key 'vigenere'... ");
    vigenere_encrypt_file(fin, ftmp, "vigenere");

    if (file_cmp(fcontrol, ftmp)) return 1;
    else printf("Passed!\n");
    return 0;
}

int self_test (void) 
{
    FILE* fin = fopen_s("./plain_text.txt", "r");
    FILE* ftmp = fopen_s(".selftest.txt.tmp", "w+x");
    FILE* fcontrol = fopen_s("./tests/encrypted_caesar_10_selftest.txt", "r");
    if (ftmp == NULL || fin == NULL || fcontrol == NULL) 
    {
        fclose(fin); fclose(ftmp); fclose(fcontrol);
        return -1;
    }

    int flag = check_caesar(fin, ftmp, &fcontrol); 
    
    fseek(fin, 0, SEEK_SET);
    fclose(ftmp);
    ftmp = fopen_s(".selftest.txt.tmp", "w+");
    fcontrol = fopen_s("./tests/encrypted_vigenere_selftest.txt", "r");
    if (ftmp == NULL || fcontrol == NULL) 
    {
        fclose(fin); fclose(ftmp); fclose(fcontrol);
        return -1;
    }

    flag |= check_vigenere(fin, ftmp, fcontrol);

    fclose(fin);
    fclose(ftmp);
    fclose(fcontrol);
    if (!flag) remove(".selftest.txt.tmp");

    return flag;
}
