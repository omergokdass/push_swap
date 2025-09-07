/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokdas <ogokdas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:13:02 by ogokdas           #+#    #+#             */
/*   Updated: 2025/09/07 16:31:32 by ogokdas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks_to_b(t_stack **a, t_stack **b, int size)
{
	int	chunk_count;
	int	chunk_index;
	int	pivot;
	int	prev_pivot;
	int	pushed;
	int	total;

	chunk_count = get_chunk_count(size);
	chunk_index = 0;
	while (chunk_index < chunk_count)
	{
		pivot = get_chunk_pivot(chunk_index, size, chunk_count);
		prev_pivot = (chunk_index == 0) ? -1 :
			get_chunk_pivot(chunk_index - 1, size, chunk_count);
		pushed = 0;
		total = stack_size(*a);
		while (pushed <= pivot - prev_pivot && total-- > 0)
		{
			if (!*a)
				break ;
			push_chunk_value(a, b, prev_pivot, pivot);
			pushed++;
		}
		chunk_index++;
	}
}

void push_back_to_a(t_stack **a, t_stack **b)
{
    int steps;

    while (*b)
    {
        steps = shortest_way(*b, get_max(*b));

        if (steps > 0)
            while (steps-- > 0)
                rb(b);
        else
            while (steps++ < 0)
                rrb(b);

        pa(a, b);
    }
}

void big_sort(t_stack **a, t_stack **b)
{
    int size;

    size = stack_size(*a);
    if (size <= 5)
        small_sort(a,b);
    else
    {
        push_chunks_to_b(a, b, size);
        push_back_to_a(a, b);
    }
}