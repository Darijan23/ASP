#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
	int *arr;
	int top;
} stack;

stack* new_stack(int n) {
    stack *s = malloc(sizeof(stack));
    s->arr = malloc(n * sizeof(int));
    s->top = -1;
    return s;
}

void push(stack *s, int val) {
    s->arr[++(s->top)] = val;
}

void pop(stack *s) {
    if (s->top == -1) return;
    s->top--;
}

int main() {
    int n;
    stack *s;

    scanf("%d ", &n);

    s = new_stack(n);

    for (int i = 0; i < n; i++) {
        char c;
        scanf("%c ", &c);

        if (c >= '0' && c <= '9') {
            push(s, c - '0');
        } else {
            int sol = 0;
            int b = s->arr[s->top];
            pop(s);
            int a = s->arr[s->top];
            pop(s);

            switch(c) {
                case '+':
                    sol = a + b;
                    break;

                case '-':
                    sol = a - b;
                    break;

                case '*':
                    sol = a * b;
                    break;
            }

            push(s, sol);
        }        
    }

    printf("%d", s->arr[s->top]);
    free(s->arr);
    free(s);
}