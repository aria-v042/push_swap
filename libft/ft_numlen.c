/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 02:53:16 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/30 02:53:33 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
