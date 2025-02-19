/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:48:52 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/19 16:15:35 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool is_valid_row(t_game *map, int index, int len, bool edge_map)
{
	int	i;
	char	*row;

	i = -1;
	row = map->grid[index];
	while (edge_map == true && ++i < len)
	{
		if (row[i] != '1')
			return (false);
	}
	if (row[0] != '1' || row[len-1] != '1')
		return (false);
	while (edge_map == false && ++i < len)
	{
		if (row[i] == '1' || row[i] == '0')
			continue;
		else if (row[i] == 'P')
			(map->player.coord.x = i), (map->player.coord.y = index), (map->player.amount++);
		else if (row[i] == 'E')
			(map->exit.coord.x = i), (map->exit.coord.y = index), (map->exit.amount++);
		else if (row[i] == 'C')
			map->coll.amount++;
		else
			return (false);
	}
	return (true);
}

bool	is_valid_map(t_game *map)
{
	int	i;

	i = -1;
	map->width = ft_strlen(map->grid[0]) - 1;
	if (map->width < 3)
		return (false);
	while (++i < map->length)
	{
		if (ft_strlen(map->grid[i]) - 1 != map->width)
			return (false);
		if (!is_valid_row(map, i, map->width, (i == 0 || i == map->length - 1)))
			return (false);
		if (map->exit.amount > 2 || map->player.amount > 2)
			return (false);
	}
	if (map->player.amount != 1 || map->exit.amount != 1 || map->coll.amount == 0)
		return (false);
	return (true);
}
