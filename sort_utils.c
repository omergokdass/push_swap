/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokdas <ogokdas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:16:24 by ogokdas           #+#    #+#             */
/*   Updated: 2025/09/09 17:24:45 by ogokdas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_count(int size)
{
	if (size <= 100)
		return (5);
	else if (size <= 500)
		return (13);
	return (size / 42);
}

int	get_chunk_pivot(int chunk_index, int size, int chunk_count)
{
	int	base_size;
	int	remainder;

	base_size = size / chunk_count;
	remainder = size % chunk_count;
	if (chunk_index < remainder)
		return ((base_size + 1) * (chunk_index + 1) - 1);
	return (base_size * (chunk_index + 1) + remainder - 1);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	find_cheapest_in_chunk(t_stack *a, int prev_pivot, int pivot)
{
	int		best_val;
	int		best_cost;
	int		cost;
	t_stack	*tmp;

	tmp = a;
	best_val = -1;
	best_cost = INT_MAX;
	while (tmp)
	{
		if (tmp->value > prev_pivot && tmp->value <= pivot)
		{
			cost = shortest_way(a, tmp->value);
			if (ft_abs(cost) < ft_abs(best_cost))
			{
				best_cost = cost;
				best_val = tmp->value;
			}
		}
		tmp = tmp->next;
	}
	return (best_val);
}

void	push_chunk_value(t_stack **a, int prev_pivot, int pivot)
{
	int	val;
	int	cost;

	val = find_cheapest_in_chunk(*a, prev_pivot, pivot);
	if (val == -1)
		return ;
	cost = shortest_way(*a, val);
	while (cost > 0 && (*a)->value != val)
	{
		ra(a);
		cost--;
	}
	while (cost < 0 && (*a)->value != val)
	{
		rra(a);
		cost++;
	}
}
