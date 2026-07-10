#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

static void merge_sort_helper(int arr[], int left, int right, int temp[])
{
    if (left >= right)
    {
        return;
    }

    int middle = left + (right - left) / 2;
    merge_sort_helper(arr, left, middle, temp);
    merge_sort_helper(arr, middle + 1, right, temp);

    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= middle)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}

void merge_sort(int arr[], int n)
{
    if (n <= 1)
    {
        return;
    }

    int *temp = (int *)malloc(sizeof(int) * n);

    if (temp == NULL)
    {
        printf("Memory error\n");
        return;
    }

    merge_sort_helper(arr, 0, n - 1, temp);
    free(temp);
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
    merge_sort(arr, n);
    QueryPerformanceCounter(&end);

    double timeTaken = ((double)(end.QuadPart - start.QuadPart) * 1000.0) / frequency.QuadPart;

    printf("\nExecution Time: %.3f milliseconds\n", timeTaken);

    free(arr);
    return 0;
}
