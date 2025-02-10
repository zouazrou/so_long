/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:48:45 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/10 12:12:37 by zouazrou         ###   ########.fr       */
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

void	initialization(char **grid, int fd, int length)
{
	char	*line;
	size_t	width;
	size_t	x;
	size_t	y;

	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		grid[y++] = line;
	}
	grid[y] = NULL;
	close(fd);
}

int     ft_length(char *file)
{
    int     fd;
    int     length;
    char    *line;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (-1);
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
    char    **grid;

    if (ac != 2 )
        return (1);
    length = 0;
    fd = open(av[1], O_RDWR);
    if (fd == -1)
        return (perror("Error opening file\n"), 1);
	length = ft_length(av[1]);
	grid = malloc((length + 1) * sizeof(char *));
	if (!grid)
		return (1);
	initialization(grid, fd, length);
	if (true == isvalidsize(grid, length))
		printf("is valid map\n");
	else
		perror("Error : map is not valid\n");
    show(grid, length);
	free_grid(&grid, length);
    return (0);
}
