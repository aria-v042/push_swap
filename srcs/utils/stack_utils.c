/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 20:59:20 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/28 21:14:47 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

// CHECK:
int	stack_dup(t_data *data, int num)
{
	t_stack	*a;

	a = data->a;
	while (a)
	{
		if (a->value == num)
			return (1);
		a = a->next;
	}
	return (0);
}
