/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:29:17 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/30 02:53:43 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_putnbr_base_fd(unsigned long long n, char *base, int fd)
{
	unsigned long long	base_size;
	int					bytes_printed;

	bytes_printed = 0;
	base_size = ft_strlen(base);
	if (n >= base_size)
		bytes_printed += ft_putnbr_base_fd(n / base_size, base, fd);
	ft_putchar_fd(base[n % base_size], fd);
	return (++bytes_printed);
}
