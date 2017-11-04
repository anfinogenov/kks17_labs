#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../headers/binary_search.h"
#include "../headers/caesar_cipher.h"
#include "../headers/sort.h"
#include "../headers/single_list.h"
#include "../headers/vigenere_cipher.h"

int main (int argc, char *argv[]) {
    srand(time(NULL));
    bubble_demo(0x5000);
    merge_demo(0x5000);
    binary_demo();
    caesar_demo(argc, argv);
    stack_demo();
    return 0;
}
