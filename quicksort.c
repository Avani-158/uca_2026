#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int partition(int arr[], int low, int high)
{
    int pivotIndex = low + (high - low) / 2;
    int pivot = arr[pivotIndex];

    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[high];
    arr[high] = temp;

    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)      
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}

void quick_sort_helper(int arr[], int low, int high)
{
    while (low < high)
    {
        int p = partition(arr, low, high);

        if (p - low < high - p)
        {
            quick_sort_helper(arr, low, p - 1);
            low = p + 1;
        }
        else
        {
            quick_sort_helper(arr, p + 1, high);
            high = p - 1;
        }
    }
}

void quick_sort(int arr[], int n)
{
    if (n > 1)
        quick_sort_helper(arr, 0, n - 1);
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

int main()
{
    int n, choice;

    srand((unsigned)time(NULL));

    printf("Enter array size: ");
    scanf("%d", &n);

    printf("\nChoose array type:\n");
    printf("1. Random\n");
    printf("2. Ascending\n");
    printf("3. Descending\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

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
    quick_sort(arr, n);
    QueryPerformanceCounter(&end);

    double timeTaken =
        ((double)(end.QuadPart - start.QuadPart) * 1000.0) /
        frequency.QuadPart;

    printf("\nExecution Time: %.3f milliseconds\n", timeTaken);

    free(arr);

    return 0;
}