/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hexadecimal_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:25:55 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/18 10:26:51 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	convert_hexadecimal_fd(int fd, va_list *ap_ptr, char specifier)
{
	unsigned int	num;

	num = va_arg(*ap_ptr, unsigned int);
	if (specifier == 'x')
		return (ft_putnbr_base_fd(num, BASE16_LOWERCASE, fd));
	else if (specifier == 'X')
		return (ft_putnbr_base_fd(num, BASE16_UPPERCASE, fd));
	return (0);
}
