CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = so_long

all : $(NAME)

$(NAME) :
	$(CC) -g get_next_line/*.c game.c do_op.c error.c utils.c main.c libft/libft.a -L./minilibx-linux -lmlx_Linux -I./minilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

clean :
	rm $(NAME)
re : clean all
.PHONY : all clean
