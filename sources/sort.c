#include <stdio.h>
#include <stdlib.h>

#include "../headers/sort.h"

void bubble_sort (int* array, int start, int end) {
    for (int i = start; i < end; i++) {
        for (int j = start; j < end - (i-start+1); j++) {
            if (array[j] > array[j+1]) {
                swap(array+j, array+j+1);
            }
        }
    }
}

void swap (int* v1, int* v2) {
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

void print_array (int* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (!(i % 8)) printf("%04x |\t", i);
        printf("%d\t", arr[i]);
        if ((i+1) % 8 == 0) puts("");
    }
}

void bubble_demo (int size) {
    if (size < 0 || size > 0xf000) {
        puts("Incorrect size for bubble demo! Skipping...");
        return;
    }
    puts("Bubble sort demonstration.");
    int test_array[size];
    for (int i = 0; i < size; i++) {
        test_array[i] = -50 + rand()%101;
    }

    puts("Generated array: ");
    print_array(test_array, size);
    puts("Sorting...");
    bubble_sort (test_array, 0, size);
    puts("Sorted array: ");
    print_array(test_array, size);
}

