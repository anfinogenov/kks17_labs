#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../headers/binary_search.h"
#include "../headers/caesar_cipher.h"
#include "../headers/sort.h"
#include "../headers/single_list.h"
#include "../headers/vigenere_cipher.h"
#include "../headers/test.h"

int main (int argc, char **argv) 
{
    srand(time(NULL));

    if (self_test())
    {
        printf("Self-test failed!\n");
        exit(1);
    }
    else
    {
        printf("Self-test passed!\n");
    }

    // Sorting algorithms
    bubble_demo(0x50); // 0x5000
    merge_demo(0x50); // 0x5000

    // Search algorithm
    binary_demo();

    // Encryption algorithms
    if (argc == 5) argc = 4;
    caesar_demo(argc, argv);
    argv[3] = argv[4];
    vigenere_demo(argc, argv);

    // Containers
    stack_array_demo();
    stack_ptr_demo();
    return 0;
}
