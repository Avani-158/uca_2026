#include <stdio.h>
#include <string.h>

void reverse_string(char *str)
{
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);

    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }

    reverse_string(str);

    printf("Reversed string: %s\n", str);

    return 0;
}