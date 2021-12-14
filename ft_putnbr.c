/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:37:30 by bbordere          #+#    #+#             */
/*   Updated: 2021/12/14 15:21:52 by bbordere         ###   ########.fr       */
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
	char	res;

	if (n / ft_strlen(base))
		ft_putnbr_base(n / ft_strlen(base), base, i);
	res = base[n % ft_strlen(base)];
	ft_putchar(res, i);
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
