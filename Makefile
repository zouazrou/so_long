CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = so_long

all : $(NAME)

$(NAME) :
	$(CC) -g utils.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./libft/libft.a main.c -o $(NAME)

clean :
	rm $(NAME)
re : clean all
.PHONY : all clean