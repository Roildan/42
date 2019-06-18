# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armoulin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/28 13:51:05 by armoulin          #+#    #+#              #
#    Updated: 2019/04/07 18:36:37 by armoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

NAME			= fdf

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

LIBFT_DIR		= libft/
LIBFT_HEAD		= $(LIBFT_DIR)includes/
LIBFT			= $(LIBFT_DIR)libft.a

MINILIBX_DIR	= minilibx/
MINILIBX_HEAD	= $(MINILIBX_DIR)
MINILIBX		= $(MINILIBX_DIR)libmlx.a

HEADERS_DIR		= includes/
HEADERS_LST		= fdf.h \
				  maplist.h \
				  err_msg.h \
				  colors.h \
				  settings.h
HEADERS			= $(addprefix $(HEADERS_DIR), $(HEADERS_LST))

INCLUDES		= -I$(HEADERS_DIR) -I$(LIBFT_HEAD) -I$(MINILIBX_HEAD)
LIBRARIES		= -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx \
				  -framework OpenGL -framework AppKit

SOURCES_DIR		= srcs/
SOURCES_LST		= main.c \
				  maplist.c \
				  parse.c \
				  init.c \
				  draw_tools.c \
				  draw_rotations.c \
				  draw_projections.c \
				  draw_title_menu.c \
				  draw_image.c \
				  compute_points.c \
				  tools.c \
				  colors.c \
				  handle_keyboard.c \
				  handle_mouse.c \
				  reset.c \
				  move.c \
				  rotations.c \
				  zoom_altitude.c
SOURCES			= $(addprefix $(SOURCES_DIR), $(SOURCES_LST))

OBJECTS_DIR		= bin/
OBJECTS_LST		= $(patsubst %.c, %.o, $(SOURCES_LST))
OBJECTS			= $(addprefix $(OBJECTS_DIR), $(OBJECTS_LST))

.PHONY: all, clean, fclean, re

all:				$(NAME)

$(NAME):			$(LIBFT) $(MINILIBX) $(OBJECTS_DIR) $(OBJECTS)
	@$(CC) $(CFLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $@
	@echo "$(NAME): $(GREEN)$(NAME)		was compiled !$(RESET)"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Compiling $(LIBFT)...$(RESET)"
	@make -sC $(LIBFT_DIR)

$(MINILIBX):
	@echo "$(NAME): $(GREEN)Compiling $(MINILIBX)...$(RESET)"
	@make -sC $(MINILIBX_DIR)

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIR)		was created !$(RESET)"

$(OBJECTS_DIR)%.o:	$(SOURCES_DIR)%.c $(HEADERS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(NAME): $(GREEN)$@		was compiled !$(RESET)"

clean:
	@make clean -sC $(LIBFT_DIR)
	@make clean -sC $(MINILIBX_DIR)
	@rm -rf $(OBJECTS_DIR)
	@echo "$(NAME): $(RED)$(OBJECTS_DIR)		was deleted.$(RESET)"
	@echo "$(NAME): $(RED)binary files	were deleted.$(RESET)"


fclean:				clean
	@make fclean -sC $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME)		was deleted.$(RESET)"

re:					fclean all
