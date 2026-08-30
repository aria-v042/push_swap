/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 12:41:11 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/30 01:18:59 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_sort(t_data *data)
{
	if (data->strat == SIMPLE)
		simple_sort(data);
	else if (data->strat == MEDIUM)
		medium_sort(data);
	else if (data->strat == COMPLEX)
		complex_sort(data);
	else if (data->strat == ADAPTIVE)
	{
		if (data->disorder < 0.20)
			simple_sort(data);
		else if (data->disorder >= 0.20 && data->disorder < 0.50)
			medium_sort(data);
		else
			complex_sort(data);
	}
}

static void	init_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->strat = ADAPTIVE;
	data->bench_mode = 0;
	data->disorder = 0;
	ft_memset(data->ops_count, 0, sizeof(data->ops_count));
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (1);
	init_data(&data);
	if (parser(&data, argc, argv) != 0)
		error_exit(&data);
	set_disorder(&data);
	run_sort(&data);
	return (0);
}
