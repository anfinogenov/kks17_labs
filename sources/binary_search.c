#include <stdio.h>
#include <stdlib.h>
#include "../headers/binary_search.h"
#include "../headers/sort.h"

int binary_search(int* start, int* end, int value)
{
    if (end - start == 1)
    {
        if (*start == value)
            return 0;
        return -1;
    }

    int* half = start + (end - start) / 2;
    int ret = -1;

    if (value < *half)
        ret = binary_search(start, half, value);
    else
    {
        ret = binary_search(half, end, value);
        if (ret >= 0)
            ret += half - start;
    }

    while (start[ret-1] == value && ret > 0) ret--;

    return ret;
}

void binary_demo (void) {
    puts("> Binary search demonstration.");
    int size = 10;
    int max = 2*size + 1;
    int array[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand()%max;
    }

    merge_sort(array, 0, size);

    printf("Generated array: ");
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    puts("");

    for (int i = -5; i < max+5; i++) {
        int index = binary_search(array, array+size, i);
        if (index != -1) printf("Found %d at %d\n", i, index);
        else printf("Not found %d\n", i);
    }
}
