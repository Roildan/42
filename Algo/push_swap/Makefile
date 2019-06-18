# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armoulin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/28 13:51:05 by armoulin          #+#    #+#              #
#    Updated: 2019/04/26 16:19:45 by armoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
GREEN				= \033[0;32m
RED					= \033[0;31m
RESET				= \033[0m

NAME_CHECKER		= checker
NAME_PUSH			= push_swap

CC					= gcc
CFLAGS				= -Wall -Wextra -Werror

PRINTF_DIR			= ./ft_printf/
PRINTF_HEADER		= $(PRINTF_DIR)includes/
PRINTF				= $(PRINTF_DIR)libftprintf.a

MINILIBX_DIR		= minilibx/
MINILIBX_HEAD		= $(MINILIBX_DIR)
MINILIBX			= $(MINILIBX_DIR)libmlx.a

HEADERS_DIR			= ./includes/
HEADERS_MUTUAL_LST	= main.h
HEADERS_CHECKER_LST	= checker.h \
					  graphic.h
HEADERS_PUSH_LST	= push_swap.h
HEADERS_MUTUAL		= $(addprefix $(HEADERS_DIR), $(HEADERS_MUTUAL_LST))
HEADERS_CHECKER		= $(addprefix $(HEADERS_DIR), $(HEADERS_CHECKER_LST))
HEADERS_PUSH		= $(addprefix $(HEADERS_DIR), $(HEADERS_PUSH_LST))


INCLUDES			= -I$(HEADERS_DIR) -I$(PRINTF_HEADER) -I$(MINILIBX_HEAD)
LIBRARIES			= -L$(PRINTF_DIR) -lftprintf -L$(MINILIBX_DIR) -lmlx \
					  -framework OpenGL -framework AppKit

SOURCES_DIR			= ./srcs/
SOURCES_MUTUAL_LST	= check_pile.c \
					  manage_pile.c \
					  get_piles.c \
					  tools.c \
					  swap.c \
					  push.c \
					  rotate.c \
					  rrotate.c
SOURCES_MUTUAL		= $(addprefix $(SOURCES_DIR), $(SOURCES_MUTUAL_LST))

SOURCES_CHECKER_DIR	= $(SOURCES_DIR)checker/
SOURCES_CHECKER_LST	= main.c \
					  manage_list.c \
					  check_opp.c \
					  push.c \
					  rotate.c \
					  rrotate.c \
					  swap.c \
					  tools.c \
					  graphic.c \
					  graphic_tools.c \
					  draw_title.c \
					  event_management.c
SOURCES_CHECKER		= $(addprefix $(SOURCES_CHECKER_DIR), $(SOURCES_CHECKER_LST))

SOURCES_PUSH_DIR	= $(SOURCES_DIR)push_swap/
SOURCES_PUSH_LST	= main.c \
					  push.c \
					  rotate.c \
					  rrotate.c \
					  swap.c \
					  tools.c \
					  cchiant.c
SOURCES_PUSH		= $(addprefix $(SOURCES_PUSH_DIR), $(SOURCES_PUSH_LST))


OBJECTS_DIR			= ./bin/
OBJECTS_MUTUAL_LST	= $(patsubst %.c, %.o, $(SOURCES_MUTUAL_LST))
OBJECTS_MUTUAL		= $(addprefix $(OBJECTS_DIR), $(OBJECTS_MUTUAL_LST))

OBJECTS_CHECKER_DIR	= $(OBJECTS_DIR)checker/
OBJECTS_CHECKER_LST	= $(patsubst %.c, %.o, $(SOURCES_CHECKER_LST))
OBJECTS_CHECKER		= $(addprefix $(OBJECTS_CHECKER_DIR), $(OBJECTS_CHECKER_LST))

OBJECTS_PUSH_DIR	= $(OBJECTS_DIR)push_swap/
OBJECTS_PUSH_LST	= $(patsubst %.c, %.o, $(SOURCES_PUSH_LST))
OBJECTS_PUSH		= $(addprefix $(OBJECTS_PUSH_DIR), $(OBJECTS_PUSH_LST))

.PHONY: all, clean, fclean, re

all:				$(NAME_CHECKER) $(NAME_PUSH)

$(NAME_CHECKER):	$(PRINTF) $(MINILIBX) $(OBJECTS_CHECKER_DIR) $(OBJECTS_CHECKER) $(OBJECTS_MUTUAL)
	@$(CC) $(CFLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS_MUTUAL) $(OBJECTS_CHECKER) -o $@
	@echo "$(NAME_CHECKER): $(GREEN)$(NAME_CHECKER)		was compiled !$(RESET)"

$(NAME_PUSH):		$(PRINTF) $(OBJECTS_PUSH_DIR) $(OBJECTS_MUTUAL) $(OBJECTS_PUSH)
	@$(CC) $(CFLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS_MUTUAL) $(OBJECTS_PUSH) -o $@
	@echo "$(NAME_PUSH): $(GREEN)$(NAME_PUSH)		was compiled !$(RESET)"

$(PRINTF):
	@echo "$(PRINTF): $(GREEN)Compiling $(PRINTF)...$(RESET)"
	@make -sC $(PRINTF_DIR)

$(MINILIBX):
	@echo "$(MINILIBX): $(GREEN)Compiling $(MINILIBX)...$(RESET)"
	@make -sC $(MINILIBX_DIR)


$(OBJECTS_CHECKER_DIR): $(OBJECTS_DIR)
	@mkdir -p $(OBJECTS_CHECKER_DIR)
	@echo "$(NAME_CHECKER): $(GREEN)$(OBJECTS_CHECKER_DIR)		was created !$(RESET)"

$(OBJECTS_PUSH_DIR): $(OBJECTS_DIR)
	@mkdir -p $(OBJECTS_PUSH_DIR)
	@echo "$(NAME_PUSH): $(GREEN)$(OBJECTS_PUSH_DIR)		was created !$(RESET)"

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)
	@echo "$(NAME_PUSH): $(GREEN)$(OBJECTS_DIR)		was created !$(RESET)"

$(OBJECTS_DIR)%.o:	$(SOURCES_DIR)%.c $(HEADERS_MUTUAL)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(NAME_PUSH): $(GREEN)$@	was compiled !$(RESET)"

$(OBJECTS_CHECKER_DIR)%.o:	$(SOURCES_CHECKER_DIR)%.c $(HEADERS_CHECKER)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(NAME_CHECKER): $(GREEN)$@	was compiled !$(RESET)"

$(OBJECTS_PUSH_DIR)%.o:	$(SOURCES_PUSH_DIR)%.c $(HEADERS_PUSH)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(NAME_PUSH): $(GREEN)$@	was compiled !$(RESET)"

clean:
	@make clean -sC $(PRINTF_DIR)
	@make clean -sC $(MINILIBX_DIR)
	@rm -rf $(OBJECTS_DIR)
	@echo "$(NAME_PUSH): $(RED)binary files	were deleted.$(RESET)"
	@echo "$(NAME_PUSH): $(RED)$(OBJECTS_DIR)		was deleted.$(RESET)"

fclean:				clean
	@make fclean -sC $(PRINTF_DIR)
	@rm -f $(NAME_CHECKER) $(NAME_PUSH)
	@echo "$(NAME_CHECKER): $(RED)$(NAME_CHECKER)		was deleted.$(RESET)"
	@echo "$(NAME_PUSH): $(RED)$(NAME_PUSH)		was deleted.$(RESET)"

re:					fclean all
