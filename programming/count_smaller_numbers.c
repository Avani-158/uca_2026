#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Node;

void merge(Node arr[], Node temp[], int left, int mid, int right, int ans[]) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int smaller = 0;

    while (i <= mid && j <= right) {
        if (arr[j].value < arr[i].value) {
            temp[k++] = arr[j++];
            smaller++;
        } else {
            ans[arr[i].index] += smaller;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        ans[arr[i].index] += smaller;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(Node arr[], Node temp[], int left, int right, int ans[]) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, temp, left, mid, ans);
    mergeSort(arr, temp, mid + 1, right, ans);
    merge(arr, temp, left, mid, right, ans);
}

int main() {
    int n;
    scanf("%d", &n);

    Node arr[n], temp[n];
    int ans[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
        ans[i] = 0;
    }

    mergeSort(arr, temp, 0, n - 1, ans);

    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}