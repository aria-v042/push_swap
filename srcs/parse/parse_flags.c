/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 19:44:19 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/28 20:09:31 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_flag(t_data *data, char *arg)
{
	if (!ft_strncmp(arg, "--simple", 8))
		data->strat = SIMPLE;	
	else if (!ft_strncmp(arg, "--medium", 8))
		data->strat = MEDIUM;	
	else if (!ft_strncmp(arg, "--complex", 9))
		data->strat = COMPLEX;	
	else if (!ft_strncmp(arg, "--adaptive", 10))
		data->strat = ADAPTIVE;	
	else if (!ft_strncmp(arg, "--bench", 7))
		data->bench_mode = 1;
	else
		return (-1);
	return (0);
}

