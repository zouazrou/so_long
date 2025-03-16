/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:03:24 by zouazrou          #+#    #+#             */
/*   Updated: 2025/03/16 21:07:00 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animation_bomb(t_game *map, int x, int y)
{
	int		i;
	int		size;
	void	*ptr;

	size = map->enemy.nb_frm;
	i = 0;
	while (i < size)
	{
		ptr = map->enemy.img[i++];
		mlx_put_image_to_window(map->mlx, map->win, ptr, x * SIZE, y * SIZE);
		mlx_do_sync(map->mlx);
		usleep(80000);
	}
	ft_putendl_fd("+-------------------------------------------------+", 1);
	ft_putendl_fd("| Game Over! But i know you're testing my Game :) |", 1);
	ft_putendl_fd("+-------------------------------------------------+", 1);
	destroy_all(map, 0);
}

int	animation_player(t_game *param)
{
	static void	*ptr;

	if (ptr == param->player.img[0])
		ptr = param->player.img[1];
	else if (ptr == param->player.img[1])
		ptr = param->player.img[2];
	else if (ptr == param->player.img[2])
		ptr = param->player.img[3];
	else
		ptr = param->player.img[0];
	usleep(80000);
	mlx_do_sync(param->mlx);
	mlx_put_image_to_window(param->mlx, param->win, ptr,
		param->player.coord.x * SIZE, param->player.coord.y * SIZE);
	return (0);
}
