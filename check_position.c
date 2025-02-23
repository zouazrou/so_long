/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:44:12 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/23 14:44:50 by zouazrou         ###   ########.fr       */
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
