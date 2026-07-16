#include<stdio.h>

int main(){
    int n;

    printf("Enter number: ");
    scanf("%d", &n);

    int a=0;
    int b=1;
    int sum=0;

    while(a<=n){
        if(a%2==0){
            sum+=a;
        }
        
        int c=a+b;
        a=b;
        b=c;
    }
    printf("the sum is :%d" ,sum);
}