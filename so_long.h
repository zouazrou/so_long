/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:48:49 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/10 12:11:18 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h> // remove when finish

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <errno.h>

#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"

typedef struct s_map
{
    char    **grid;
    int     length;
    int     width;
    int     p;
    int     c;
    int     e;
}               t_map;

bool	isvalidsize(char **grid, int length);
bool	is_valid_map(t_map *map, int length);
void	safe_free(char **ptr);

#endif
