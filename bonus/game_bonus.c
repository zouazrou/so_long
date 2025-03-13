/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:13:01 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/25 18:46:58 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mlx_put_images(t_game *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->win, map->empty.img, x
		* SIZE, y * SIZE);
	if (is_wall(map, x, y))
		mlx_put_image_to_window(map->mlx, map->win, map->wall.img, x
			* SIZE, y * SIZE);
	else if (is_player(map, x, y))
		(mlx_put_image_to_window(map->mlx, map->win, map->player.img, x
				* SIZE, y * SIZE));
	else if (is_coll(map, x, y))
		mlx_put_image_to_window(map->mlx, map->win, map->coll.img, x
			* SIZE, y * SIZE);
	else if (is_exit(map, x, y))
		mlx_put_image_to_window(map->mlx, map->win, map->exit.img, x
			* SIZE, y * SIZE);
	else if (is_enemy(map, x, y))
		mlx_put_image_to_window(map->mlx, map->win, map->enemy.img, x
			* SIZE, y * SIZE);
}

void	display_game(t_game *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->length)
	{
		x = 0;
		while (x < map->width)
			mlx_put_images(map, x++, y);
		y++;
	}
	put_moves(map);
}

int	animation(t_game *param)
{
	static void	*ptr;
	static int	frame;

	if (frame-- != 0)
		return (0);
	frame = 10000;
	if (ptr == param->player.img)
		ptr = param->frame2.img;
	else if (ptr == param->frame2.img)
		ptr = param->frame3.img;
	else if (ptr == param->frame3.img)
		ptr = param->frame4.img;
	else
		ptr = param->player.img;
	mlx_put_image_to_window(param->mlx, param->win, ptr,
		param->player.coord.x * SIZE, param->player.coord.y * SIZE);
	return (0);
}

void	game(t_game *map)
{
	if (init_img(map) == false)
		exit((destroy_all(map, PERROR), 1));
	display_game(map);
	mlx_hook(map->win, 17, 0, close_win, map);
	mlx_key_hook(map->win, keyboard, map);
	mlx_loop_hook(map->mlx, animation, map);
	mlx_loop(map->mlx);
	exit((destroy_all(map, PERROR), 1));
}
