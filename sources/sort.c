#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void merge (int* array, int* helper, int low, int middle, int high) {
    for (int i = low; i <= high; i++) {
        helper[i] = array[i];
    }
    
    int i = low;
    int j = middle+1;
    int k = low;

    while (i <= middle && j <= high) {
        if (helper[i] <= helper[j]) 
            array[k++] = helper[i++];      
        else array[k++] = helper[j++];   
    }

    while (i <= middle) {
        array[k++] = helper[i++];
    }
}

void merge_sort_recursive (int* array, int* helper, int low, int high) {
    if (low < high) {
        int middle = low + (high - low)/2;
        merge_sort_recursive(array, helper, low, middle);
        merge_sort_recursive(array, helper, middle+1, high);
        merge(array, helper, low, middle, high);
    }
}

void merge_sort(int* array, int start, int end) {
    int* additional = (int*)calloc(end-start, sizeof(int));
    merge_sort_recursive(array, additional, start, end-1);
    free(additional);
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
    if (size < 0 || size > MAX_SORT_SIZE) {
        puts("> Incorrect size for bubble demo! Skipping...");
        return;
    }

    puts("> Bubble sort demonstration.");

    int is_print = 0;
    if (size <= MAX_PRINT_SIZE) is_print = 1;
    else printf("Too large size, printing is disabled.\n");

    int test_array[size];
    for (int i = 0; i < size; i++) {
        test_array[i] = -50 + rand()%101;
    }

    if (is_print) {
        puts("Generated array: ");
        print_array(test_array, size);
    }

    puts("Sorting...");
    clock_t start = clock();
    bubble_sort (test_array, 0, size);
    clock_t end = clock();
    printf("Sorting time (in CLOCKS): %lu\n", end-start);
    
    if (is_print) {
        puts("Sorted array: ");
        print_array(test_array, size);
    }
    return;
}

void merge_demo (int size) {
    if (size < 0 || size > MAX_SORT_SIZE) {
        puts("> Incorrect size for merge demo! Skipping...");
        return;
    }
    puts("> Merge sort demonstration");

    int is_print = 0;
    if (size <= MAX_PRINT_SIZE) is_print = 1;
    else printf("Too large size, printing is disabled.\n");

    int test_array[size];
    for (int i = 0; i < size; i++) {
        test_array[i] = -size + rand()%(2*size+1);
    }

    if (is_print) {
        puts("Generated array: ");
        print_array(test_array, size);
    }
    
    puts("Sorting...");
    clock_t start = clock();
    merge_sort(test_array, 0, size);
    clock_t end = clock();
    printf("Sorting time (in CLOCKS): %lu\n", end-start);

    if (is_print) {
        puts("Sorted array: ");
        print_array(test_array, size);
    }
    return;
}
