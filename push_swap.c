#include "push_swap.h"

#include <stdio.h>

void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

int main(int ac, char **av)
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    int i;

    i = 1;
    while(i < ac)
    {
        stack_add_back(&a,stack_new(ft_atoi(av[i])));
        i++;
    }
    print_stack(a);
}