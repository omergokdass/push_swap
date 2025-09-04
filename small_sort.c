#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static int	find_min_pos(t_stack *a)
{
	int		min;
	int		pos;
	int		i;
	t_stack	*tmp;

	min = a->value;
	pos = 0;
	i = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;

	while (stack_size(*a) > 3)
	{
		size = stack_size(*a);
		pos = find_min_pos(*a);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				ra(a);
		}
		else
		{
			while (pos++ < size)
				rra(a);
		}
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	small_sort(t_stack **a, t_stack **b)
{
	int size;
	
	size = stack_size(*a);
	if (size == 2 && (*a)->value > (*a)->next->value)
			sa(a);
	else if (size == 3)
		sort_three(a);
	else
		sort_five(a, b);
}
