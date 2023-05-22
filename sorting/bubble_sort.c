#include <stdio.h>
#include <time.h>

#define LEN 20

double sort(int *list)
{
    clock_t start = clock();
    int tmp;

    /*
        Running total "length - 1" iterations.
    */
    for (int i = LEN - 1; i > 0; i--)
    {
        /*
            If "j-1"th value is smaller than previous value, swaps two value.
            Running "i" iterations.
            ex) 1st operation: comparing "length - 1" times.
        */
        for (int j = 0; j < i; j++)
        {
            if (list[j+1] >= list[j]) continue;

            tmp = list[j+1];
            list[j+1] = list[j];
            list[j] = tmp;
        }
    }

    clock_t end = clock();
    
    return (double)(end - start);
}

int main()
{
    int test_array[LEN] = { 89, 53, 72, 77, 75, 24, 51, 57, 26, 85, 73, 10, 80, 86, 90, 27, 95, 31, 55, 78 };
    double running_time;

    printf("Sorting Array:\n");
    for (int i = 0; i < LEN; i++) printf("%d ", test_array[i]);
    
    running_time = sort(test_array);

    printf("\n\nSorted Array:\n");
    for (int i = 0; i < LEN; i++) printf("%d ", test_array[i]);

    printf("\n\nIt took %.3f(s) to sort the array.\n");

    return 0;
}