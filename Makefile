# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: preed <preed@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 14:36:11 by preed             #+#    #+#              #
#    Updated: 2022/02/15 19:19:59 by preed            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = $(MAIN_SRC) $(SRC_GNL) $(SRC_LIBFT) $(SRC_GAME) $(SRC_MENU)

MAIN_SRC = main.c

GAME = preparation.c display.c display2.c display3.c render.c init.c \
		move.c utils.c utils2.c utils3.c map_check.c \
		input.c patrol_init.c patrol.c patrol_move.c \
		game_over.c win.c sprites.c lvl_name.c 

SRC_GAME = $(addprefix game/, $(GAME))

MENU = menu.c lvl_select.c

SRC_MENU = $(addprefix menu/, $(MENU))

GNL = get_next_line.c get_next_line_utils.c

SRC_GNL = $(addprefix gnl/, $(GNL))

LIBFT = libft_1.c libft_2.c libft_3.c ft_atoi.c ft_itoa.c ft_split.c

SRC_LIBFT = $(addprefix libft/, $(LIBFT))

OBJS = ${SRCS:.c=.o}

CC = gcc

%.o: %.c		${HEADER}
				${CC}  -c $< -o ${<:.c=.o}

FLAGS = -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror
#FLAGS = -lmlx -framework OpenGL -Lminilibx -framework AppKit -Wall -Wextra -Werror

all: ${NAME}

${NAME}: $(SRC) $(OBJS) ./maps/* so_long.h
	${CC} ${FLAGS} $(SRC) -o ${NAME}

clean: 
	rm $(NAME)
	