/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokdas <ogokdas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:13:02 by ogokdas           #+#    #+#             */
/*   Updated: 2025/09/11 15:39:00 by ogokdas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_prev_pivot(int chunk_index, int size, int chunk_count)
{
	if (chunk_index == 0)
		return (-1);
	return (get_chunk_pivot(chunk_index - 1, size, chunk_count));
}

static void	process_chunk(t_stack **a, t_stack **b,
		int prev_pivot, int pivot)
{
	int	pushed;
	int	total;

	pushed = 0;
	total = stack_size(*a);
	while (pushed <= pivot - prev_pivot && total-- > 0)
	{
		if (!*a)
			break ;
		push_chunk_value(a, b, prev_pivot, pivot);
		pushed++;
	}
}

void	push_chunks_to_b(t_stack **a, t_stack **b, int size)
{
	int	chunk_count;
	int	chunk_index;
	int	pivot;
	int	prev_pivot;

	chunk_count = get_chunk_count(size);
	chunk_index = 0;
	while (chunk_index < chunk_count)
	{
		pivot = get_chunk_pivot(chunk_index, size, chunk_count);
		prev_pivot = get_prev_pivot(chunk_index, size, chunk_count);
		process_chunk(a, b, prev_pivot, pivot);
		chunk_index++;
	}
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	steps;

	while (*b)
	{
		steps = shortest_way(*b, get_max(*b));
		if (steps > 0)
		{
			while (steps-- > 0)
				rb(b);
		}
		else
		{
			while (steps++ < 0)
				rrb(b);
		}
		pa(a, b);
	}
}

void	chunk_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 5)
		small_sort(a, b);
	else
	{
		push_chunks_to_b(a, b, size);
		push_back_to_a(a, b);
	}
}
