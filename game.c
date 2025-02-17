/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:13:01 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/17 17:28:17 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_all(t_map *param)
{
	mlx_destroy_display(param->mlx);
	mlx_destroy_window(param->mlx, param->win);
	free(param->background.img_ptr);
	free(param->player.img_ptr);
	free(param->wall.img_ptr);
	free(param->collectible.img_ptr);
	free(param->exit.img_ptr);
	free(param->mlx);
}
int	handling_input(int keysym, t_map *param)
{
	if (keysym == XK_Escape)
	{
		destroy_all(param);
	}
	else
		printf("keysym :%d\n", keysym);
	return (42);
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
	map->wall.img_ptr = mlx_xpm_file_to_image(map->mlx, "->/textures/wall->xpm", &x, &y);
	map->collectible.img_ptr = mlx_xpm_file_to_image(map->mlx, "->/textures/coll->xpm", &x, &y);
	map->player.img_ptr = mlx_xpm_file_to_image(map->mlx, "->/textures/player->xpm", &x, &y);
	map->background.img_ptr = mlx_xpm_file_to_image(map->mlx, "->/textures/Brown->xpm", &x, &y);
	map->exit.img_ptr = mlx_xpm_file_to_image(map->mlx, "->/textures/exit->xpm", &x, &y);
	display_game(map);
	mlx_key_hook(map->win, handling_input, map);
	mlx_loop(map->mlx);
	return (true);
}
