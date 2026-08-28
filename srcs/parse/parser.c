/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 18:49:47 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/28 20:13:18 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_flag(char *arg)
{
	return (ft_strncmp(arg, "--", 2) == 0);
}

int	parser(t_data *data, int argc, char **argv)
{
	int	i;
	int exit_code;

	i = 1;
	while (i < argc && exit_code == 0)
	{
		if (is_flag(argv[i]))
			exit_code = parse_flag(data, argv[i]);
		else
			exit_code = parse_numbers(data, argv[i]);
		i++;
	}
	return (exit_code);
}
