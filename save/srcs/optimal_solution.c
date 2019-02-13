/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:13:52 by fpayen            #+#    #+#             */
/*   Updated: 2019/01/30 15:43:18 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*static void     putbits(unsigned int x)
{
	for (int i = (sizeof(int) * 8) - 1; i >= 0; i--)
	{
		(x & (1U << i)) ? ft_putchar('1') : ft_putchar('0');
	}
	ft_putchar('\n');
}*/

static int	place_pieces(unsigned int *square, t_piece *piece, size_t size)
{
	int		check;
	size_t	y;
	size_t	i;

	i = 0;
	y = 0;
	while (piece[i].profile)
	{
		if ((check = room_check(square, piece[i], y, size)) == -1 ||
				(check == -2 && !piece[i].x))
			return (0);
		else if (check == -2 && piece[i].x)
			mask_reset(piece, i, &y);
		else if (!check)
			mask_shift_right(piece, i);
		else
		{
			mask_apply(square, piece, i, y);
			++i;
		}
	}
	return (1);
}

static int	next_position(unsigned int *square, t_piece *piece, size_t i,
		size_t size)
{
	int		check;
	size_t	y;

	check = 0;
	y = piece[i].y;
	while (check != 1)
	{
		if ((check = room_check(square, piece[i], y, size)) == -1 ||
				(check == -2 && !piece[i].x))
			return (0);
		else if (check == -2 && piece[i].x)
			mask_reset(piece, i, &y);
		else if (!check)
			mask_shift_right(piece, i);
	}
	mask_apply(square, piece, i, y);
	return (1);
}

static int	try_positions(unsigned int *square, t_piece *piece, size_t size)
{
	size_t	i;
	size_t	j;

	i = 1;
	if (!place_pieces(square, piece, size))
	{
		ft_bzero(square, sizeof(int) * 14);
		pieces_reset(piece);
		while (i > 0 && piece[i - 1].profile)
		{
			j = i - 1;
			if (piece[j].applied)
			{
				mask_remove(square, piece, j, piece[j].y);
				mask_shift_right(piece, j);
			}
			if (!next_position(square, piece, j, size))
				i--;
			else
				i++;
		}
	}
	return (i ? 1 : 0);
}

static int	piece_shift(size_t size, unsigned int *square, t_piece *piece,
		size_t i)
{
	size_t	j;
	size_t	k;

	k = i;
	ft_bzero(square, sizeof(int) * 14);
	pieces_reset(piece);
	if (try_positions(square, piece, size) == 0)
	{
		while (k > 0)
		{
			i = k;
			while (i > 0)
			{
				j = i - 1;
				if (piece[j].profile && piece[i].profile)
				{
					piece_swap(piece, i, j);
					ft_bzero(square, sizeof(int) * 14);
					pieces_reset(piece);
					if (try_positions(square, piece, size) == 1)
						return (1);
				}
				if (piece[j].profile && piece[i].profile)
					piece_swap(piece, i, j);
				i--;
			}
			--k;
		return (0);
		}
	}
	return (1);
}

int			final_square(unsigned int *square, t_piece *piece, size_t size,
		size_t nb_pieces)
{
	unsigned int	*square_cpy;
	t_piece			*piece_cpy;
	size_t			i;
//	size_t			size;

	i = 0;
	if (!(square_cpy = (unsigned int *)malloc(sizeof(int) * 14)))
		return (-1);
	if (!(piece_cpy = pieces_cpy(piece, nb_pieces)))
		return (-1);
/*	for (int n = 0; n < 14; n++)
		putbits(square[n]);
	ft_putchar('\n');*/
//	size = square_size(square);
//	place_pieces(square_cpy, piece, size);
	if (piece_shift(size, square_cpy, piece_cpy, nb_pieces) == 1
			&& (size * size) >= (4 * nb_pieces))
	{
		while (i < 14)
		{
			square[i] = square_cpy[i];
			i++;
		}
		piece_overwrite(piece, piece_cpy);
	}
	free(square_cpy);
	free(piece_cpy);
	return (i > 0 ? 1 : 0);
}
