#include <stdio.h>

int getByte(int x, int n) {
    return (x >> (n << 3)) & 0xFF;
}

int main() {
    int x, n;
    scanf("%x %d", &x, &n);
    printf("Byte :-> %x\n", getByte(x, n));
    return 0;
}