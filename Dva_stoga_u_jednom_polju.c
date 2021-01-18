#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define SIZE 10


struct stack_s {
    int array[SIZE];
    int tops[2];
} stack_init = { .tops={-1, SIZE} };
typedef struct stack_s stack_t;

int push(stack_t *stack, int stack_nr, int val) {
    if (stack_nr != 1 && stack_nr != 2) return -2;         //kao nevažeći unos
    if(stack->tops[0] + 1 == stack->tops[1]) return -1;    //stogovi su puni ako su im topovi jedan pokraj drugoga
    
    stack_nr--;
    stack->tops[stack_nr] += stack_nr ? -1 : 1;         //drugi stog ide u kontra smjeru?
    stack->array[stack->tops[stack_nr]] = val;

    return 0;
}

int pop(stack_t *stack, int stack_nr) {
    if (stack_nr != 1 && stack_nr != 2) return -2;         //kao nevažeći unos

    stack_nr--;
    if (stack->tops[stack_nr] == (stack_nr ? SIZE : -1)) return -1;  //ovo mi nije jasno

    stack->tops[stack_nr] += stack_nr ? 1 : -1;

    return 0;

}

int print(stack_t stack, int stack_nr) {
    printf("Stog: ");

    if (stack_nr == 1) {
        for (int i = 0; i <= stack.tops[0]; i++) {
            printf("%d ", stack.array[i]);
        }        
    } else if (stack_nr == 2) {
        for (int i = SIZE - 1; i >= stack.tops[1]; i--) {
            printf("%d ", stack.array[i]);
        }        
    }
    printf("\n");

    return 0;    
}

int main() {
    char menu_choice;
    stack_t stack = stack_init;
    int val, retval, stack_nr;

    DEBUG("\n(d) dodaj - push\n(b) brisi - pop\n(i) ispis - print\n(e) Exit\n");
    do {
        scanf(" %c", &menu_choice);
        switch (menu_choice) {
            case 'd':
                scanf("%d", &stack_nr);
                scanf("%d", &val);
                retval = push(&stack, stack_nr, val);
                if (retval==-1) {
                    printf("Stog je %d pun. Ne mogu dodati element.\n", stack_nr);
                } else if (retval==-2) {
                    printf("Stog je %d ne postoji.\n", stack_nr);
                }
                break;
            case 'b':
                scanf("%d", &stack_nr);
                retval = pop(&stack, stack_nr);
                if (retval==-1) {
                    printf("Stog je %d prazan. Ne mogu obrisati element.\n", stack_nr);
                } else if (retval==-2) {
                    printf("Stog je %d ne postoji.\n", stack_nr);
                }
                break;
            case 'i':
                scanf("%d", &stack_nr);
                print(stack, stack_nr);
                break;
        }
    } while (menu_choice!='e');
    return 0;
}
