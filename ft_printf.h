/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:05:19 by raydogmu          #+#    #+#             */
/*   Updated: 2024/11/11 11:46:31 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
void	ft_putstr(const char *s);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putnbr_base(unsigned long nbr, char *base);
void	ft_putunsignednbr(unsigned int nbr);
int		char_proccess(char c, va_list args);
int		ft_strlen(char *s);
int		decimal_len(int n);
int		char_proccess2(char c, va_list args);
int		char_proccess3(char c, va_list args);
int		ft_putnbr_base_len(unsigned long nbr, char *base);
int		decimal_long_len(unsigned int n);
int		xx_process(unsigned long arg, char *base);
int		null_text(char *k);

#endif