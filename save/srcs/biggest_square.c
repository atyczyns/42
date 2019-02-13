/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:08:04 by fpayen            #+#    #+#             */
/*   Updated: 2019/01/29 15:50:59 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/includes/libft.h"
#include <string.h>

/*
** place_pieces inserts the pieces into a bitmap of the square with no
** optimisation in order to find the largest possible square to be able to hold
** every piece.
*/

static void		place_pieces(unsigned int *square, t_piece *pieces,
		size_t size)
{
	int		check;
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (pieces[i].profile)
	{
		if ((check = room_check(square, pieces[i], y, size)) == -1
				|| (check == -2 && !pieces[i].x))
		{
			size++;
			y = 0;
		}
		else if (check == -2 && pieces[i].x)
			mask_reset(pieces, i, &y);
		else if (!check)
			mask_shift_right(pieces, i);
		else
		{
			mask_apply(square, pieces, i, y);
			i++;
		}
	}
}

/*
** biggest_square finds one size for the square that will serve as the cap and
** returns a bitmaskof its findings.
*/

unsigned int	*biggest_square(t_piece *pieces, size_t nb_pieces)
{
	unsigned int	*square;
	size_t			size;

	if (!(square = (unsigned int *)ft_memalloc(sizeof(int) * 14)))
		return (NULL);
	size = 2;
	nb_pieces *= 4;
	while (size * size < nb_pieces)
		size++;
	place_pieces(square, pieces, size);
	return (square);
}
