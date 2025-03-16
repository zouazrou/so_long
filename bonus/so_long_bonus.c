/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:48:45 by zouazrou          #+#    #+#             */
/*   Updated: 2025/03/16 18:10:33 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	is_enemy(t_game *map, int x, int y)
{
	return (map->grid[y][x] == 'N');
}

void	check_extension(char *filename)
{
	char	*extension;
	int		idx_ext;
	int		idx_fnm;

	extension = ".ber";
	idx_ext = 4;
	idx_fnm = ft_strlen(filename);
	while (idx_ext && idx_fnm)
	{
		if (filename[--idx_fnm] != extension[--idx_ext])
			exit((ft_putendl_fd("Error : File name must end with '.ber'", 2),
					1));
	}
	if (idx_ext == 0 && idx_fnm != 0 && filename[--idx_fnm] != '/')
		return ;
	exit((ft_putendl_fd("Error : File name must end with '.ber'", 2), 1));
}

void	init_fields(t_game *map)
{
	map->moves = 0;
	map->player.amount = 0;
	map->coll.amount = 0;
	map->exit.amount = 0;
	map->mlx = NULL;
	map->win = NULL;
}

void	init_map(t_game *map, char ***gg, int fd)
{
	char	*line;
	int		y;

	init_fields(map);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		(*gg)[y] = ft_strdup(line);
		map->grid[y++] = line;
	}
	(*gg)[y] = NULL;
	map->grid[y] = NULL;
	close(fd);
}

int	main(int ac, char **av)
{
	t_game	map;

	check_handling_errors(ac, av, &map);
	game(&map);
	return (0);
}
