/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 01:33:42 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/30 09:07:23 by nd-abreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

static int	count_zero_bit(t_stack *a, int bit)
{
	int	count;

	count = 0;
	while (a)
	{
		if (((a->rank >> bit) & 1) == 0)
			count++;
		a = a->next;
	}
	return (count);
}

static void	process_bit(t_data *data, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((data->a->rank >> bit) & 1)
			ra(data);
		else
			pb(data);
		i++;
	}
	while (data->b)
		pa(data);
}

void	complex_sort(t_data *data)
{
	int	size;
	int	max_bits;
	int	zeros;
	int	bit;

	size = stack_size(data->a);
	if (size <= 5)
		return (small_sort(data));
	assign_indexes(data->a);
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits && !is_sorted(data->a))
	{
		zeros = count_zero_bit(data->a, bit);
		if (zeros != 0 && zeros != size)
			process_bit(data, bit, size);
		bit++;
	}
}
