/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:48:45 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/21 21:12:33 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    show(t_game *map)
{
    for (size_t i = 0; i < map->length; i++)
    {
		// ft_putnbr_fd, 	1);
		ft_putendl_fd(map->grid[i], 1);
    }
	ft_putnbr_fd(map->length, 1);
	ft_putendl_fd("", 1);
	ft_putnbr_fd(map->width, 1);
	ft_putendl_fd("", 1);
}

bool	check_extension(char *filename)
{
	char	*extension;
	int		len;
	int		i;
	int		j;

	extension = ".ber";
	i = 0;
	j = ft_strlen(filename) - 4;
	if (j <= 0)
		return (false);
	while (filename[j] && extension[i])
	{
		if (filename[j] != extension[i])
			return (false);
		j++;
		i++;
	}
	if (filename[j])
		return (false);
	return (true);
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
	char	**grid;
	int		width;
	int		y;

	init_fields(map);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		(*gg)[y] = ft_strdup(line);
		map->grid[y++] = line;
	}
	(*gg)[y] = NULL;	
	map->grid[y] = NULL;
	close(fd);
}

int main(int ac, char **av)
{
    int     fd;
	char	**gg;
	t_game	map;

    if (ac != 2 )
		return (1);
	if (check_extension(av[1]) == false)
		exit ((perror("Error : name of file must be ending by '.ber'"), 1));
	fd = open(av[1], O_RDWR);
	if (fd == -1)
		return (perror("Error"), 1);
	map.length = ft_length(av[1]);
	if (map.length < 3)
		return (close(fd), perror("Error : lenght of map is less then 3"), 1);
	gg = malloc((map.length + 1) * sizeof(char *));
	if (!gg)
		return (close(fd), 1);
	map.grid = malloc((map.length + 1) * sizeof(char *));
	if (!map.grid)
		return (free_grid(&gg, map.length), close(fd), 1);
	init_map(&map, &gg, fd);
	if (false == is_valid_map(&map, &gg))
		exit ((ft_putendl_fd("Error : map is not valid", 2), 1));
	free_grid(&gg, map.length);
	if (game(&map) == false)
		exit((destroy_all(&map, true),perror("Error : "), 1));
	return (0);
}
