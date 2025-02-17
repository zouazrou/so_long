/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:48:45 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/17 16:26:04 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    show(t_map *map)
{
    for (size_t i = 0; i < map->length; i++)
    {
		printf("%s", map->grid[i]);
    }
	printf("l = %d | w = %d\n", map->length, map->width);
}
// "map.ter" 7 - 4
// 3
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
void	initialization(t_map *map, int fd)
{
	char	*line;
	int		width;
	int		y;

	y = 0;
	map->e = 0;
	map->c = 0;
	map->p = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		map->grid[y++] = line;
	}
	map->grid[y] = NULL;
	close(fd);
}

int     ft_length(char *file)
{
    int     fd;
    int     length;
    char    *line;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        exit ((close(fd), perror("Error : something wrong in function open"), 1));
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

void	free_grid(char ***grid, int length)
{
	for (int i = length; i >= 0; i--)
		safe_free(&(*grid)[i]);
	free(*grid);
	*grid = NULL;
}

int main(int ac, char **av)
{
    int     fd;
	t_map	map;

    if (ac != 2 )
        return (1);
	if (check_extension(av[1]) == false)
		exit ((perror("Error : name of file must be ending by '.ber'"), 1));
    fd = open(av[1], O_RDWR);
    if (fd == -1)
        return (perror("Error"), 1);
	map.length = ft_length(av[1]);
	if (map.length < 3)
		return (perror("Error : lenght of map is less then 3"), 1);
	map.grid = malloc((map.length + 1) * sizeof(char *));
	if (!map.grid)
		return (1);
	initialization(&map, fd);
	if (true == is_valid_map(&map))
		printf("\nis valid map\n");
	else
		perror("Error : map is not valid\n");
	show(&map);
	game(&map);
	free_grid(&map.grid, map.length);
	return (0);
}

// gcc test.c -L./minilibx-linux -lmlx -lX11 -lXext -lm -o tes
