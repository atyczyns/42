/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuck_the_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:16:32 by fpayen            #+#    #+#             */
/*   Updated: 2019/01/29 15:54:13 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <string.h>

void	piece_overwrite(t_piece *dst, t_piece *src)
{
	size_t	i;

	i = 0;
	while (src[i].profile)
	{
		dst[i].mask[0] = src[i].mask[0];
		dst[i].mask[1] = src[i].mask[1];
		dst[i].mask[2] = src[i].mask[2];
		dst[i].mask[3] = src[i].mask[3];
		dst[i].x = src[i].x;
		dst[i].y = src[i].y;
		dst[i].profile = src[i].profile;
		dst[i].index = src[i].index;
		dst[i].applied = src[i].applied;
		i++;
	}
}

void	mask_remove(unsigned int *square, t_piece *piece, size_t i, size_t y)
{
	size_t	j;

	j = 0;
	piece[i].applied = 0;
	while (piece[i].mask[j] && j < 4)
	{
		square[y + j] ^= piece[i].mask[j];
		j++;
	}
}
