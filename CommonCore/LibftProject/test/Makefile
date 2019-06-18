# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armoulin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:32:34 by armoulin          #+#    #+#              #
#    Updated: 2018/11/08 18:58:17 by armoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= test

LIB		= ../Libft/libft.a

CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c \
		  test_part1.c \
		  test_part2.c
DIRSRC	= srcs
SOURCES	= $(addprefix $(DIRSRC)/, $(SRCS))

all: $(OBJS)
	gcc $(CFLAGS) $(SOURCES) $(LIB) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: clean fclean
