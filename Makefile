NAME = so_long

SRC = main.c

CC = gcc

FLAGS =   -lmlx -framework OpenGL -framework AppKit

all: ${NAME}

${NAME}: main.c utils.c get_next_line.c get_next_line_utils.c render.c init.c map.ber so_long.h input.c
	${CC} ${FLAGS}  main.c utils.c  get_next_line.c render.c get_next_line_utils.c init.c  input.c -o ${NAME}

## gcc  -g -lmlx -framework OpenGL -framework AppKit main.c utils.c get_next_line.c get_next_line_utils.c render.c init.c -o so_long