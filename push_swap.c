/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokdas < ogokdas@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:47:32 by ogokdas           #+#    #+#             */
/*   Updated: 2025/09/03 20:18:51 by ogokdas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (ac < 2)
		return (0);
	a = parse_input_to_stack(av);
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
		normalize_stack(&a);
		chunk_sort(&a);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
