#ifndef VIGENERE_CIPHER_H
#define VIGENERE_CIPHER_H

char vigenere_shift_letter (char c, char letter);
void vigenere_encrypt_file (FILE* fin, FILE* fout, char* key);
void vigenere_encrypt_string (char* str, char* key);
void vigenere_demo (int argc, char** argv);

#endif
