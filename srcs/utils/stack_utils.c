/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 20:59:20 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/28 21:26:50 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_get_bottom(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

t_stack	*stack_new_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	stack_add_bottom(t_stack **stack_p, t_stack *new_node)
{
	t_stack	*bottom;

	if (!stack_p || !new_node)
		return ;
	if (!*stack_p)
		*stack_p = new_node;
	else
	{
		bottom = stack_get_bottom(*stack_p);
		bottom->next = new_node;
	}
}

void	stack_free(t_stack **stack_p)
{
	t_stack	*node;
	t_stack	*next_node;

	if (!stack_p)
		return ;
	node = *stack_p;
	while (node)
	{
		next_node = node->next;
		free(node);
		node = next_node;
	}
}
