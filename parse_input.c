/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokdas <ogokdas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:47:26 by ogokdas           #+#    #+#             */
/*   Updated: 2025/09/04 02:54:22 by ogokdas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *s)
{
	int	i;

	i = 0;
	if (!s[i])
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	has_duplicate_stack(t_stack *a)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->value == tmp2->value)
			{
				write(2, "Error\n", 6);
				free_stack(&a);
				exit(1);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

static void	error_and_free(char **split, t_stack **a)
{
	write(2, "Error\n", 6);
	free_split(split);
	free_stack(a);
	exit(1);
}

t_stack	*parse_input_to_stack(char **av)
{
	t_stack	*a;
	char	**split;
	int		i;
	int		j;

	a = NULL;
	i = 1;
	while (av[i])
	{
		split = ft_split(av[i], ' ');
		j = 0;
		while (split[j])
		{
			if (!is_number(split[j]))
				error_and_free(split, &a);
			stack_add_back(&a, stack_new(ft_atoi(split[j])));
			j++;
		}
		free_split(split);
		i++;
	}
	has_duplicate_stack(a);
	return (a);
}
