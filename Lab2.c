/*WAP to convert a given valid parenthesized infix
arithmetic expression to postfix expression. The
expression consists of single character operands and the
binary operators + (plus), - (minus), * (multiply) and /
(divide)*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

int precedence(char c) {
    if (c == '+' || c == '-') 
        return 1;
    if (c == '*' || c == '/') 
        return 2;
    if (c == '^')
        return 3;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, k = 0;
    char c;
    
    while ((c = infix[i++]) != '\0') {
        
        if ('a'<=c && c <='z') {
            postfix[k++] = c;
        }
        else if (c == '(') {
            stack[++top] = c;
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--; 
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while (top != -1) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0';  
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter a valid infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
