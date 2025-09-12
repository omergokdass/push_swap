/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokdas <ogokdas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:11:49 by ogokdas           #+#    #+#             */
/*   Updated: 2025/09/11 15:11:52 by ogokdas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	shortest_way(t_stack *stack, int target)
{
	t_stack	*tmp;
	int		pos;
	int		size;

	tmp = stack;
	pos = 0;
	while (tmp)
	{
		if (tmp->value == target)
			break ;
		pos++;
		tmp = tmp->next;
	}
	size = stack_size(stack);
	if (pos <= size / 2)
		return (pos);
	else
		return (-(size - pos));
}

int	get_max(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
