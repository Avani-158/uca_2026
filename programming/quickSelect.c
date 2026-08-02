#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}

void quickSelect(int arr[], int low, int high, int k) {
    if (low < high) {
        int p = partition(arr, low, high);

        if (p == k)
            return;
        else if (p > k)
            quickSelect(arr, low, p - 1, k);
        else
            quickSelect(arr, p + 1, high, k);
    }
}

int main() {
    int n, k;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &k);

    quickSelect(arr, 0, n - 1, k - 1);

    printf("Smallest %d elements:\n", k);

    for (int i = 0; i < k; i++)
        printf("%d ", arr[i]);


    return 0;
}