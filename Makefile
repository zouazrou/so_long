CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = so_long
NAME_BNS = so_long_bonus

all : $(NAME)

$(NAME) :
	$(CC) -g get_next_line/*.c game.c do_op.c error.c utils.c check_position.c so_long.c libft/libft.a -L./minilibx-linux -lmlx_Linux -I./minilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

bonus : $(NAME_BNS)

$(NAME_BNS) :
	$(CC) -g get_next_line/*.c bonus/game_bonus.c bonus/do_op_bonus.c bonus/error_bonus.c bonus/utils_bonus.c bonus/check_position_bonus.c bonus/so_long_bonus.c libft/libft.a -L./minilibx-linux -lmlx_Linux -I./minilibx-linux -lXext -lX11 -lm -lz -o $(NAME_BNS)



clean :
	rm $(NAME) $(NAME_BNS)
re : clean all
.PHONY : all clean bonus
