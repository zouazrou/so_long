/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:48:40 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/25 16:06:31 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_win(t_game *map)
{
	destroy_all(map, 0);
	return (0);
}

bool	init_img_2(t_game *map)
{
	int	x;
	int	y;

	map->wall.img = mlx_xpm_file_to_image(map->mlx, "./textures/wall.xpm", &x,
			&y);
	if (!map->wall.img)
		return (false);
	map->coll.img = mlx_xpm_file_to_image(map->mlx, "./textures/coll.xpm", &x,
			&y);
	if (!map->coll.img)
		return (false);
	map->empty.img = mlx_xpm_file_to_image(map->mlx, "./textures/bg.xpm", &x,
			&y);
	if (!map->empty.img)
		return (false);
	map->exit.img = mlx_xpm_file_to_image(map->mlx, "./textures/exit.xpm", &x,
			&y);
	if (!map->exit.img)
		return (false);
	map->enemy.img = mlx_xpm_file_to_image(map->mlx, "./textures/L_1.xpm", &x,
			&y);
	if (!map->enemy.img)
		return (false);
	return (true);
}

bool	init_img(t_game *map)
{
	int	x;
	int	y;

	map->mlx = mlx_init();
	if (!map->mlx)
		return (false);
	map->win = mlx_new_window(map->mlx, map->width * SIZE, map->length * SIZE,
			"so_long");
	if (!map->win)
		return (false);
	map->player.img = mlx_xpm_file_to_image(map->mlx, "./textures/player.xpm",
			&x, &y);
	map->frame2.img = mlx_xpm_file_to_image(map->mlx, "./textures/frame22.xpm",
			&x, &y);
	map->frame3.img = mlx_xpm_file_to_image(map->mlx, "./textures/frame33.xpm",
			&x, &y);
	map->frame4.img = mlx_xpm_file_to_image(map->mlx, "./textures/frame44.xpm",
			&x, &y);
	if (!map->player.img || !map->frame2.img
		|| !map->frame3.img || !map->frame4.img)
		return (false);
	return (init_img_2(map));
}
