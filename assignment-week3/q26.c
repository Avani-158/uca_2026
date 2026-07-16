#include <stdio.h>

int my_strlen(const char *str)
{
    int length = 0;

    while (str[length] != '\0' && str[length] != '\n')
    {
        length++;
    }

    return length;
}

int main()
{
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Length = %d\n", my_strlen(str));

}