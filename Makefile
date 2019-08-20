# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 18:38:09 by dtoy              #+#    #+#              #
#    Updated: 2019/08/13 21:22:07 by dtoy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
MAKE = make
FLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGL -framework AppKit
CFILES = \
        src/main.c \
		src/ft_key_press.c \
		src/ft_mouse_press.c \
		src/ft_mouse_move.c \
		src/ft_init_all.c \
		src/ft_threads_init.c \
		src/ft_draw_mandelbrot.c \
		src/ft_draw_julia.c \
		src/ft_draw_burningship.c \
		src/ft_put_color.c \
		src/ft_change_color.c \
		src/ft_error.c \
		src/ft_draw_tricorn.c
OFILES = $(CFILES:%.c=%.o)
LIBINC = libft/includes
LIBPATH = libft/
FT = ft
LFTPATH = $(LIBPATH)
LFT = $(addprefix lib, $(addsuffix .a, $(FT)))
LIBFT = -L$(LFTPATH) -l$(FT)
MKFT = $(MAKE) -C $(LFTPATH)
MLX = mlx
LMLXPATH = minilibx_macos/
LMLX = $(addprefix lib, $(addsuffix .a, $(MLX)))
LIBMLX = -L$(LMLXPATH) -l$(MLX)
MKMLX = $(MAKE) -C $(LMLXPATH)
SRC = $(CFILES)
OBJS = $(OFILES)
INC = includes/
INCLUDES = -I$(LIBINC) -I$(LMLXPATH) -I$(INC)
LIB = -lm $(LIBFT) $(LIBMLX)
all: $(NAME)
$(NAME) : $(LFT) $(LMLX) $(OBJS)
		$(CC) -o $(NAME) $(INCLUDES) $(LIB) $(FRAMEWORKS) $(OBJS)
%.o: %.c
		$(CC) $(FLAGS) -o $@ $(INCLUDES) -c $<
$(LFT):
		$(MKFT)
$(LMLX):
		$(MKMLX)
clean:
		$(MKFT) clean
		$(MKMLX) clean
		rm -rf $(OBJS)
fclean: clean
		$(MKFT) fclean
		rm -rf $(NAME)
re: fclean all