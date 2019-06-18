# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armoulin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 16:26:26 by armoulin          #+#    #+#              #
#    Updated: 2018/11/06 16:58:29 by armoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CFLAGS	= -Wall -Wextra -Werror

DIRSRC	= srcs
DIRINC	= includes

SRCS	= ft_putchar.c \
		  ft_putstr.c \
		  ft_strcmp.c \
		  ft_strlen.c \
		  ft_swap.c

SOURCES	= $(addprefix $(DIRSRC)/, $(SRCS))
OBJECTS	= $(SRCS:.c=.o)

all: $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJECTS): $(SOURCES)
	gcc $(CFLAGS) -I$(DIRINC) -c $(SOURCES)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
