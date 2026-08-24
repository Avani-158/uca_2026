#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int main() {
    char expression[1000];
    char *token;

    fgets(expression, sizeof(expression), stdin);

    token = strtok(expression, " \n");

    while (token != NULL) {

        if (token[0] >= '0' && token[0] <= '9') {
            push(atoi(token));
        }

        else {
            int b = pop();
            int a = pop();
            int result;

            switch (token[0]) {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;
            }

            push(result);
        }

        token = strtok(NULL, " \n");
    }

    printf("%d\n", pop());

    return 0;
}