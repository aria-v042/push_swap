/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 23:32:55 by nd-abreu          #+#    #+#             */
/*   Updated: 2026/08/29 00:42:21 by nd-abreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	sa(t_data *data)
{
	swap(data->a);
	ft_printf("sa\n");
	data->ops_count[OP_SA]++;
}

void	sb(t_data *data)
{
	swap(data->b);
	ft_printf("sb\n");
	data->ops_count[OP_SB]++;
}

void	ss(t_data *data)
{
	swap(data->a);
	swap(data->b);
	ft_printf("ss\n");
	data->ops_count[OP_SS]++;
}
