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

int	stack_dup(t_stack *s, int num)
{
	while (s)
	{
		if (s->value == num)
			return (1);
		s = s->next;
	}
	return (0);
}
