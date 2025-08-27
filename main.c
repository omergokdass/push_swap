#include "push_swap.h"
#include <stdio.h>

void print_stack(t_stack *stack, char name)
{
    t_stack *tmp = stack;

    printf("Stack %c: ", name);
    while (tmp)
    {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

