#include <stdio.h>
#include "../headers/binary_search.h"

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

    return ret;
}

void binary_demo()
{
#define N 10
    int array[N] = {1, 5, 6, 9, 9, 10, 14, 18, 20, 27};

    printf("Binary search demonstration func.\n");
    printf("Created array: ");
    for (int i = 0; i < N; i++) printf("%d ", array[i]);
    printf("\n");

    for (int i = 0; i < N; i++)
        printf(
                "found %d at %d\n",
                array[i],
                binary_search(array, array+N, array[i])
              );
#undef N
}

