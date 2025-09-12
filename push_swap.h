/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokdas <ogokdas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:47:45 by ogokdas           #+#    #+#             */
/*   Updated: 2025/09/11 15:40:09 by ogokdas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN (-2147483648)

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new_node);
int		stack_size(t_stack *stack);
void	free_stack(t_stack **stack);
void	free_split(char **split);
int		is_sorted(t_stack *stack);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void	small_sort(t_stack **a, t_stack **b);

t_stack	*parse_input_to_stack(char **av);

int		*stack_to_array(t_stack *a);
void	sort_array(int *arr, int size);
void	normalize_stack(t_stack *a, int *arr, int size);

int		shortest_way(t_stack *stack, int target);
int		get_max(t_stack *stack);

int		get_chunk_count(int size);
int		get_chunk_pivot(int chunk_index, int size, int chunk_count);
void	push_chunk_value(t_stack **a, t_stack **b, int prev_pivot, int pivot);

void	push_chunks_to_b(t_stack **a, t_stack **b, int size);
void	push_back_to_a(t_stack **a, t_stack **b);
void	chunk_sort(t_stack **a, t_stack **b);

#endif
