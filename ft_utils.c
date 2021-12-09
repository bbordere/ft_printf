/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:37:30 by bbordere          #+#    #+#             */
/*   Updated: 2021/12/09 16:53:02 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	nbr;
	char			res;

	if (n < 0)
	{
		nbr = -n;
		write(1, "-", 1);
	}
	else
		nbr = n;
	if (n / 10)
		ft_putnbr(nbr / 10);
	res = (nbr % 10) + '0';
	write(1, &res, 1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(unsigned long n, char *base)
{
	char	res;

	if (n / ft_strlen(base))
		ft_putnbr_base(n / ft_strlen(base), base);
	res = base[n % ft_strlen(base)];
	write(1, &res, 1);
}

void	ft_put_address(void	*p)
{
	unsigned long int	addr;

	addr = (unsigned long)p;
	if (addr == 0)
	{
		ft_putstr(NULL_PTR);
		return ;
	}
	ft_putstr("0x");
	ft_putnbr_base(addr, HEXA_BASE_L);
}
