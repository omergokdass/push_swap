/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokdas <ogokdas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:12:50 by ogokdas           #+#    #+#             */
/*   Updated: 2025/09/04 16:56:34 by ogokdas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *stack_to_array(t_stack *a)
{
    int *arr;
    int i;

    i = 0;
    arr = malloc(sizeof(int)*stack_size(a));
    if(!arr)
        exit(1);
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
    i = 0;
    while(i < size - 1)
    {
        j = 0;
        while(j < size - 1)
        {
            if(arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}

void normalize_stack(t_stack *a, int *arr, int size)
{
    int i;

    i = 0;
    while(a)
    {
        i = 0;
        while(i < size)
        {
            if(a->value == arr[i])
                break;
            i++;
        }
        a->value = i;
        a = a->next;
    }
}
