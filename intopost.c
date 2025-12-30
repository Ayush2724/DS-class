#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack {
    int size;
    int top;
    char *arr;
};
int is_empty(struct stack *p1) {
    if (p1->top == -1)
        return 1;
    else
        return 0;
}
int is_full(struct stack *p1) {
    if (p1->top == p1->size - 1)
        return 1;
    else
        return 0;
}
void push(struct stack *p1, char val) {
    if (is_full(p1)) {
        printf("Stack Overflow! No more elements can be added\n");
    } else {
        p1->top++;
        p1->arr[p1->top] = val;
    }
}
char pop(struct stack *p1) {
    if (is_empty(p1)) {
        printf("Stack Underflow! Cannot pop from stack\n");
        return 0;
    } else {
        char val = p1->arr[p1->top];
        p1->top--;
        return val;
    }
}
int precedence(char ch) {
    if (ch == '^') return 4;
    if (ch == '*' || ch == '/') return 3;
    if (ch == '+' || ch == '-') return 2;
    return 0;
}
int is_operator(char ch) {
    if (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
        return 1;
    else
        return 0;
}
char* infix_to_postfix (struct stack *sp, char infix[], char postfix[]) {
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        // Operand → directly to output
        if (!is_operator(infix[i]) && infix[i] != '(' && infix[i] != ')') {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        // If '(' → push it
        else if (infix[i] == '(') {
            push(sp, '(');
            i++;
        }
        // If ')' → pop until '('
        else if (infix[i] == ')') {
            while (is_empty(sp)==0 && sp->arr[sp->top] != '(') {
                postfix[j] = pop(sp);
                j++;
            }
            pop(sp); // remove '('
            i++;
        }
        // Operator
        else {
            while (is_empty(sp)== 0 && precedence(infix[i]) <= precedence(sp->arr[sp->top])) {
                postfix[j++] = pop(sp);
            }
            push(sp, infix[i]);
            i++;
        }
    }
    // Pop remaining operators
    while (!is_empty(sp)) {
        postfix[j++] = pop(sp);
    }
   postfix[j] = '\0';
    return postfix;
}
int main() {
    char infix[100], postfix[100];
        printf("Enter an infix expression (no spaces): ");
    scanf("%s", infix);
struct stack *sp = (struct stack*) malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = strlen(infix);
    sp->arr = (char*) malloc(sp->size * sizeof(char));
printf("Postfix: %s \n", infix_to_postfix(sp, infix, postfix));
    free(sp->arr);
free(sp);
return 0;
}
