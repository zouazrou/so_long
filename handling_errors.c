/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:19:38 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/17 14:25:06 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	handling_errors(t_map *map, int type, bool err)
{
	free_grid(&map->grid, map->length);
	if (err == false)
		exit (0);
	perror("Error :");
	if (type == 1)
	if (err == true)
		exit(1);
}
