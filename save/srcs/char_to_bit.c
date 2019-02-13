/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:36:12 by fpayen            #+#    #+#             */
/*   Updated: 2019/01/29 15:53:26 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <string.h>

/*
** profile_save saves the bitmask of a given piece from four integers to a
** single one, spread across each byte.
*/

static unsigned int	profile_save(t_piece *pieces, size_t i)
{
	unsigned int	profile;

	profile = 0;
	profile |= pieces[i].mask[0];
	profile |= (pieces[i].mask[1]) >> (sizeof(int) * 2);
	profile |= (pieces[i].mask[2]) >> (sizeof(int) * 4);
	profile |= (pieces[i].mask[3]) >> (sizeof(int) * 6);
	return (profile);
}

/*
** piece_align pushes the piece to the leftmost bit of each int and to the top
** of the array.
*/

static void			piece_align(t_piece *pieces, size_t i)
{
	unsigned int	benchmark;
	size_t			x;

	benchmark = 1U << (sizeof(int) * 8 - 1);
	x = 0;
	while (!(pieces[i].mask[0] & benchmark)
			&& !(pieces[i].mask[1] & benchmark)
			&& !(pieces[i].mask[2] & benchmark)
			&& !(pieces[i].mask[3] & benchmark))
	{
		pieces[i].mask[0] <<= 1;
		pieces[i].mask[1] <<= 1;
		pieces[i].mask[2] <<= 1;
		pieces[i].mask[3] <<= 1;
	}
	while (x < 4)
	{
		if (pieces[i].mask[x] && x)
			while (x && !(pieces[i].mask[x - 1]))
			{
				pieces[i].mask[x - 1] = pieces[i].mask[x];
				pieces[i].mask[x--] = 0;
			}
		x++;
	}
}

/*
** piece_create generates a bitmask for a single piece passed as parameter.
*/

static void			piece_fill(char **tetris, t_piece *pieces, size_t i)
{
	unsigned int	mask;
	size_t			x;
	size_t			y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tetris[x][y] == '#')
			{
				mask = 1U << ((4 - y) + 27);
				pieces[i].mask[x] |= mask;
			}
			y++;
		}
		x++;
	}
	piece_align(pieces, i);
	pieces[i].profile = profile_save(pieces, i);
}

/*
** piece_init initialises every variable inside the array containing the pieces
** to 0.
*/

static void			pieces_init(t_piece *pieces, size_t nb_pieces)
{
	size_t	i;

	i = 0;
	while (i < nb_pieces)
	{
		pieces[i].mask[0] = 0;
		pieces[i].mask[1] = 0;
		pieces[i].mask[2] = 0;
		pieces[i].mask[3] = 0;
		pieces[i].x = 0;
		pieces[i].y = 0;
		pieces[i].applied = 0;
		i++;
	}
}

/*
** char_to_bit converts the char array passed as a parameter into a bitmask
** made of four integers for a given piece.
*/

t_piece				*char_to_bit(char **tetris, size_t nb_pieces)
{
	t_piece	*pieces;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(pieces = (t_piece *)malloc(sizeof(t_piece) * (nb_pieces + 1))))
		return (NULL);
	pieces_init(pieces, nb_pieces);
	while (j < nb_pieces)
	{
		piece_fill(&tetris[i], pieces, j);
		pieces[j].index = j;
		i += 5;
		j++;
	}
	pieces[j].index = j;
	pieces[j].profile = 0;
	return (pieces);
}
