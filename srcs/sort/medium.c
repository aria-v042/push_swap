/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 01:32:43 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/30 06:28:02 by nd-abreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_min_max(t_stack *stack, int *min, int *max)
{
	*min = stack->value;
	*max = stack->value;
	while (stack)
	{
		if (stack->value < *min)
			*min = stack->value;
		if (stack->value > *max)
			*max = stack->value;
		stack = stack->next;
	}
}

static int	chunk_count(int n)
{
	int	chunk_count;

	chunk_count = 1;
	while (chunk_count * chunk_count < n)
		chunk_count++;
	return (chunk_count);
}

static void	sort_chunk(t_data *data, int lower, int upper)
{
	int	count_in_b;
	int	pass_count;
	int	idx;

	count_in_b = 0;
	pass_count = stack_size(data->a);
	while (pass_count > 0)
	{
		if (data->a->value >= lower && data->a->value <= upper)
		{
			idx = find_insert_index_b(data->b, count_in_b, data->a->value);
			insert_into_b(data, idx);
			count_in_b++;
		}
		else
			ra(data);
		pass_count--;
	}
}

void	medium_sort(t_data *data)
{
	int	min;
	int	max;
	int	chunk_count;
	int	width;
	int	chunk;

	if (stack_size(data->a) <= 5)
		return (small_sort(data));
	assign_min_max(data->a, &min, &max);
	chunk_count = chunk_count(stack_size(data->a));
	width = (max - min + 1 + chunk_count - 1) / chunk_count;
	chunk = 0;
	while (chunk < chunk_count)
	{
		sort_chunk(data, min + chunk * width, min + chunk * width + width - 1);
		chunk++;
	}
	while (data->b)
		pa(data);
}
