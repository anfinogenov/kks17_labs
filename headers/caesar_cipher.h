#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

char caesar_shift_letter (char c, int shift);
void caesar_encrypt_file (FILE* fin, FILE* fout, int shift);
void caesar_encrypt_string (char* str, int shift);
void caesar_demo (int argc, char** argv);

#endif
