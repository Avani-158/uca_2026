#include <stdio.h>
#include <stdlib.h>

int mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

int reversePairs(int arr[], int n) {
    int *temp = (int *)malloc(n * sizeof(int));
    int count = mergeSort(arr, temp, 0, n - 1);
    free(temp);
    return count;
}

int mergeSort(int arr[], int temp[], int left, int right) {
    if (left >= right)
        return 0;

    int mid = (left + right) / 2;

    int count = 0;
    count += mergeSort(arr, temp, left, mid);
    count += mergeSort(arr, temp, mid + 1, right);

   
    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= right && (long long)arr[i] > 2LL * arr[j])
            j++;
        count += j - (mid + 1);
    }

    
    merge(arr, temp, left, mid, right);

    return count;
}

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", reversePairs(arr, n));

    return 0;
}