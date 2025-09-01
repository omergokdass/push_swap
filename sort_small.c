#include "push_swap.h"

void	sort_3(t_stack **a)
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

void	sort_5(t_stack **a, t_stack **b)
{
	int	pos;

	while (stack_size(*a) > 3)
	{
		pos = find_min_pos(*a);
		if (pos <= stack_size(*a) / 2)
			while (pos-- > 0)
				ra(a);
		else
			while (pos++ < stack_size(*a))
				rra(a);
		pb(a, b);
	}
	sort_3(a);
	while (*b)
		pa(a, b);
}
