#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		*arr;
	int		i;
	int		size;

	if (ac < 2)
		return (0);
	arr = parse_input(ac, av);
	a = NULL;
	i = 0;
	while (i < ac - 1)
	{
		stack_add_back(&a, stack_new(arr[i]));
		i++;
	}
	free(arr);
	b = NULL;
	size = stack_size(a);
	if (size <= 5)
	{
		if (size == 2 && a->value > a->next->value)
			sa(&a);
		else if (size == 3)
			sort_3(&a);
		else
			sort_5(&a, &b);
	}
	else
	{
		normalize_stack(a, size);
		chunk_sort(&a, &b, size);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
