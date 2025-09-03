/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokdas <ogokdas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:12:50 by ogokdas           #+#    #+#             */
/*   Updated: 2025/09/04 00:47:53 by ogokdas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int *stack_to_array(t_stack *a)
{
    // 2 5 6 1 4 3 8 9 7

    int *arr;
    int i;

    i = 0;
    arr = malloc(sizeof(int)*stack_size(a));
    while(a)
    {
        arr[i] = a->value;
        i++;
        a = a->next;
    }

    return(arr);
}
void    sort_array(int *arr, int size)
{
    int i;
    int j;
    int tmp;


}
























/* int main()
{
    t_stack *a = NULL;
    stack_add_back(&a,stack_new(12));
    stack_add_back(&a,stack_new(44));
    stack_add_back(&a,stack_new(21));

    int *arr = stack_to_array(a);

    int i = 0;
    while(arr[i])
    {
        printf("%d ",arr[i]);
        i++;
    }
}

