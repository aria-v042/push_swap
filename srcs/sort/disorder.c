/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 02:28:44 by nd-abreu          #+#    #+#             */
/*   Updated: 2026/08/29 02:29:26 by nd-abreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_disorder(t_data *data)
{
	t_stack	*node_i;
	t_stack	*node_j;
	int		mistakes;
	int		total_pairs;

	mistakes = 0;
	total_pairs = 0;
	node_i = data->a;
	while (node_i)
	{
		node_j = node_i->next;
		while (node_j)
		{
			total_pairs++;
			if (node_i->value > node_j->value)
				mistakes++;
			node_j = node_j->next;
		}
		node_i = node_i->next;
	}
	if (total_pairs == 0)
		data->disorder = 0;
	else
		data->disorder = (float)mistakes / (float)total_pairs;
}