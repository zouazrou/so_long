/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:48:52 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/09 10:52:33 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"

void	safe_free(char **ptr)
{
	if (!ptr || !*ptr)
	 	return ;
	free(*ptr);
	*ptr = NULL;
}
