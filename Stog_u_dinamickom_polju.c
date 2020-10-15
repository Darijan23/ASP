#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define SIZE 3
#define GROW_BY 3


struct stack_s {
    int *array;
    int top;
    int size;
    int is_dynamic;
} stack_init = { .array=NULL, .top=-1, .size=0, .is_dynamic=0 };
typedef struct stack_s stack_t;

int push(stack_t *stack, int val) {
    int retval = 0;
    if(stack->top == stack->size - 1) {
        if (stack->is_dynamic) {
            stack->array = (int *)realloc(stack->array, sizeof(int) * (stack->size + GROW_BY));
            if (!(stack->array)) {
                return -1;
            }
            stack->size += GROW_BY;
            retval = 1;            
        } else return -1;
        
    }
    
    stack->top++;
    stack->array[stack->top] = val;

    return retval;
}

int pop(stack_t *stack) {
    if (stack->top <= -1) return -1;    

    stack->top--;

    return 0;
}

void print(stack_t stack) {
    printf("Stog: ");
    for (int i = 0; i <= stack.top; i++) {
        printf("%d ", stack.array[i]);
    }
    printf("\n");    
}

int main() {
    char menu_choice, is_dynamic_choice;
    stack_t stack = stack_init;
    int val, retval;

    do {
        printf("Zelite li polje u kojem se implementira stog uciniti dinamickim? (Y/N): ");
        scanf(" %c", &is_dynamic_choice);
    } while (is_dynamic_choice!='Y' && is_dynamic_choice!='N');
    stack.is_dynamic = is_dynamic_choice=='Y';

    // Ovdje alocirati memorijski prostor za polje i postaviti velicinu stoga
    stack.array = (int *)malloc(sizeof(int) * SIZE);
    stack.size = SIZE;

    DEBUG("\n(d) dodaj - push\n(b) brisi - pop\n(i) ispis - print\n(e) Exit\n");
    do {
        scanf(" %c", &menu_choice);
        switch (menu_choice) {
            case 'd':
                scanf("%d", &val);
                retval = push(&stack, val);
                if (retval==1) {
                    printf("Stog je pun. Alocirao sam dodatni prostor.\n");
                } else if (retval==-1) {
                    printf("Stog je pun. Ne mogu dodati element.\n");
                }
                break;
            case 'b':
                retval = pop(&stack);
                if (retval==-1) {
                    printf("Stog je prazan. Ne mogu obrisati element.\n");
                }
                break;
            case 'i':
                print(stack);
                break;
        }
    } while (menu_choice!='e');
    free(stack.array);
    return 0;
}