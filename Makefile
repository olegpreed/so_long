# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: preed <preed@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 14:36:11 by preed             #+#    #+#              #
#    Updated: 2022/01/19 18:16:33 by preed            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = $(SRC_GNL) $(SRC_LIBFT) $(SRC_GAME)

SRC_GNL = get_next_line.c get_next_line_utils.c

SRC_LIBFT = libft_1.c libft_2.c

SRC_GAME = main.c preparation.c render.c init.c utils.c map_check.c input.c

CC = gcc

FLAGS = -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror

all: ${NAME}

${NAME}: $(SRC) ./maps/* so_long.h
	${CC} ${FLAGS} $(SRC) -o ${NAME}

clean: 
	rm $(NAME)

## gcc  -g -lmlx -framework OpenGL -framework AppKit *.c -o so_long