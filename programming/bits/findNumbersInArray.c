#include<stdio.h>

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int answer = 0;

    for(int bit=0; bit<32; bit++){
        int count=0;

        for(int i=0; i<n; i++){
            if((arr[i] & (1<<bit)) !=0){
                count++;
            }
        }

        if(count%3!=0){
            answer |=(1<<bit);
        }
    }

    printf("The number that appears only once is: %d\n", answer);

    
}