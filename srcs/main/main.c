/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 12:41:11 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/26 22:02:16 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_data(t_data *data, t_stack *a, t_stack *b)
{
	data->a = a;
	data->b = b;
	data->strat = ADAPTIVE;
	data->bench = 0;
	data->disorder = 0;
	ft_memset(data->ops, 0, sizeof(data->ops));
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_data	data;

	if (argc < 2)
		return (0);
	init_data(&data, &a, &b);
	//parser(argc, argv, &data);
	return (0);
}
