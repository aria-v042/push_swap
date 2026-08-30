/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 06:29:14 by nd-abreu          #+#    #+#             */
/*   Updated: 2026/08/30 06:29:24 by nd-abreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_insert_index_b(t_stack *stack, int count_in_b, int value)
{
	int	idx;

	idx = 0;
	while (idx < count_in_b && stack && stack->value > value)
	{
		idx++;
		stack = stack->next;
	}
	return (idx);
}

void	insert_into_b(t_data *data, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		rb(data);
		i++;
	}
	pb(data);
	i = 0;
	while (i < idx)
	{
		rrb(data);
		i++;
	}
}