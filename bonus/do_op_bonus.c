/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:15:43 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/24 14:39:18 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_moves(t_game *map)
{
	char *nbr;

	mlx_put_image_to_window(map->mlx, map->win, map->wall.img, 0
		* SIZE, 0 * SIZE);
	mlx_put_image_to_window(map->mlx, map->win, map->wall.img, 1
		* SIZE, 0 * SIZE);
	mlx_put_image_to_window(map->mlx, map->win, map->wall.img, 2
		* SIZE, 0 * SIZE);
	mlx_put_image_to_window(map->mlx, map->win, map->wall.img, 3
		* SIZE, 0 * SIZE);
	if (map->moves != INT_MAX)
		nbr = ft_itoa(map->moves++);
	mlx_string_put(map->mlx, map->win, 0.1 * SIZE, 0.5 * SIZE, 0xffffff, "moves : ");
	mlx_string_put(map->mlx, map->win, 1.5 * SIZE, 0.5 * SIZE, 0xffffff, nbr);
	safe_free(&nbr);
}

void	do_move(t_game *map, t_coord curr, t_coord new)
{
	put_moves(map);
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
