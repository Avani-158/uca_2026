#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
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
    selection_sort(arr, n);
    QueryPerformanceCounter(&end);

    double timeTaken = ((double)(end.QuadPart - start.QuadPart) * 1000.0) / frequency.QuadPart;

    printf("\nExecution Time: %.3f milliseconds\n", timeTaken);

    free(arr);
    return 0;
}
