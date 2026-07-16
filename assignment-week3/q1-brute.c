#include <stdio.h>
#include <math.h>

int isPerfectSquare(int x)
{
    int s = sqrt(x);
    return s * s == x;
}

int isFibonacci(int n)
{
    return isPerfectSquare(5 * n * n + 4) ||
           isPerfectSquare(5 * n * n - 4);
}

int main()
{
    int n, sum = 0;

    printf("Enter number: ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
    {
        if (i % 2 == 0 && isFibonacci(i))
            sum += i;
    }

    printf("Sum = %d", sum);

}