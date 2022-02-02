# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 14:36:11 by preed             #+#    #+#              #
#    Updated: 2022/02/02 17:24:57 by oleg             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = $(SRC_GNL) $(SRC_LIBFT) $(SRC_GAME)

SRC_GNL = get_next_line.c get_next_line_utils.c

SRC_LIBFT = libft_1.c libft_2.c

SRC_GAME = main.c preparation.c render.c init.c utils.c map_check.c input.c patrol_init.c patrol.c game_over.c

OBJS			= ${SRCS:.c=.o}

CC = gcc

%.o: %.c		${HEADER}
				${CC}  -c $< -o ${<:.c=.o}

FLAGS = -g -lmlx -framework OpenGL -Lminilibx -framework AppKit -Wall -Wextra -Werror

all: ${NAME}

${NAME}: $(SRC) $(OBJS) ./maps/* so_long.h
	${CC} ${FLAGS} $(SRC) -o ${NAME}

clean: 
	rm $(NAME)

## gcc  -g -lmlx -framework OpenGL -framework AppKit *.c -o so_long