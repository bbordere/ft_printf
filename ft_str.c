/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:56:10 by bbordere          #+#    #+#             */
/*   Updated: 2021/12/14 15:21:51 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *i)
{
	write(1, &c, 1);
	(*i)++;
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int *i)
{
	if (!str)
	{
		ft_putstr(NUL_STR, i);
		return ;
	}
	write(1, str, ft_strlen(str));
	(*i) += ft_strlen(str);
}
