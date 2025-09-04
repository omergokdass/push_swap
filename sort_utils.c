#include "push_swap.h"

int get_chunk_count(int size)
{
    int chunk_count;

    if (size <= 100)
        chunk_count = 5;
    else if (size <= 500)
        chunk_count = size / 20;
    else
        chunk_count = size / 25;

    return chunk_count;
}

int get_chunk_pivot(int chunk_index, int size, int chunk_count)
{
    int base_size;
    int remainder;
    int pivot;

    base_size = size / chunk_count;
    remainder = size % chunk_count;

    if (chunk_index < remainder)
        pivot = (base_size + 1) * (chunk_index + 1) - 1;
    else
        pivot = base_size * (chunk_index + 1) + remainder - 1;

    return pivot;
}
int shortest_way(t_stack *stack, int target)
{
    t_stack *tmp;
    int pos;
    int size;

    tmp = stack;
    pos = 0;
    while (tmp)
    {
        if (tmp->value == target)
            break;
        pos++;
        tmp = tmp->next;
    }

    size = stack_size(stack);

    if (pos <= size / 2)
        return pos;
    else
        return -(size - pos);
}

static void	push_chunk_value(t_stack **a, t_stack **b, int prev_pivot, int pivot)
{
	t_stack	*tmp;
	int		steps;

	tmp = *a;
	while (tmp && (tmp->value <= prev_pivot || tmp->value > pivot))
		tmp = tmp->next;
	if (!tmp)
		return ;
	steps = shortest_way(*a, tmp->value);
	while (steps > 0 && steps--)
		ra(a);
	while (steps < 0 && steps++)
		rra(a);
	pb(a, b);
}

int get_max(t_stack *stack)
{
    int max = stack->value;
    while (stack)
    {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    return max;
}
