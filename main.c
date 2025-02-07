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
        perror("Error opening file\n");
    width = ft_strlen(line);
    line = get_next_line(fd);
    while (line)
    {
        grid[length++] = line;
        line = get_next_line(fd);
    }
    print(grid, length, width);    
    return (0);
}