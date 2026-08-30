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

static void	error_exit(t_data *data)
{
	stack_free(&data->a);
	stack_free(&data->b);
	ft_printf_fd(2, "Error\n");
	exit (1);
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
	return (0);
}
