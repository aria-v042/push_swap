/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:29:17 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/18 10:30:02 by frodrig2         ###   ########.fr       */
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

size_t	ft_numlen(int n)
{
	size_t		count;
	long long	big;

	count = 0;
	if (n == 0)
		return (++count);
	big = (long long) n;
	if (big < 0)
	{
		count++;
		big *= -1;
	}
	while (big > 0)
	{
		count++;
		big /= 10;
	}
	return (count);
}
