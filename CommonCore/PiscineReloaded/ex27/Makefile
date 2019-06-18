# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armoulin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 11:39:02 by armoulin          #+#    #+#              #
#    Updated: 2018/11/07 12:34:02 by armoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_display_file

CFLAGS	= -Wall -Wextra -Werror

DIRSRC	= srcs

SRCS	= main.c

SOURCES	= $(addprefix $(DIRSRC)/, $(SRCS))
OBJECTS	= $(SRCS:.c=.o)

all: $(OBJECTS)
	gcc $(CFLAGS) $(OBJECTS) -o $(NAME)

$(OBJECTS): $(SOURCES)
	gcc $(CFLAGS) -c $(SOURCES)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
