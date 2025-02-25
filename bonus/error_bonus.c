/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:19:38 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/25 16:00:27 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	check_path(char **grid, int l, int w)
{
	int	y;
	int	x;

	y = 0;
	while (y < l)
	{
		x = 0;
		while (x < w)
		{
			if (grid[y][x] == 'E' || grid[y][x] == 'C')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

void	destroy_frames(t_game *map)
{
	if (map->player.img)
		mlx_destroy_image(map->mlx, map->player.img);
	if (map->frame2.img)
		mlx_destroy_image(map->mlx, map->frame2.img);
	if (map->frame3.img)
		mlx_destroy_image(map->mlx, map->frame3.img);
	if (map->frame4.img)
		mlx_destroy_image(map->mlx, map->frame4.img);
}

void	destroy_all(t_game *map, int err)
{
	destroy_frames(map);
	if (map->wall.img)
		mlx_destroy_image(map->mlx, map->wall.img);
	if (map->enemy.img)
		mlx_destroy_image(map->mlx, map->enemy.img);
	if (map->coll.img)
		mlx_destroy_image(map->mlx, map->coll.img);
	if (map->exit.img)
		mlx_destroy_image(map->mlx, map->exit.img);
	if (map->empty.img)
		mlx_destroy_image(map->mlx, map->empty.img);
	if (map->win)
		mlx_destroy_window(map->mlx, map->win);
	if (map->mlx)
	{
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	if (map->grid)
		free_grid(&map->grid, map->length);
	if (err == PERROR)
		exit ((perror("Error "), EXIT_FAILURE));
	if (err == MAP)
		exit (EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void	free_grid(char ***grid, int length)
{
	int	i;

	i = length;
	while (i >= 0)
		safe_free(&(*grid)[i--]);
	free(*grid);
	*grid = NULL;
}
