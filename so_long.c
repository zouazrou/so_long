/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:48:45 by zouazrou          #+#    #+#             */
/*   Updated: 2025/03/13 12:32:47 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	map->player.img = NULL;
	map->wall.img = NULL;
	map->coll.img = NULL;
	map->empty.img = NULL;
	map->exit.img = NULL;
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
	int		fd;
	char	**gg;
	t_game	map;

	if (ac != 2)
		return (1);
	check_extension(av[1]);
	map.length = ft_length(av[1]);
	if (map.length < 3)
		return (ft_putendl_fd("Error : map is not valid", 2), EXIT_FAILURE);
	gg = malloc((map.length + 1) * sizeof(char *));
	if (!gg)
		exit((perror("Error"), 1));
	map.grid = malloc((map.length + 1) * sizeof(char *));
	if (!map.grid)
		exit((free_grid(&gg, map.length), perror("Error"), 1));
	fd = open(av[1], O_RDWR);
	if (fd == -1)
		exit((perror("Error"), 1));
	init_map(&map, &gg, fd);
	if (false == is_valid_map(&map, &gg))
		exit((ft_putendl_fd("Error : map is not valid", 2), destroy_all(&map,
					MAP), 1));
	game(&map);
	return (0);
}
