# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 21:21:22 by raydogmu          #+#    #+#              #
#    Updated: 2024/10/29 05:21:00 by raydogmu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFILES = ft_printf_utils.c ft_printf.c ft_printf_utils2.c ft_printf_utils3.c

OFILES = $(CFILES:.c=.o)
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	ar r $(NAME) $(OFILES)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re