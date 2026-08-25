/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_integer_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:24:13 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/18 10:24:47 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	convert_integer_fd(int fd, va_list *ap_ptr)
{
	int	num;

	num = va_arg(*ap_ptr, int);
	ft_putnbr_fd(num, fd);
	return ((int)ft_numlen(num));
}
