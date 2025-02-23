/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:19:38 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/23 15:19:28 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	destroy_all(t_game *map, int err)
{
	if (map->wall.img)
		mlx_destroy_image(map->mlx, map->wall.img);
	if (map->player.img)
		mlx_destroy_image(map->mlx, map->player.img);
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
