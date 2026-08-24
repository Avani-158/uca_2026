#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 30

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main() {
    char expression[MAX + 1];

    scanf("%30s", expression);

    for (int i = 0; i < strlen(expression); i++) {

        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']') {

            if (top == -1) {
                printf("false");
                return 0;
            }

            char open = pop();

            if (!isMatching(open, ch)) {
                printf("false");
                return 0;
            }
        }
    }

    if (top == -1)
        printf("true");
    else
        printf("false");

    return 0;
}