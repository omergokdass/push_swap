#include "push_swap.h"

static int is_number(char *str)
{
	int i = 0;
	if (!str[i])
		return 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return 0;
		i++;
	}
	return 1;
}

static int has_duplicate_stack(t_stack *a)
{
	t_stack *tmp1 = a;
	while (tmp1)
	{
		t_stack *tmp2;

        tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->value == tmp2->value)
				return 1;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return 0;
}

t_stack *parse_input_to_stack(char **av)
{
	t_stack *a = NULL;
	int i = 1;

	while (av[i])
	{
		char **split = ft_split(av[i], ' ');
		int j = 0;
		while (split[j])
		{
			if (!is_number(split[j]))
			{
				write(2, "Error\n", 6);
				free_split(split);
				free_stack(&a);
				exit(1);
			}
			stack_add_back(&a, stack_new(ft_atoi(split[j])));
			j++;
		}
		free_split(split);
		i++;
	}

	if (has_duplicate_stack(a))
	{
		write(2, "Error\n", 6);
		free_stack(&a);
		exit(1);
	}
	return a;
}
