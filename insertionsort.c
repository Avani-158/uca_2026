#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
    }
}

void generateRandom(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;
}

void generateAscending(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = i;
}

void generateDescending(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
}

int main(void)
{
    int n, choice;

    srand(time(NULL));

    printf("Enter array size: ");
    scanf("%d", &n);

    printf("\nChoose array type:\n");
    printf("1. Random\n");
    printf("2. Ascending\n");
    printf("3. Descending\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int *arr = (int *)malloc(n * sizeof(int));

    switch (choice)
    {
    case 1:
        generateRandom(arr, n);
        printf("\nRandom array generated.\n");
        break;
    case 2:
        generateAscending(arr, n);
        printf("\nAscending array generated.\n");
        break;
    case 3:
        generateDescending(arr, n);
        printf("\nDescending array generated.\n");
        break;
    default:
        printf("Invalid choice!\n");
        free(arr);
        return 0;
    }

    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
    insertion_sort(arr, n);
    QueryPerformanceCounter(&end);

    double timeTaken = ((double)(end.QuadPart - start.QuadPart) * 1000.0) / frequency.QuadPart;

    printf("\nExecution Time: %.3f milliseconds\n", timeTaken);

    free(arr);
    return 0;
}
