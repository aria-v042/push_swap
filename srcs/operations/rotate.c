/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 00:35:17 by nd-abreu          #+#    #+#             */
/*   Updated: 2026/08/29 00:40:51 by nd-abreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_one(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_data *data)
{
	rotate_one(&data->a);
	ft_printf("ra\n");
	data->ops_count[OP_RA]++;
}

void	rb(t_data *data)
{
	rotate_one(&data->b);
	ft_printf("rb\n");
	data->ops_count[OP_RB]++;
}

void	rr(t_data *data)
{
	rotate_one(&data->a);
	rotate_one(&data->b);
	ft_printf("rr\n");
	data->ops_count[OP_RR]++;
}

