CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = so_long

all : $(NAME)

$(NAME) :
	$(CC) -g get_next_line/*.c libft/libft.a game.c utils.c main.c -L./minilibx-linux -lmlx_Linux -I./minilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

clean :
	rm $(NAME)
re : clean all
.PHONY : all clean
