/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:48:45 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/10 14:50:56 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    show(char **grid, size_t l)
{
    for (size_t i = 0; i < l; i++)
    {
		printf("%s", grid[i]);
    }

}

void	initialization(t_map *map, int fd, int length)
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
    size_t  length;
    size_t  width;
    char    *line;
	t_map	map;

    if (ac != 2 )
        return (1);
    fd = open(av[1], O_RDWR);
    if (fd == -1)
        return (perror("Error opening file\n"), 1);
	length = ft_length(av[1]);
	if (length < 3)
		return (perror("Error : lenght of map is less then 3"), 1);
	
	map.grid = malloc((length + 1) * sizeof(char *));
	if (!map.grid)
		return (1);
	initialization(&map, fd, length);
	show(map.grid, length);
	is_valid_map(&map, length);
	// if (true == is_valid_map(&map, length))
	// 	printf("\nis valid map\n");
	// else
	// 	perror("Error : map is not valid");
	free_grid(&map.grid, length);
	return (0);
}
// gcc test.c -L./minilibx-linux -lmlx -lX11 -lXext -lm -o tes