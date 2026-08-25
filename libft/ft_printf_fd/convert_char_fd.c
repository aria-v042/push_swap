/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:22:07 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/18 10:22:10 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	convert_char_fd(int fd, va_list *ap_ptr)
{
	unsigned char	c;

	c = va_arg(*ap_ptr, int);
	ft_putchar_fd(c, fd);
	return ((int) sizeof(unsigned char));
}
