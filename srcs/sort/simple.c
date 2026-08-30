/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 01:16:21 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/30 02:29:06 by nd-abreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_insert_index(t_stack *stack, int value)
{
	int		index;
	t_stack	*current;

	index = 0;
	current = stack;
	while (current && current->value < value)
	{
		index++;
		current = current->next;
	}
	return (index);
}

static void	insert_into_a(t_data *data, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		ra(data);
		i++;
	}
	pa(data);
	i = 0;
	while (i < index)
	{
		rra(data);
		i++;
	}
}

void	simple_sort(t_data *data)
{
	int	to_push;
	int	index;

	if (stack_size(data->a) <= 3)
	{
		small_sort(data);
		return ;
	}
	to_push = stack_size(data->a) - 3;
	while (to_push > 0)
	{
		pb(data);
		to_push--;
	}
	sort_three(data);
	while (data->b)
	{
		index = get_insert_index(data->a, data->b->value);
		insert_into_a(data, index);
	}
}
