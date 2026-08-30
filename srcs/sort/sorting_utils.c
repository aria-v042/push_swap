/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 09:02:26 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/30 13:58:04 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_stack *node, int n)
{
	int	index;
	int	min_index;
	int	min_value;

	index = 0;
	min_index = 0;
	min_value = node->value;
	while (index < n)
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

void	rotate_to_top_a(t_data *data, int index, int size)
{
	if (index <= size / 2)
	{
		while (index-- > 0)
			ra(data);
	}
	else
	{
		while (index++ < size)
			rra(data);
	}
}

void	assign_indexes(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	int		rank;

	i = a;
	while (i)
	{
		rank = 0;
		j = a;
		while (j)
		{
			rank += (j->value < i->value);
			j = j->next;
		}
		i->rank = rank;
		i = i->next;
	}
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
