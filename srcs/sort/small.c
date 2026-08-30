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
	int	first;
	int	second;
	int	third;

	first = data->a->value;
	second = data->a->next->value;
	third = data->a->next->next->value;
	if (first > second && second < third && first < third)
		sa(p);
	else if (first > second && second > third)
	{
		sa(p);
		rra(p);
	}
	else if (first > second && second < third && first > third)
		ra(p);
	else if (first < second && second > third && first < third)
	{
		sa(p);
		ra(p);
	}
	else if (first < second && second > third && first > third)
		rra(p);
}

void	sort_four(t_data *data)
{
	// TODO
}

void	sort_five(t_data *data)
{
	// TODO
}

void	small_sort(t_data *data)
{
	int size;

	size = stack_size(data->a);
	if (size <= 1)
		return ;
	if (size == 2)
		sort_two(data);
	else if (size == 3)
		sort_three(data);
	else if (size == 4)
		sort_four(data);
	else if (size == 5)
		sort_five(data);
}
