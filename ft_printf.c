/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:30:45 by bbordere          #+#    #+#             */
/*   Updated: 2021/12/09 12:39:14 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(char *str, ...)
{
	va_list	ap;
	size_t	i;

	va_start(ap, *str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) == 'c')
			write(1, va_arg(ap, char *), 1);
		if (*str == '%' && *(str + 1) == 's')
			ft_putstr(va_arg(ap, char *));
		if (*str == '%' && (*(str + 1) == 'i') || *(str + 1) == 'd')
			ft_putnbr(va_arg(ap, int));
		if (*str == '%' && *(str + 1) == 'u')
			ft_putnbr_base(va_arg(ap, unsigned int), DECIMAL_BASE);
		if (*str == '%' && *(str + 1) == 'x')
			ft_putnbr_base(va_arg(ap, unsigned int), HEXA_BASE_L);
		if (*str == '%' && *(str + 1) == 'X')
			ft_putnbr_base(va_arg(ap, unsigned int), HEXA_BASE_U);
		if (*str == '%' && *(str + 1) == '%')
			write(1, "%", 1);
		if (*str == '%')
			str++;
		else
			write(1, str, 1);
		str++;
	}
	va_end(ap);
}

int main(int argc, char const *argv[])
{
	ft_printf("blq %fl bla %x","456", 456);
}

