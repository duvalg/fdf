# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/27 11:25:13 by gduval            #+#    #+#              #
#    Updated: 2017/07/27 11:25:16 by gduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT_NAME = libft.a
LIBFT_PATH = ./libft/
LIBFT = $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))

SRC_PATH = ./srcs/
SRC_NAME = main.c						\
			init_struct.c				\
			parse.c						\
			check_map.c					\
			init_mlx.c					\
			print_map.c					\
			padding_gestion.c			\
			bresenham.c					\
			rotation_matrix.c			\
			keyhook_1.c					\
			keyhook_2.c					\
			exit.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(SRC_NAME:.c=.o)

HEADER_PATH = ./includes/
HEADER_NAME = fdf.h
HEADER = $(addprefix $(HEADER_PATH), $(HEADER_NAME))

FLAGS = -framework OpenGL -framework AppKit -Werror -Wextra -Wall
CC = gcc

all: $(NAME)

$(NAME) :
	@echo "\033[93m----------------------------------\033[0m"
	@echo "\033[93m-         FDF COMPILATION        -\033[0m"
	@echo "\033[93m----------------------------------\033[0m"
	@make -C libft
	@$(CC) minilibx_macos/libmlx.a $(FLAGS) $(LIBFT) $(SRC) -o $(NAME)
	@echo "\033[93m-              done              -\033[0m"

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
