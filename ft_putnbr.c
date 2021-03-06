/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:37:30 by bbordere          #+#    #+#             */
/*   Updated: 2021/12/15 15:54:50 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *i)
{
	unsigned int	nbr;
	char			res;

	if (n < 0)
	{
		nbr = -n;
		write(1, "-", 1);
		(*i)++;
	}
	else
		nbr = n;
	if (n / 10)
		ft_putnbr(nbr / 10, i);
	res = (nbr % 10) + '0';
	ft_putchar(res, i);
}

void	ft_putnbr_base(unsigned long n, char *base, int *i)
{
	size_t	len;

	len = ft_strlen(base);
	if (n / len)
		ft_putnbr_base(n / len, base, i);
	ft_putchar(base[n % len], i);
}

void	ft_put_address(void	*p, int *i)
{
	unsigned long int	addr;

	addr = (unsigned long)p;
	if (addr == 0)
	{
		ft_putstr(NULL_PTR, i);
		return ;
	}
	ft_putstr("0x", i);
	ft_putnbr_base(addr, HEXA_BASE_L, i);
}
