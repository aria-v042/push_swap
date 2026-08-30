/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:30:13 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/30 02:55:59 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H

# include "libft.h"
# include <stdarg.h>

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# define BASE10 "0123456789"
# define BASE16_LOWERCASE "0123456789abcdef"
# define BASE16_UPPERCASE "0123456789ABCDEF"

/* ==== CORE ==== */

int		ft_printf_fd(int fd, const char *format, ...);

/* ==== FORMAT PARSING ==== */

int		parse_specification_fd(int fd, const char *format, va_list *ap_ptr);

int		convert_char_fd(int fd, va_list *ap_ptr);
int		convert_string_fd(int fd, va_list *ap_ptr);
int		convert_pointer_fd(int fd, va_list *ap_ptr);
int		convert_integer_fd(int fd, va_list *ap_ptr);
int		convert_unsigned_fd(int fd, va_list *ap_ptr);
int		convert_hexadecimal_fd(int fd, va_list *ap_ptr, char specifier);

/* ==== UTILS ==== */

int		ft_putnbr_base_fd(unsigned long long n, char *base, int fd);

#endif
