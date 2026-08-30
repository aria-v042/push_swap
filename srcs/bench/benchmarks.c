/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmarks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:53:32 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/30 14:19:32 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_disorder_percent_fd(double disorder, int fd)
{
	int	scaled;
	int	whole;
	int	cents;

	scaled = (int)(disorder * 10000 + 0.5);
	whole = scaled / 100;
	cents = scaled % 100;
	ft_putnbr_fd(whole, fd);
	ft_putchar_fd('.', fd);
	if (cents < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(cents, fd);
	ft_putchar_fd('%', fd);
}

static char	*get_strategy(t_strat strat)
{
	if (strat == SIMPLE)
		return ("Simple");
	if (strat == MEDIUM)
		return ("Medium");
	if (strat == COMPLEX)
		return ("Complex");
	if (strat == ADAPTIVE)
		return ("Adaptive");
}

static char	*get_complexity(t_data *data)
{
	if (data->strat == SIMPLE)
		return ("O(n²)");
	if (data->strat == MEDIUM)
		return ("O(n√n)");
	if (data->strat == COMPLEX)
		return ("O(n log n)");
	if (data->disorder < 0.20)
		return ("O(n²)");
	if (data->disorder < 0.50)
		return ("O(n√n)");
	else
		return ("O(n log n)");
}

static int	total_ops(int *ops_count)
{
	int	i;
	int	total;

	i = 0;
	while (i < 11)
	{
		total += ops_count[i];
		i++;
	}
	return (total);
}

void	display_benchmarks(t_data *data)
{
	ft_printf_fd(STDERR_FILENO, "[bench] disorder:  ");
	put_disorder_percent_fd(data->disorder, STDERR_FILENO);
	ft_printf_fd(STDERR_FILENO, "\n");
	ft_printf_fd(STDERR_FILENO, "[bench] strategy:  %s",
		get_strategy(data->strat));
	ft_printf_fd(STDERR_FILENO, " / %d\n", get_complexity(data));
	ft_printf_fd(STDERR_FILENO, "[bench] total_ops:  %d\n",
		total_ops(data->ops_count));
	ft_printf_fd(STDERR_FILENO, "[bench] sa:  %d  sb:  %d  ss:  %d  "
		"pa:  %d  pb:  %d\n",
		data->ops_count[OP_SA], data->ops_count[OP_SB], data->ops_count[OP_SS],
		data->ops_count[OP_PA], data->ops_count[OP_PB]);
	ft_printf_fd(STDERR_FILENO, "[bench] ra:  %d  rb:  %d  rr:  %d  "
		"rra:  %d  rrb:  %d  rrr:  %d\n",
		data->ops_count[OP_RA], data->ops_count[OP_RB], data->ops_count[OP_RR],
		data->ops_count[OP_RRA], data->ops_count[OP_RRB],
		data->ops_count[OP_RRR]);
}
