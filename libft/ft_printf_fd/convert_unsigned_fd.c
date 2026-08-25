/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:25:08 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/18 10:25:34 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	convert_unsigned_fd(int fd, va_list *ap_ptr)
{
	unsigned int	num;

	num = va_arg(*ap_ptr, unsigned int);
	return (ft_putnbr_base_fd(num, BASE10, fd));
}
