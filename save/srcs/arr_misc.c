/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:43:30 by fpayen            #+#    #+#             */
/*   Updated: 2019/01/30 15:02:56 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <string.h>

static void	swap_u(unsigned int *a, unsigned int *b)
{
	unsigned int	c;

	c = *a;
	*a = *b;
	*b = c;
}

static void	swap_t(size_t *a, size_t *b)
{
	size_t	c;

	c = *a;
	*a = *b;
	*b = c;
}

void		pieces_reset(t_piece *piece)
{
	size_t	i;

	i = 0;
	while (piece[i].profile)
	{
		piece[i].mask[0] <<= piece[i].x;
		piece[i].mask[1] <<= piece[i].x;
		piece[i].mask[2] <<= piece[i].x;
		piece[i].mask[3] <<= piece[i].x;
		piece[i].x = 0;
		piece[i].y = 0;
		piece[i].applied = 0;
		i++;
	}
}

t_piece		*pieces_cpy(t_piece *piece, size_t nb_pieces)
{
	t_piece	*copy;
	size_t	i;

	i = 0;
	if (!(copy = (t_piece *)malloc(sizeof(t_piece) * nb_pieces + 1)))
		return (NULL);
	while (piece[i].profile)
	{
		copy[i].mask[0] = piece[i].mask[0];
		copy[i].mask[1] = piece[i].mask[1];
		copy[i].mask[2] = piece[i].mask[2];
		copy[i].mask[3] = piece[i].mask[3];
		copy[i].x = piece[i].x;
		copy[i].y = piece[i].y;
		copy[i].profile = piece[i].profile;
		copy[i].index = piece[i].index;
		copy[i].applied = piece[i].applied;
		i++;
	}
	return (copy);
}

void		piece_swap(t_piece *piece, size_t i, size_t j)
{
	swap_u(piece[i].mask, piece[j].mask);
	swap_u(piece[i].mask + 1, piece[j].mask + 1);
	swap_u(piece[i].mask + 2, piece[j].mask + 2);
	swap_u(piece[i].mask + 3, piece[j].mask + 3);
	swap_t(&(piece[i].x), &(piece[j].x));
	swap_t(&(piece[i].y), &(piece[j].y));
	swap_u(&(piece[i].profile), &(piece[j].profile));
	swap_t(&(piece[i].index), &(piece[j].index));
	swap_t(&(piece[i].applied), &(piece[j].applied));
}
