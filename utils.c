/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:48:52 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/10 14:48:31 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
bool is_valid_wall(char *row, int len, bool edge_map)
{
	int	i;

	if (edge_map == false && row[0] == '1' && row[len-1] == '1')
		return (true);
	else if (edge_map == false)
		return (false);
	i = 0;
	while (i < len)
	{
		if (row[i++] != '1')
			return (false);
	}
	return (true);
}
bool	isvalidsize(char **grid, int length)
{
	int	i;
	int	width;

	width = ft_strlen(grid[0]);
	if (width < 4)
		return (false);
	i = 0;
	while (i < length)
	{
		if (ft_strlen(grid[i]) != width || !is_valid_wall(grid[i], width - 1, (i == 0 || i == length - 1)))
			return (false);
		++i;
	}
	return (true);
}
