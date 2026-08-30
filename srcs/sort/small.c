/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 03:31:42 by nd-abreu          #+#    #+#             */
/*   Updated: 2026/08/30 09:25:02 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_data *data)
{
	if (data->a->value > data->a->next->value)
		sa(data);
}

static void	sort_three(t_data *data)
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

static void	sort_four(t_data *data)
{
	int	min_index;

	min_index = get_min_index(data->a, 4);
	rotate_to_top_a(data, min_index, 4);
	pb(data);
	sort_three(data);
	pa(data);
}

static void	sort_five(t_data *data)
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
