/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:13:01 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/17 17:55:53 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_all(t_map *map)
{
	mlx_destroy_display(map->mlx);
	mlx_destroy_window(map->mlx, map->win);
	// mlx_destroy_image(map->mlx, map->img.img_ptr);
	free(map->wall.img_ptr);
	free(map->player.img_ptr);
	free(map->collectible.img_ptr);
	free(map->exit.img_ptr);
	free(map->background.img_ptr);
	exit ((free(map->mlx), 1));
}
int	keyboard(int keysym, t_map *map)
{
	static int	moves;

	printf("%d\n", ++moves);
	if (keysym == XK_Escape)
		destroy_all(map);
	// else if (keysym == XK_w)
	// 	do_op(map, 'w');
	// else if (keysym == XK_a)
	// 	do_op(map, 'a');
	// else if (keysym == XK_s)
	// 	do_op(map, 's');
	// else if (keysym == XK_d)
	// 	do_op(map, 'd');
	// else
	// 	printf("keysym : %d\n", keysym);
	return (0);
}
void	display_game(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->length)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == '1')
				mlx_put_image_to_window(map->mlx, map->win, map->wall.img_ptr, x * SIZE, y * SIZE);
			else if (map->grid[y][x] == 'P')
				mlx_put_image_to_window(map->mlx, map->win, map->player.img_ptr, x * SIZE, y * SIZE);
			else if (map->grid[y][x] == 'C')
				mlx_put_image_to_window(map->mlx, map->win, map->collectible.img_ptr, x * SIZE, y * SIZE);
			else if (map->grid[y][x] == 'E')
				mlx_put_image_to_window(map->mlx, map->win, map->exit.img_ptr, x * SIZE, y * SIZE);
			else if (map->grid[y][x] == '0')
				mlx_put_image_to_window(map->mlx, map->win, map->background.img_ptr, x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
}

bool	game(t_map *map)
{
	int		x;
	int		y;

	map->mlx = mlx_init();
	if (!map->mlx)
		return (false);
	map->win = mlx_new_window(map->mlx, map->width * SIZE, map->length * SIZE, "so_long");
	if (!map->win)
	{
		mlx_destroy_display(map->mlx);
		return (false);
	}
	map->wall.img_ptr = mlx_new_image(map->mlx, SIZE, SIZE);
	if (!map->wall.img_ptr)
		return (false);
	map->collectible.img_ptr = mlx_new_image(map->mlx, SIZE, SIZE);
	if (!map->collectible.img_ptr)
		return (false);
	map->player.img_ptr = mlx_new_image(map->mlx, SIZE, SIZE);
	if (!map->player.img_ptr)
		return (false);
	map->background.img_ptr = mlx_new_image(map->mlx, SIZE, SIZE);
	if (!map->background.img_ptr)
		return (false);
	map->exit.img_ptr = mlx_new_image(map->mlx, SIZE, SIZE);
	if (!map->exit.img_ptr)
		return (false);
	map->wall.img_ptr = mlx_xpm_file_to_image(map->mlx, "./textures/wall.xpm", &x, &y);
	map->collectible.img_ptr = mlx_xpm_file_to_image(map->mlx, "./textures/coll.xpm", &x, &y);
	map->player.img_ptr = mlx_xpm_file_to_image(map->mlx, "./textures/player.xpm", &x, &y);
	map->background.img_ptr = mlx_xpm_file_to_image(map->mlx, "./textures/Brown.xpm", &x, &y);
	map->exit.img_ptr = mlx_xpm_file_to_image(map->mlx, "./textures/exit.xpm", &x, &y);
	display_game(map);
	mlx_key_hook(map->win, keyboard, map);
	mlx_loop(map->mlx);
	return (true);
}
