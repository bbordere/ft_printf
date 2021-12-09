/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:38:08 by bbordere          #+#    #+#             */
/*   Updated: 2021/12/09 11:49:32 by bbordere         ###   ########.fr       */
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

void	ft_putstr(char *str);
void	ft_putnbr(int n);
size_t	ft_strlen(const char *str);
void	ft_putnbr_base(unsigned int n, char *base);

#endif