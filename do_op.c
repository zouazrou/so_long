/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:15:43 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/18 15:11:07 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
-->achno dart db :
	adding another member inside my struct "on exit"
-->achno khasni ndir db :
	you must be handling if new coord is wall or empty sp or coll or exit ...

*/
void	up(t_game *map)
{
	t_coord	new_crd;

	new_crd = map->player.coord;
	new_crd.y++;
	if (is_coll(map, new_crd.x, new_crd.y))
		map->coll.amount--;
	else if (is_exit(map, new_crd.x, new_crd.y))
	
}
void	do_op(t_game *map, char direction)
{
	if (direction == 'u')
		up(map);
	// else if (direction == 'u')
	// else if (direction == 'u')
	// else if (direction == 'u')
	// else
}
