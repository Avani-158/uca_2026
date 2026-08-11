#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int a[], int n, int i)
{
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[max])
        max = left;

    if (right < n && a[right] > a[max])
        max = right;

    if (max != i)
    {
        int temp = a[i];
        a[i] = a[max];
        a[max] = temp;

        heapify(a, n, max);
    }
}

void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

void randomArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = rand() % 10000;
}

void ascendingArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = i;
}

void descendingArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = n - i;
}

int isSorted(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
            return 0;
    }

    return 1;
}

void testCase(int n)
{
    int *a = (int *)malloc(n * sizeof(int));
    clock_t start, end;
    double timeTaken;
    int repetitions = 100;

    randomArray(a, n);

    start = clock();

    for (int i = 0; i < repetitions; i++)
    {
        randomArray(a, n);
        heapSort(a, n);
    }

    end = clock();

    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    timeTaken = timeTaken / repetitions;

    printf("Random (%d): %.6f sec - %s\n",
           n, timeTaken, isSorted(a, n) ? "Sorted" : "Not Sorted");

    ascendingArray(a, n);

    start = clock();

    for (int i = 0; i < repetitions; i++)
    {
        ascendingArray(a, n);
        heapSort(a, n);
    }

    end = clock();

    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    timeTaken = timeTaken / repetitions;

    printf("Ascending (%d): %.6f sec - %s\n",
           n, timeTaken, isSorted(a, n) ? "Sorted" : "Not Sorted");

    descendingArray(a, n);

    start = clock();

    for (int i = 0; i < repetitions; i++)
    {
        descendingArray(a, n);
        heapSort(a, n);
    }

    end = clock();

    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    timeTaken = timeTaken / repetitions;

    printf("Descending (%d): %.6f sec - %s\n\n",
           n, timeTaken, isSorted(a, n) ? "Sorted" : "Not Sorted");

    free(a);
}

int main()
{
    int sizes[] = {8000, 12000, 16000, 20000, 24000, 28000, 32000, 36000};
    int n = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        testCase(sizes[i]);
    }

    return 0;
}