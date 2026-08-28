/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 20:10:37 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/28 21:51:28 by nd-abreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i])
	{
		free(split_args[i]);
		i++;
	}
	free(split_args);
}

static int	parse_integer(t_data *data, char *arg)
{
	long long	num;

	if (!ft_isnumber(arg))
		return (-1);
	num = ft_atol(arg);
	if (num < INT_MIN || num > INT_MAX)
		return (-1);
	if (stack_dup(data, (int) num))
		return (-1);
	// TODO: stack_add(data, num)
	return (0);
}

int	parse_numbers(t_data *data, char *arg)
{
	char	**split_args;
	int		i;
	int		exit_code;

	split_args = ft_split(arg, ' ');
	if (!split_args || !split_args[0])
		return (-1);
	i = 0;
	while (split_args[i] && exit_code == 0)
	{
		exit_code = parse_integer(data, split_args[i]);
		i++;
	}
	if (exit_code != 0)
		free_split(split_args);
	return (exit_code);
}

