#include <stdio.h>

int main() {
    int c, next;
    int in_string = 0, in_char = 0;

    while ((c = getchar()) != EOF) {

        if (!in_string && !in_char && c == '/') {
            next = getchar();

            if (next == '/') {
                while ((c = getchar()) != EOF && c != '\n');
                if (c == '\n')
                    putchar('\n');
            }
            else if (next == '*') {
                int prev = 0;
                while ((c = getchar()) != EOF) {
                    if (prev == '*' && c == '/')
                        break;
                    prev = c;
                }
            }
            else {
                putchar(c);
                if (next != EOF)
                    ungetc(next, stdin);
            }
        }
        else {
            putchar(c);

            if (c == '"' && !in_char)
                in_string = !in_string;
            else if (c == '\'' && !in_string)
                in_char = !in_char;
            else if ((in_string || in_char) && c == '\\') {
                c = getchar();
                if (c != EOF)
                    putchar(c);
            }
        }
    }

    return 0;
}