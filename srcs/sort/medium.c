/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 01:32:43 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/30 14:01:08 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (size / 5);
	return (size / 11);
}

static int	get_index_in_chunk(t_stack *a, int chunk_min, int chunk_max)
{
	int index;
	int chunk_first;
	int chunk_last;

	index = 0;
	chunk_first = -1;
	chunk_last = -1;
	while (a)
	{
		if (a->rank >= chunk_min && a->rank <= chunk_max)
		{
			if (chunk_first < 0)
				chunk_first = index;
			chunk_last = index;
		}
		index++;
		a = a->next;
	}
	if (chunk_first == -1)
		return (-1);
	else if (index >= chunk_first + chunk_last)
		return (chunk_first);
	else
		return (chunk_last);
}

static void	push_chunk_into_b(t_data *data, int chunk_min, int chunk_max)
{
	int	index;

	index = get_index_in_chunk(data->a, chunk_min, chunk_max);
	while (index > 0)
	{
		rotate_to_top_a(data, index, stack_size(data->a));
		pb(data);
		index = get_index_in_chunk(data->a, chunk_min, chunk_max);
	}
}

void	medium_sort(t_data *data)
{
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	max_index;

	if (is_sorted(data->a))
		return ;
	if (stack_size(data->a) <= 5)
		return (small_sort(data));
	chunk_size = get_chunk_size(stack_size(data->a));
	chunk_min = 0;
	chunk_max = chunk_size - 1;
	while (data->a)
	{
		push_chunk_into_b(data, chunk_min, chunk_max);
		chunk_min += chunk_size;
		chunk_max += chunk_size;
	}
	while (data->b)
	{
		max_index = get_max_index(data->b, stack_size(data->b));
		rotate_to_top_b(data, max_index, stack_size(data->b));
		pa(data);
	}
}
