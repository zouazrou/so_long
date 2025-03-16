/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_members_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:17:58 by zouazrou          #+#    #+#             */
/*   Updated: 2025/03/16 23:14:24 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	init_coll(t_game *map)
{
	int	x;
	int	y;
	int	size;

	size = 1;
	map->coll.nb_frm = size;
	if (false == init_by_null(&map->coll.img, size))
		return (false);
	map->coll.img[0] = mlx_xpm_file_to_image(map->mlx,
			"./textures/coll.xpm", &x, &y);
	if (!map->coll.img[0])
		return (false);
	return (true);
}

bool	init_empty_sp(t_game *map)
{
	int	x;
	int	y;
	int	size;

	size = 1;
	map->empty.nb_frm = size;
	if (false == init_by_null(&map->empty.img, size))
		return (false);
	map->empty.img[0] = mlx_xpm_file_to_image(map->mlx,
			"./textures/bg.xpm", &x, &y);
	if (!map->empty.img[0])
		return (false);
	return (true);
}

void	xpm_to_imgs(t_game *map)
{
	int	x;
	int	y;

	map->enemy.img[0] = mlx_xpm_file_to_image(map->mlx,
			"./textures/L_1.xpm", &x, &y);
	map->enemy.img[1] = mlx_xpm_file_to_image(map->mlx,
			"./textures/L_2.xpm", &x, &y);
	map->enemy.img[2] = mlx_xpm_file_to_image(map->mlx,
			"./textures/L_3.xpm", &x, &y);
	map->enemy.img[3] = mlx_xpm_file_to_image(map->mlx,
			"./textures/L_4.xpm", &x, &y);
	map->enemy.img[4] = mlx_xpm_file_to_image(map->mlx,
			"./textures/L_5.xpm", &x, &y);
	map->enemy.img[5] = mlx_xpm_file_to_image(map->mlx,
			"./textures/L_6.xpm", &x, &y);
	map->enemy.img[6] = mlx_xpm_file_to_image(map->mlx,
			"./textures/L_7.xpm", &x, &y);
	map->enemy.img[7] = mlx_xpm_file_to_image(map->mlx,
			"./textures/L_8.xpm", &x, &y);
	map->enemy.img[8] = mlx_xpm_file_to_image(map->mlx,
			"./textures/L_9.xpm", &x, &y);
	map->enemy.img[9] = mlx_xpm_file_to_image(map->mlx,
			"./textures/L_10.xpm", &x, &y);
	map->enemy.img[10] = mlx_xpm_file_to_image(map->mlx,
			"./textures/L_11.xpm", &x, &y);
}

bool	init_enemy(t_game *map)
{
	int	size;

	size = 11;
	map->enemy.nb_frm = size;
	if (false == init_by_null(&map->enemy.img, size))
		return (false);
	xpm_to_imgs(map);
	if (!map->enemy.img[0] || !map->enemy.img[1] || !map->enemy.img[2]
		|| !map->enemy.img[3] || !map->enemy.img[4] || !map->enemy.img[5]
		|| !map->enemy.img[6] || !map->enemy.img[7] || !map->enemy.img[8]
		|| !map->enemy.img[9] || !map->enemy.img[10])
		return (false);
	return (true);
}

bool	init_exit(t_game *map)
{
	int	x;
	int	y;
	int	size;

	size = 1;
	map->exit.nb_frm = size;
	if (false == init_by_null(&map->exit.img, size))
		return (false);
	map->exit.img[0] = mlx_xpm_file_to_image(map->mlx,
			"./textures/exit.xpm", &x, &y);
	if (!map->exit.img[0])
		return (false);
	return (true);
}
