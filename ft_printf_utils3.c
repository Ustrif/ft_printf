/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 04:20:07 by raydogmu          #+#    #+#             */
/*   Updated: 2024/10/29 04:52:11 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	decimal_len(int n)
{
	int		i;

	if (n < 0)
		i = 1;
	else
		i = 0;
	while (1)
	{
		i++;
		if (n / 10 == 0)
			break ;
		n = n / 10;
	}
	return (i);
}

int	ft_putnbr_base_len(unsigned long nbr, char *base)
{
	int	base_len;
	int	count;

	count = 1;
	base_len = ft_strlen(base);
	if (nbr >= (unsigned long)base_len)
		count += ft_putnbr_base_len(nbr / base_len, base);
	return (count);
}

int	decimal_long_len(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (1)
	{
		i++;
		if (n / 10 == 0)
			break ;
		n = n / 10;
	}
	return (i);
}

void	ft_putnbr_base(unsigned long nbr, char *base)
{
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16, base);
	ft_putchar(base[nbr % 16]);
}
