/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:48:49 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/19 16:15:51 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h> // remove when finish

#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <errno.h>

#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

typedef	struct s_coord
{
	int	x;
	int	y;
}		t_coord;

typedef struct s_info
{
	void	*img;
	t_coord	coord;
	int		amount;
}			t_info;

typedef struct s_game
{
    char    **grid;
    int     length;
    int     width;
	void	*mlx;
	void	*win;
	int		moves;
	t_info	wall;
	t_info	player;
	t_info	exit;
	t_info	empty;
	t_info	coll;
}               t_game;

#define SIZE 64

//
bool	is_exit(t_game *map, int x, int y);
bool	is_empty_sp(t_game *map, int x, int y);
bool	is_wall(t_game *map, int x, int y);
bool	is_coll(t_game *map, int x, int y);
bool	is_player(t_game *map, int x, int y);

//
bool	isvalidsize(char **grid, int length);
bool	is_valid_map(t_game *map);
void	safe_free(char **ptr);
int		keyboard(int keysym, t_game *map);
void	free_grid(char ***grid, int length);
void	destroy_all(t_game *map, bool err);
// game...
bool	game(t_game *map);

//
void	do_op(t_game *map, char direction);

#endif
