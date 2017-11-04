#ifndef SORT_H
#define SORT_H

void bubble_sort (int* array, int start, int end);
void bubble_demo (int size);
void merge_sort (int* array, int start, int end);
void merge_demo (int size);
void swap (int* v1, int* v2);

#define MAX_PRINT_SIZE 0x100
#define MAX_SORT_SIZE 102400

#endif
