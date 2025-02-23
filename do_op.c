/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:15:43 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/23 15:18:54 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_move(t_game *map, t_coord curr, t_coord new)
{
	ft_putnbr_fd(++map->moves, 1);
	ft_putchar_fd('\n', 1);
	mlx_put_image_to_window(map->mlx, map->win, map->player.img, new.x * SIZE,
		new.y * SIZE);
	map->grid[new.y][new.x] = 'P';
	if (map->player.coord.x == map->exit.coord.x
		&& map->player.coord.y == map->exit.coord.y)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->exit.img, curr.x
			* SIZE, curr.y * SIZE);
		map->grid[curr.y][curr.x] = 'E';
		map->player.coord = new;
		return ;
	}
	mlx_put_image_to_window(map->mlx, map->win, map->empty.img, curr.x * SIZE,
		curr.y * SIZE);
	map->grid[curr.y][curr.x] = '0';
	map->player.coord = new;
}

void	move(t_game *map, t_coord new)
{
	t_coord	curr;

	curr = map->player.coord;
	if (is_coll(map, new.x, new.y))
	{
		map->coll.amount--;
		do_move(map, curr, new);
	}
	else if (is_empty_sp(map, new.x, new.y))
	{
		do_move(map, curr, new);
	}
	else if (is_exit(map, new.x, new.y))
	{
		if (!map->coll.amount)
		{
			ft_putstr_fd("Gg!\n", 1);
			destroy_all(map, 0);
		}
		do_move(map, curr, new);
	}
}

void	do_op(t_game *map, char direction)
{
	t_coord	new;

	new = map->player.coord;
	if (direction == 'u')
		new.y--;
	else if (direction == 'd')
		new.y++;
	else if (direction == 'r')
		new.x++;
	else if (direction == 'l')
		new.x--;
	move(map, new);
}

int	keyboard(int keysym, t_game *map)
{
	static int	moves;

	if (keysym == XK_Escape)
		destroy_all(map, false);
	else if (keysym == XK_Up || keysym == XK_w)
		do_op(map, 'u');
	else if (keysym == XK_Down || keysym == XK_s)
		do_op(map, 'd');
	else if (keysym == XK_Right || keysym == XK_d)
		do_op(map, 'r');
	else if (keysym == XK_Left || keysym == XK_a)
		do_op(map, 'l');
	return (0);
}
