/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 01:16:21 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/30 14:01:48 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_insert_index(t_stack *stack, int value)
{
	int		index;
	t_stack	*current;
	t_stack	*next;

	index = 0;
	current = stack;
	while (current)
	{
		next = current->next;
		if (!next)
			next = stack;
		if (value > current->value && value < next->value)
			return (index + 1);
		if (current->value > next->value
			&& (value > current->value || value < next->value))
			return (index + 1);
		current = current->next;
		index++;
	}
	return (0);
}

static void	insert_into_a(t_data *data, int value)
{
	int	index;

	index = get_insert_index(data->a, value);
	rotate_to_top_a(data, index, stack_size(data->a));
	pa(data);
}

void	simple_sort(t_data *data)
{
	int	to_push;
	int	min_index;

	if (is_sorted(data->a))
		return ;
	if (stack_size(data->a) <= 5)
		return (small_sort(data));
	to_push = stack_size(data->a) - 5;
	while (to_push > 0)
	{
		pb(data);
		to_push--;
	}
	small_sort(data);
	while (data->b)
		insert_into_a(data, data->b->value);
	min_index = get_min_index(data->a, stack_size(data->a));
	rotate_to_top_a(data, min_index, stack_size(data->a));
}
