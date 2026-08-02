#include <stdio.h>

int logicalShift(int x, int n) {
    int mask = ~(((1 << 31) >> n) << 1);
    return (x >> n) & mask;
}

int main() {
    int x, n;
    scanf("%x %d", &x, &n);
    printf("Logical Shift :-> %x\n", logicalShift(x, n));
    return 0;
}