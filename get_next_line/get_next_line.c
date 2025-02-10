/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:33:08 by zouazrou          #+#    #+#             */
/*   Updated: 2024/11/29 18:57:01 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	it_contains_newline(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i++] == '\n')
			return (i);
	}
	return (0);
}

char	*cut_store(char **buffer, char **stock)
{
	char	*temp;
	char	*newline;
	int		len;
	int		j;

	temp = ft_strchr(*buffer, '\n');
	temp++;
	len = temp - (*buffer);
	if (*temp != '\0')
		*stock = ft_strdup(temp);
	newline = malloc(len + 1);
	if (!newline)
		return (NULL);
	j = 0;
	while (j < len)
	{
		newline[j] = (*buffer)[j];
		j++;
	}
	newline[j] = '\0';
	safe_free(buffer);
	return (newline);
}

void	norm(ssize_t *bytes, char *temp, int *eof)
{
	if (*bytes <= 0)
	{
		*eof = 1;
		safe_free(&temp);
	}
	else
		temp[*bytes] = '\0';
}

char	*management_buffers(char **stock, int fd, int *eof)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes;

	buffer = NULL;
	temp = malloc(BUFFER_SIZE + 1);
	if (temp == NULL)
		return (NULL);
	bytes = read(fd, temp, BUFFER_SIZE);
	norm(&bytes, temp, eof);
	if (bytes == -1)
		return (NULL);
	else if ((*stock) && *eof == 0)
		buffer = ft_strjoin((*stock), temp);
	else if ((*stock) && *eof == 1)
		buffer = ft_strdup((*stock));
	else if (!(*stock) && *eof == 0)
		buffer = ft_strdup(temp);
	else
		return (NULL);
	if (*eof == 0)
		safe_free(&temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*buffer;
	int			eof;

	if (!BUFFER_SIZE)
		return (0);
	eof = 0;
	buffer = management_buffers(&stock, fd, &eof);
	if (stock)
		safe_free(&stock);
	if (!buffer)
		return (NULL);
	if (!it_contains_newline(buffer))
	{
		if (eof)
			return (buffer);
		stock = ft_strdup(buffer);
		safe_free(&buffer);
		return (get_next_line(fd));
	}
	return (cut_store(&buffer, &stock));
}

// int main()
// {
// 	char	*line;
// 	int fd = open("file.txt", O_RDWR);
// 	int fdd = open("f.txt", O_RDWR);

// 	while (line = get_next_line(fd))
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fdd);
// 		printf("%s", line);
// 		free(line);
// 	}
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	return (0);
// }
