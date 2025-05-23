CC = cc

CFLAGS = -g -Wall -Wextra -Werror

FLAG_MLX = -lXext -lX11

LIBFT = libft/libft.a

LIBMLX_PATH = /usr/include/minilibx-linux/

LIBMLX = $(LIBMLX_PATH)libmlx.a

SRC = $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c) \
	game.c do_op.c error.c utils.c check_position.c so_long.c

SRC_BONUS =	$(addprefix get_next_line/, get_next_line.c get_next_line_utils.c) \
			$(addprefix bonus/, game_bonus.c do_op_bonus.c error_bonus.c \
				utils_bonus.c check_position_bonus.c init_images_bonus.c \
				animation_bonus.c init_members_bonus.c so_long_bonus.c)


OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)


NAME = so_long
NAME_BONUS = so_long_bonus


all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(FLAG_MLX) -o $(NAME)

$(LIBFT) :
	make -C libft

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBMLX) $(FLAG_MLX) $(LIBFT) -o $(NAME_BONUS)

clean :
	rm -f $(OBJ) $(OBJ_BONUS)
	make -C libft clean

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C libft fclean

re : fclean all

.PHONY : all clean fclean re bonus
