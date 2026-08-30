/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 03:31:42 by nd-abreu          #+#    #+#             */
/*   Updated: 2026/08/30 01:52:34 by nd-abreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_data *data)
{
	if (data->a->value > data->a->next->value)
		sa(data);
}

void	sort_three(t_data *data)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = data->a->value;
	a2 = data->a->next->value;
	a3 = data->a->next->next->value;
	if (a1 < a2 && a1 < a3)
	{
		if (a3 < a2)
		{
			sa(data);
			ra(data);
		}
	}
	else if (a2 < a1 && a2 < a3)
	{
		if (a1 < a3)
			sa(data);
		else
			ra(data);
	}
	else
	{
		if (a1 < a2)
			rra(data);
		else
		{
			sa(data);
			rra(data);
		}
	}
}

void	small_sort(t_data *data)
{
	// pick one of the sort functions for small stacks
}
