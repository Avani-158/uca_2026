#include <stdio.h>
#include <string.h>

void url_encode(char *str, int true_length)
{
    int spaces = 0;

    for (int i = 0; i < true_length; i++)
    {
        if (str[i] == ' ')
            spaces++;
    }

    int end = true_length + (spaces * 2);

    str[end] = '\0';

    for (int i = true_length - 1, j = end - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        }
        else
        {
            str[j--] = str[i];
        }
    }
}

int main()
{
    char str[100] = "Hello World";
    url_encode(str, strlen(str));

    printf("%s", str);

}