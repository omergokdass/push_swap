/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokdas <ogokdas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:47:32 by ogokdas           #+#    #+#             */
/*   Updated: 2025/09/09 16:37:33 by ogokdas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	preprocess_stack(t_stack **a, int size)
{
	int	*arr;

	arr = stack_to_array(*a);
	sort_array(arr, size);
	normalize_stack(*a, arr, size);
	free(arr);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (ac == 1)
		return (0);
	a = parse_input_to_stack(av);
	size = stack_size(a);
	if (size <= 1)
		return (free_stack(&a), 0);
	preprocess_stack(&a, size);
	if (is_sorted(a))
		return (free_stack(&a), 0);
	b = NULL;
	big_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
