/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:48:45 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/09 10:53:14 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void    show(char **grid, size_t l, size_t w)
{
    // for (size_t i = 0; i < l; i++)
    // {
    //     for (size_t j = 0; grid[i][j]; j++)
    //     {
    //         ft_putchar_fd(grid[i][j], 1);
    //     }
    // }

}

void	initialization(char **grid, int fd, int length)
{
	char	*line;
	size_t	width;
	size_t	x;
	size_t	y;

    if (length < 0)
        exit(1);
    grid = malloc((length + 1) * sizeof(char *));
    if (!grid)
        exit(1);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		grid[y++] = ft_strdup(line);
		safe_free(&line);
	}
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
int main(int ac, char **av)
{
    int     fd;
    size_t  length;
    size_t  width;
    char    *line;
    char    **grid;

    if (ac != 2 )
        return (1);
    // length = 0;
    // fd = open(av[1], O_RDWR);
    // if (fd == -1)
    //     return (perror("Error opening file\n"), 1);
	initialization(grid, fd, ft_length(av[1]));
    show(grid, length, width);
    return (0);
}
