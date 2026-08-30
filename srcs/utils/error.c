/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 21:21:53 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/29 21:22:38 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_data *data)
{
	stack_free(&data->a);
	stack_free(&data->b);
	ft_printf_fd(2, "Error\n");
	exit (1);
}
