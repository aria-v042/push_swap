/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 09:02:26 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/30 14:27:46 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_stack *node, int size)
{
	int	index;
	int	min_index;
	int	min_value;

	index = 0;
	min_index = 0;
	min_value = node->value;
	while (index < size)
	{
		if (node->value < min_value)
		{
			min_value = node->value;
			min_index = index;
		}
		node = node->next;
		index++;
	}
	return (min_index);
}

int	get_max_index(t_stack *node, int size)
{
	int	index;
	int	max_index;
	int	max_value;

	index = 0;
	max_index = 0;
	max_value = node->rank;
	while (index < size)
	{
		if (node->rank > max_value)
		{
			max_value = node->rank;
			max_index = index;
		}
		node = node->next;
		index++;
	}
	return (max_index);
}

void	rotate_to_top_a(t_data *data, int index, int size)
{
	if (index <= size / 2)
	{
		while (index > 0)
		{
			ra(data);
			index--;
		}
	}
	else
	{
		while (index < size)
		{
			rra(data);
			index++;
		}
	}
}

void	rotate_to_top_b(t_data *data, int index, int size)
{
	if (index <= size / 2)
	{
		while (index > 0)
		{
			rb(data);
			index--;
		}
	}
	else
	{
		while (index < size)
		{
			rrb(data);
			index++;
		}
	}
}
