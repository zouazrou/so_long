/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:48:49 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/17 17:23:00 by zouazrou         ###   ########.fr       */
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

#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"

typedef struct s_img
{
	void	*img_ptr;
}			t_img;

typedef struct s_map
{
    char    **grid;
    int     length;
    int     width;
    int     p;
    int     c;
    int     e;
	void	*mlx;
	void	*win;
	t_img	wall;
	t_img	player;
	t_img	exit;
	t_img	background;
	t_img	collectible;
}               t_map;

#define SIZE 64

bool	isvalidsize(char **grid, int length);
bool	is_valid_map(t_map *map);
void	safe_free(char **ptr);

// game...
bool	game(t_map *map);

#endif
