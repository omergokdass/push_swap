#include "push_swap.h"

static void swap(t_stack **stack)
{
    t_stack *first;
    t_stack *second;
    if (!stack || !*stack || !(*stack)->next)
        return; 
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}                     

void sa(t_stack **a)
{
    swap(a);
}
void sb(t_stack **b)
{    
    swap(b);        
}
    
void ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
}

static void push(t_stack **from, t_stack **to)
{
    t_stack *tmp;

    if (!from || !*from)
        return;
    tmp = *from;
    *from = (*from)->next;
    tmp->next = *to;
    *to = tmp;
}

void pa(t_stack **a, t_stack **b)
{
    push(b, a);
}

void pb(t_stack **a, t_stack **b)
{
    push(a, b);
}

static void rotate(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if (!stack || !*stack || !(*stack)->next)
        return;
    first = *stack;
    *stack = first->next;
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;        
}

void ra(t_stack **a)
{
    rotate(a);
}

void rb(t_stack **b)
{
    rotate(b);
}

void rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
}

static void r_rotate(t_stack **stack)
{
    t_stack *prev;
    t_stack *last;

    if (!stack || !*stack || !(*stack)->next)
        return;
    prev = NULL;
    last = *stack;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack;
    *stack = last;
}

void rra(t_stack **a)
{
    r_rotate(a);
}

void rrb(t_stack **b)
{
    r_rotate(b);
}

void rrr(t_stack **a, t_stack **b)
{
    r_rotate(a);
    r_rotate(b);
}