/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:27:34 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/18 10:27:56 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	parse_specification_fd(int fd, const char *format, va_list *ap_ptr)
{
	if (*format == 'c')
		return (convert_char_fd(fd, ap_ptr));
	if (*format == 's')
		return (convert_string_fd(fd, ap_ptr));
	if (*format == 'p')
		return (convert_pointer_fd(fd, ap_ptr));
	if (*format == 'd' || *format == 'i')
		return (convert_integer_fd(fd, ap_ptr));
	if (*format == 'u')
		return (convert_unsigned_fd(fd, ap_ptr));
	if (*format == 'x' || *format == 'X')
		return (convert_hexadecimal_fd(fd, ap_ptr, *format));
	if (*format == '%')
	{
		ft_putchar_fd('%', fd);
		return (1);
	}
	return (0);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	ap;
	int		bytes_printed;

	bytes_printed = 0;
	va_start(ap, format);
	if (fd < 0 || fd >= FD_MAX || !format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			bytes_printed += parse_specification_fd(fd, ++format, &ap);
		}
		else
		{
			bytes_printed += write(fd, format, 1);
		}
		format++;
	}
	va_end(ap);
	return (bytes_printed);
}
