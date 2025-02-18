/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:13:01 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/18 15:02:33 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


bool	is_wall(t_game *map, int x, int y)
{
	return (map->grid[y][x] == '1');
}

bool	is_player(t_game *map, int x, int y)
{
	return (map->grid[y][x] == 'P');
}

bool	is_coll(t_game *map, int x, int y)
{
	return (map->grid[y][x] == 'C');
}

bool	is_exit(t_game *map, int x, int y)
{
	return (map->grid[y][x] == 'E');
}

bool	is_empty_sp(t_game *map, int x, int y)
{
	return (map->grid[y][x] == '0');
}

int	keyboard(int keysym, t_game *map)
{
	static int	moves;

	ft_putnbr_fd(++moves, 1);
	ft_putendl_fd("", 1);
	if (keysym == XK_Escape)
		destroy_all(map, false);
	return (0);
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
		{
			if (is_wall(map, x, y))
				mlx_put_image_to_window(map->mlx, map->win, map->wall.img, x * SIZE, y * SIZE);
			else if (is_player(map, x, y))
				mlx_put_image_to_window(map->mlx, map->win, map->player.img, x * SIZE, y * SIZE);
			else if (is_coll(map, x, y))
				mlx_put_image_to_window(map->mlx, map->win, map->coll.img, x * SIZE, y * SIZE);
			else if (is_exit(map, x, y))
				mlx_put_image_to_window(map->mlx, map->win, map->exit.img, x * SIZE, y * SIZE);
			else if (is_empty_sp(map, x, y))
				mlx_put_image_to_window(map->mlx, map->win, map->empty.img, x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
}

bool	game(t_game *map)
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
		free(map->mlx);
		return (false);
	}
	map->wall.img = mlx_new_image(map->mlx, SIZE, SIZE);
	if (!map->wall.img)
		return (false);
	map->coll.img = mlx_new_image(map->mlx, SIZE, SIZE);
	if (!map->coll.img)
		return (false);
	map->player.img = mlx_new_image(map->mlx, SIZE, SIZE);
	if (!map->player.img)
		return (false);
	map->empty.img = mlx_new_image(map->mlx, SIZE, SIZE);
	if (!map->empty.img)
		return (false);
	map->exit.img = mlx_new_image(map->mlx, SIZE, SIZE);
	if (!map->exit.img)
		return (false);
	map->wall.img = mlx_xpm_file_to_image(map->mlx, "./textures/wall.xpm", &x, &y);
	map->coll.img = mlx_xpm_file_to_image(map->mlx, "./textures/coll.xpm", &x, &y);
	map->player.img = mlx_xpm_file_to_image(map->mlx, "./textures/player.xpm", &x, &y);
	map->empty.img = mlx_xpm_file_to_image(map->mlx, "./textures/Brown.xpm", &x, &y);
	map->exit.img = mlx_xpm_file_to_image(map->mlx, "./textures/exit.xpm", &x, &y);
	display_game(map);
	mlx_key_hook(map->win, keyboard, map);
	mlx_loop(map->mlx);
	return (true);
}
