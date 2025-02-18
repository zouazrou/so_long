/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:19:38 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/18 15:04:01 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	destroy_all(t_game *map, bool err)
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
	free_grid(&map->grid, map->length);
	if (err == true)
		exit (1);
	exit(0);
}

// void	handling_errors(t_game *map, int type, bool err)
// {
// 	free_grid(&map->grid, map->length);
// 	if (err == false)
// 		exit (0);
// 	perror("Error :");
// 	if (type == 1)
// 	if (err == true)
// 		exit(1);
// }
