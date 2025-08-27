#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int             value;
	struct s_stack  *next;
}   t_stack;

t_stack *stack_new(int value);
void    stack_add_back(t_stack **stack, t_stack *new_node);
int     stack_size(t_stack *stack);
void    free_stack(t_stack **stack);

void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);

void    sort_3(t_stack **a);
void    sort_5(t_stack **a, t_stack **b);

int	*parse_input(int argc, char **argv);

/* normalize.c */
void	normalize_stack(t_stack *a, int size);

/* chunk_sort.c */
void	chunk_sort(t_stack **a, t_stack **b, int size);



void print_stack(t_stack *stack, char name);


#endif
