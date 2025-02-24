/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:13:01 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/24 14:36:56 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	map->player.img = mlx_xpm_file_to_image(map->mlx, "./textures/player.xpm", &x,
			&y);
	map->frame2.img = mlx_xpm_file_to_image(map->mlx, "./textures/frame22.xpm", &x,
			&y);
	map->frame3.img = mlx_xpm_file_to_image(map->mlx, "./textures/frame33.xpm", &x,
		   &y);
	map->frame4.img = mlx_xpm_file_to_image(map->mlx, "./textures/frame44.xpm", &x,
		   &y);
	if (!map->player.img || !map->frame2.img || !map->frame3.img || !map->frame4.img)
		return (false);
	return (init_img_2(map));
}

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
	static	void	*ptr;
	static	int		frame;

	if (frame-- != 0)
		return (0);
	frame = 3000;
	if (ptr == param->player.img)
	ptr = param->frame2.img;
	else if (ptr == param->frame2.img)
	ptr = param->frame3.img;
	else if (ptr == param->frame3.img)
		ptr = param->frame4.img;
	else
		ptr = param->player.img;
	mlx_put_image_to_window(param->mlx, param->win, ptr, param->player.coord.x * SIZE, param->player.coord.y * SIZE);
	return (0);
}
// 8C92AC
void	game(t_game *map)
{
	if (init_img(map) == false)
		exit((destroy_all(map, PERROR), 1));
	display_game(map);
	mlx_key_hook(map->win, keyboard, map);
	mlx_loop_hook(map->mlx, animation, map);
	mlx_loop(map->mlx);
	exit((destroy_all(map, PERROR), 1));
}
