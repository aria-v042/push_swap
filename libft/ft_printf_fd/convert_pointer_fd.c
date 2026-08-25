/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pointer_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:22:28 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/18 10:23:43 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	convert_pointer_fd(int fd, va_list *ap_ptr)
{
	uintptr_t	address;

	address = (uintptr_t)va_arg(*ap_ptr, void *);
	if (!address)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	ft_putstr_fd("0x", fd);
	return (2 + ft_putnbr_base_fd(address, BASE16_LOWERCASE, fd));
}
