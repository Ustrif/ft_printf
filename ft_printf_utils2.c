/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:24:32 by raydogmu          #+#    #+#             */
/*   Updated: 2024/11/11 12:16:56 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	null_text(char *k)
{
	if (k == NULL)
	{
		ft_printf("(null)");
		return (6);
	}
	else
	{
		ft_putstr(k);
		return (ft_strlen(k));
	}
}

int	char_proccess(char c, va_list args)
{
	int		count;
	char	*text;
	int		nbrm;

	count = 0;
	if (c == 'c')
		ft_putchar((unsigned char) va_arg(args, int));
	else if (c == '%')
		ft_putchar('%');
	else if (c == 's')
	{
		text = va_arg(args, char *);
		count += null_text(text);
	}
	else if (c == 'd' || c == 'i')
	{
		nbrm = va_arg(args, int);
		ft_putnbr(nbrm);
		count += decimal_len(nbrm);
	}
	else
		count += char_proccess2(c, args);
	return (count);
}

int	char_proccess2(char c, va_list args)
{
	int		count;
	void	*ptr;

	count = 0;
	if (c == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
			return (write(1, "(nil)", 5));
		ft_putstr("0x");
		ft_putnbr_base((unsigned long) ptr, "0123456789abcdef");
		count += ft_putnbr_base_len((unsigned long) ptr, "0123456789abcdef");
		count += 2;
	}
	else if (c == 'x')
		count += xx_process(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += xx_process(va_arg(args, unsigned int), "0123456789ABCDEF");
	else
		count += char_proccess3(c, args);
	return (count);
}

int	xx_process(unsigned long arg, char *base)
{
	int	count;

	count = 0;
	ft_putnbr_base(arg, base);
	count += ft_putnbr_base_len(arg, base);
	return (count);
}

int	char_proccess3(char c, va_list args)
{
	int	count;
	int	nbrm;

	count = 0;
	if (c == 'u')
	{
		nbrm = va_arg(args, unsigned long);
		ft_putunsignednbr(nbrm);
		count += decimal_long_len(nbrm);
	}
	return (count);
}
