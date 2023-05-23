#include <stdio.h>
#include <time.h>

#define LEN 20

double sort(int *list)
{
    clock_t start = clock();
    int tmp, n;

    // (LENGTH - 1) iterations
    for (int i = 1; i < LEN; i++)
    {
        // set target data to list[i]
        tmp = list[(n = i)];

        // until previous data is smaller than target data, push data
        while (--n >= 0 && list[n] > tmp)
            list[n + 1] = list[n];

        // if a data is smaller than target data, put target data next to it
        list[n + 1] = tmp;
    }

    clock_t end = clock();

    return (double)(end - start);
}

int main()
{
    int test_array[LEN] = {89, 53, 72, 77, 75, 24, 51, 57, 26, 85, 73, 10, 80, 86, 90, 27, 95, 31, 55, 78};
    double running_time;

    printf("Sorting Array:\n");
    for (int i = 0; i < LEN; i++)
        printf("%d ", test_array[i]);

    running_time = sort(test_array);

    printf("\n\nSorted Array:\n");
    for (int i = 0; i < LEN; i++)
        printf("%d ", test_array[i]);

    printf("\n\nIt took %.3f(s) to sort the array.\n");

    return 0;
}