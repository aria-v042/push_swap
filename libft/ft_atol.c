/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 20:37:42 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/30 13:55:45 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atol(const char *s)
{
	long long	lota;
	int			sign;

	while (ft_isspace(*s))
	{
		s++;
	}
	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	lota = 0;
	while (*s >= '0' && *s <= '9')
	{
		lota *= 10;
		lota += *s - '0';
		s++;
	}
	return (lota * sign);
}
