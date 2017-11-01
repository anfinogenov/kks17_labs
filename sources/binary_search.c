int binary_search(int* start, int* end, int value)
{
    if (end - start == 1)
    {
        if (*start == value)
            return 0;
        return -1;
    }

    int* half = start + (end - start) / 2;

    if (value < *half)
        return binary_search(start, half, value);

    return binary_search(half, end, value) + (half - start);
}

