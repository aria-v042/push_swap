/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 23:32:55 by nd-abreu          #+#    #+#             */
/*   Updated: 2026/08/28 23:50:51 by nd-abreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void swap()
{
	
}

void	sa(t_data *data)
{
	swap(data->b, data->a);
	ft_printf("sa\n");
	data->ops_count[sa]++;
}


//sb
void	sb(t_data *data)
{
	swap(data->a, data->b);
	ft_printf("sb\n");
	data->ops_count[sb]++;
}


//ss
void	ss(t_data *data)
{
	swap(data->a, data->b);
	ft_printf("sb\n");
	data->ops_count[sb]++;
}