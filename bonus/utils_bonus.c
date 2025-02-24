/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:48:52 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/24 09:32:00 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(char **grid, int x, int y)
{
	if (grid[y][x] == '1' || grid[y][x] == 'X')
		return ;
	grid[y][x] = 'X';
	flood_fill(grid, x + 1, y);
	flood_fill(grid, x - 1, y);
	flood_fill(grid, x, y + 1);
	flood_fill(grid, x, y - 1);
}

bool	check_inside_map(t_game *map, char *row, int index, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (row[i] == '1' || row[i] == '0')
			continue ;
		else if (row[i] == 'C')
			map->coll.amount++;
		else if (row[i] == 'P')
		{
			map->player.coord.x = i;
			map->player.coord.y = index;
			map->player.amount++;
		}
		else if (row[i] == 'E')
		{
			map->exit.coord.x = i;
			map->exit.coord.y = index;
			map->exit.amount++;
		}
		else
			return (false);
	}
	return (true);
}

bool	is_valid_row(t_game *map, int index, int len, bool edge_map)
{
	int		i;
	char	*row;

	i = -1;
	row = map->grid[index];
	if (row[0] != '1' || row[len - 1] != '1')
		return (false);
	if (edge_map == false)
		return (check_inside_map(map, row, index, len));
	while (++i < len)
	{
		if (row[i] != '1')
			return (false);
	}
	return (true);
}

bool	is_valid_map(t_game *map, char ***gg)
{
	int	i;

	i = -1;
	map->width = ft_strlen(map->grid[0]) - 1;
	if (map->width < 3)
		return (free_grid(gg, map->length), false);
	while (++i < map->length)
	{
		if (ft_strlen(map->grid[i]) - 1 != map->width)
			return (free_grid(gg, map->length), false);
		if (!is_valid_row(map, i, map->width, (i == 0 || i == map->length - 1)))
			return (free_grid(gg, map->length), false);
		if (map->exit.amount > 2 || map->player.amount > 2)
			return (free_grid(gg, map->length), false);
	}
	if (map->player.amount != 1 || map->exit.amount != 1
		|| map->coll.amount == 0)
		return (free_grid(gg, map->length), false);
	flood_fill(*gg, map->player.coord.x, map->player.coord.y);
	if (check_path(*gg, map->length, map->width) == false)
		return (free_grid(gg, map->length), false);
	free_grid(gg, map->length);
	return (true);
}

int	ft_length(char *file)
{
	int		fd;
	int		length;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit((perror("Error"), 1));
	length = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (close(fd), length);
		safe_free(&line);
		++length;
	}
	return (-42);
}
