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

static void	get_min_max(t_stack *stack, int *min, int *max)
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
	int	k;

	k = 1;
	while (k * k < n)
		k++;
	return (k);
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
	int	n;
	int	min;
	int	max;
	int	k;
	int	width;
	int	chunk;

	n = stack_size(data->a);
	if (n <= 3)
	{
		small_sort(data);
		return ;
	}
	get_min_max(data->a, &min, &max);
	k = chunk_count(n);
	width = (max - min + 1 + k - 1) / k;
	chunk = 0;
	while (chunk < k)
	{
		sort_chunk(data, min + chunk * width, min + chunk * width + width - 1);
		chunk++;
	}
	while (data->b)
		pa(data);
}