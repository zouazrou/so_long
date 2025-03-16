/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:48:49 by zouazrou          #+#    #+#             */
/*   Updated: 2025/03/16 21:29:30 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "/usr/include/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define PERROR 1
# define MAP 2

typedef struct s_coord
{
	int		x;
	int		y;
}			t_coord;

typedef struct s_info
{
	void	**img;
	int		nb_frm;
	t_coord	coord;
	int		amount;
}			t_info;

typedef struct s_game
{
	char	**grid;
	int		length;
	int		width;
	void	*mlx;
	void	*win;
	int		moves;
	t_info	wall;
	t_info	player;
	t_info	enemy;
	t_info	exit;
	t_info	empty;
	t_info	coll;
}			t_game;

# define SIZE 32

bool		is_exit(t_game *map, int x, int y);
bool		is_empty_sp(t_game *map, int x, int y);
bool		is_wall(t_game *map, int x, int y);
bool		is_coll(t_game *map, int x, int y);
bool		is_player(t_game *map, int x, int y);
bool		is_enemy(t_game *map, int x, int y);

void		destroy_all(t_game *map, int err);
int			close_win(t_game *map);
void		free_grid(char ***grid, int length);
void		safe_free(char **ptr);

void		put_moves(t_game *map);
int			ft_length(char *file);
bool		is_valid_map(t_game *map, char ***gg);
int			keyboard(int keysym, t_game *map);
void		flood_fill(char **grid, int x, int y);
bool		check_path(char **grid, int l, int w);
void		do_op(t_game *map, char direction);
void		game(t_game *map);

bool	init_enemy(t_game *map);
bool	init_exit(t_game *map);
bool	init_empty_sp(t_game *map);
bool	init_coll(t_game *map);
bool	init_player(t_game *map);
bool	init_by_null(void ***ptr, int size);
bool	init_ptrs(t_game *map);
void	init_map(t_game *map, char ***gg, int fd);

void	check_extension(char *filename);
void	check_handling_errors(int ac, char **av, t_game *map);
void	animation_bomb(t_game *map, int x, int y);
int		animation_player(t_game *param);

#endif
