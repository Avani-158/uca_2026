#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

static void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
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
    heap_sort(arr, n);
    QueryPerformanceCounter(&end);

    double timeTaken = ((double)(end.QuadPart - start.QuadPart) * 1000.0) / frequency.QuadPart;

    printf("\nExecution Time: %.3f milliseconds\n", timeTaken);

    free(arr);
    return 0;
}
