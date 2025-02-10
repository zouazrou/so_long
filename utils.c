/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:48:52 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/10 12:22:17 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
bool check_wall(char *row, int len, bool edge_map)
{
	if (edge_map == true && row[0] == '1' && row[len-1] == '1')
		return (true);


}
bool	isvalidsize(char **grid, int length)
{
	int	i;
	int	width;

	width = ft_strlen(grid[0]);
	i = 1;
	while (i < length)
	{
		if (ft_strlen(grid[i]) != width || check_wall(grid[i], width - 1, (i != 0 && i != length - 1)))
			return (false);
		++i;
	}
	return (true);
}
