#include "get_next_line.h"

size_t  ft_lenchr(const char *s, char c)
{
    size_t  len;

    len = 0;
    while (s[len++] != c && s[len])
        ;
    return (len);
}
int is_has_newline(const char *s)
{
    while (*s)
    {
        if (*s++ == '\n')
            return (1);
    }
    return (0);
}

int    cut_store(char **buffer, char **stock, char **line)
{
    size_t  i;
    size_t  j;

    *line = malloc(ft_lenchr(*buffer, '\n') + 1);
    if (!*line)
        return (-1);
    i = 0;
    while ((*buffer)[i])
    {
        (*line)[i] = (*buffer)[i];
        if ((*buffer)[i++] == '\n')
            break;
    }
    (*line)[i] = 0;
    *stock = malloc(ft_strlen(*buffer + i) + 1);
    if (!*stock)
        return (-1);
    j = 0;
    while ((*buffer)[i])
        (*stock)[j++] = (*buffer)[i++];
    (*stock)[j] = 0;
    free(*buffer);
    return (1);
}

int    management_buffers(char **buffer, char **stock, int fd)
{
    char    *temp;
    int     bytes;

    temp = malloc(BUFFER_SIZE + 1);
    if (!temp)
        return (-1);
    bytes = read(fd, temp, BUFFER_SIZE);
    if (!bytes)
    {
        *buffer = ft_strdup(*stock);
        free(*stock);
        *stock = NULL;
        free(temp);
        return (bytes);
    }
    temp[bytes] = '\0';
    // stock empty
    if (!*stock)
        *buffer = ft_strdup(temp);
    // stock not empty
    else
    {
        *buffer = ft_strjoin(*stock, temp);
        free(*stock);
        *stock = NULL;
    }
    free(temp);
    return (bytes);
}

char    *get_next_line(int fd)
{
    static char *stock;
    char        *buffer;
    char        *line;
    int         bytes;

    // STEP (1) reding from fd to "buffer" and combine it
    // with a "stock" if not empty ,after this step 
    // "stock" will be has 'NULL'
    bytes = management_buffers(&buffer, &stock, fd);
    if (!bytes)
    {
        if (cut_store(&buffer, &stock, &line) == -1)
            return (NULL);
        return (line);
    }
    // STEP (2)
    // is no
    if (!is_has_newline(buffer))
    {
        stock = ft_strdup(buffer);
        free(buffer);
        return (get_next_line(fd));
    }
    else
    {
        if (cut_store(&buffer, &stock, &line) == -1)
            return (NULL);
    }
    return (line);
}


