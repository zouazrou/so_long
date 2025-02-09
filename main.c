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

void    print(char **grid, size_t l, size_t w)
{
    for (size_t i = 0; i < l; i++)
    {
        for (size_t j = 0; grid[i][j]; j++)
        {
            ft_putchar_fd(grid[i][j], 1);
        }
        ft_putendl_fd(0, 1);
    }

}

void	initialization(char **grid, int fd)
{
	char	*line;
	size_t	width;
	size_t	length;
	size_t	x;
	size_t	y;

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
	initialization(grid, fd);
    print(grid, length, width);
    return (0);
}
