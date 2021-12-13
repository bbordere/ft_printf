/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:30:45 by bbordere          #+#    #+#             */
/*   Updated: 2021/12/13 16:40:31 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar(int c, int *i)
{
	write(1, &c, 1);
	(*i)++;
}

void	ft_args(va_list ap, char *str, int *i)
{
	while (*str)
	{
		if (*str == '%' && *(str + 1) == 'c')
			ft_putchar(va_arg(ap, int), i);
		if (*str == '%' && *(str + 1) == 's')
			ft_putstr(va_arg(ap, char *), i);
		if (*str == '%' && (*(str + 1) == 'i' || *(str + 1) == 'd'))
			ft_putnbr(va_arg(ap, int), i);
		if (*str == '%' && *(str + 1) == 'u')
			ft_putnbr_base(va_arg(ap, unsigned int), DECIMAL_BASE, i);
		if (*str == '%' && *(str + 1) == 'x')
			ft_putnbr_base(va_arg(ap, unsigned int), HEXA_BASE_L, i);
		if (*str == '%' && *(str + 1) == 'X')
			ft_putnbr_base(va_arg(ap, unsigned int), HEXA_BASE_U, i);
		if (*str == '%' && *(str + 1) == 'p')
			ft_put_address(va_arg(ap, void *), i);
		if (*str == '%' && *(str + 1) == '%')
			ft_putchar('%', i);
		if (*str == '%')
			str++;
		else
			ft_putchar(*str, i);
		str++;
	}
}

int	ft_printf(char *str, ...)
{
	va_list		ap;
	int	i;

	i = 0;
	va_start(ap, str);
	ft_args(ap, str, &i);
	va_end(ap);
	return (i);
}
/*
int main(void)
{
	printf("%d \n",ft_printf("%dxC is the lowest temperature in the universe", -273));
	printf("%d \n ",printf("%dxC is the lowest temperature in the universe", -273));
}
*/