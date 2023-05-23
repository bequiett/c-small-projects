#include <stdio.h>

#define LEN 20

typedef struct {
    int comparison;
    int swap;
} Stat;

int swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;

    return 1;
}

Stat sort(int *list)
{
    Stat stat = {0, 0};
    int n, tmp;

    for (int i = 0; i < LEN - 1; i++)
    {
        int n = i;
        for (int j = i; j < LEN; j++)
        {            
            if (list[n] > list[j])
            {
                n = j;
                stat.comparison++;
            }
        }

        stat.swap += swap(&list[i], &list[n]);
    }

    return stat;
}

int main()
{
    int test_array[LEN] = {89, 53, 72, 77, 75, 24, 51, 57, 26, 85, 73, 10, 80, 86, 90, 27, 95, 31, 55, 78};

    printf("Sorting Array:\n");
    for (int i = 0; i < LEN; i++)
        printf("%d ", test_array[i]);

    Stat stat = sort(test_array);

    printf("\n\nSorted Array:\n");
    for (int i = 0; i < LEN; i++)
        printf("%d ", test_array[i]);

    printf("\n\nComparision\t%d times\nSwap\t\t%d times", stat.comparison, stat.swap);

    return 0;
}