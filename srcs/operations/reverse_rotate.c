/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 00:45:36 by nd-abreu          #+#    #+#             */
/*   Updated: 2026/08/29 00:45:41 by nd-abreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_one(t_stack **stack)
{
	t_stack	*second_last;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	second_last = *stack;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_data *data)
{
	reverse_rotate_one(&data->a);
	ft_printf("rra\n");
	data->ops_count[OP_RRA]++;
}

void	rrb(t_data *data)
{
	reverse_rotate_one(&data->b);
	ft_printf("rrb\n");
	data->ops_count[OP_RRB]++;
}

void	rrr(t_data *data)
{
	reverse_rotate_one(&data->a);
	reverse_rotate_one(&data->b);
	ft_printf("rrr\n");
	data->ops_count[OP_RRR]++;
}
