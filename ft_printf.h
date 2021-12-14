/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:38:08 by bbordere          #+#    #+#             */
/*   Updated: 2021/12/14 15:42:12 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define HEXA_BASE_U "0123456789ABCDEF"
# define HEXA_BASE_L "0123456789abcdef"
# define DECIMAL_BASE "0123456789"
# define NUL_STR "(null)"

# ifdef __linux__
#  define NULL_PTR "(nil)"

# elif
#  ifdef __APPLE__
#   define NULL_PTR "0x0"
#  endif

# else
#  define NULL_PTR "0x0"
# endif

void	ft_putstr(char *str, int *i);
void	ft_putnbr(int n, int *i);
size_t	ft_strlen(const char *str);
void	ft_putnbr_base(unsigned long n, char *base, int *i);
void	ft_put_address(void	*p, int *i);
void	ft_putchar(int c, int *i);
int		ft_printf(const char *str, ...);

#endif