/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 22:05:05 by nd-abreu          #+#    #+#             */
/*   Updated: 2026/08/29 01:02:03 by nd-abreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **source, t_stack **dest)
{
	t_stack	*moved;

	if (!*source)
		return ;
	moved = *source;
	*source = (*source)->next;
	moved->next = *dest;
	*dest = moved;
}

void	pa(t_data *data)
{
	push(&data->b, &data->a);
	ft_printf("pa\n");
	data->ops_count[OP_PA]++;
}

void	pb(t_data *data)
{
	push(&data->a, &data->b);
	ft_printf("pb\n");
	data->ops_count[OP_PB]++;
}