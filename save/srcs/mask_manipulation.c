/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:15:53 by fpayen            #+#    #+#             */
/*   Updated: 2019/01/29 17:07:48 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <string.h>

/*
** room_check verifies if the x and y where the piece is being placed hold
** enough room to host it and whether the piece is dipping out of the square.
*/
#include "../libft/includes/libft.h"

/*static void	putbits(unsigned int x)
{
	for (int i = (sizeof(int) * 8) - 1; i >= 0; i--)
	{
		(x & (1U << i)) ? ft_putchar('1') : ft_putchar('0');
	}
	ft_putchar('\n');
}*/

int		room_check(unsigned int *square, t_piece p, size_t y, size_t size)
{
	unsigned int	benchmark;

	benchmark = (16383 << (sizeof(int) * 8 - size));
	if ((y > size - 4 && p.mask[3]) || (y > size - 3 && p.mask[2])
			|| (y > size - 2 && p.mask[1]) || y > size - 1)
		return (-1);
	if (((benchmark | p.mask[0]) != benchmark) || ((benchmark | p.mask[1])
				!= benchmark) || ((benchmark | p.mask[2]) != benchmark)
			|| ((benchmark | p.mask[3]) != benchmark))
		return (-2);
	if (y <= size - 1 && !(p.mask[1]))
		if ((square[y] & p.mask[0]))
			return (0);
	if (y <= size - 2 && !(p.mask[2]))
		if ((square[y] & p.mask[0]) || ((square[y + 1] & p.mask[1])))
			return (0);
	if (y <= size - 3 && !(p.mask[3]))
		if ((square[y] & p.mask[0]) || (square[y + 1] & p.mask[1])
				|| (square[y + 2] & p.mask[2]))
			return (0);
	if (y <= size - 4 && p.x <= size)
		if ((square[y] & p.mask[0]) || (square[y + 1] & p.mask[1])
			|| (square[y + 2] & p.mask[2]) || (square[y + 3] & p.mask[3]))
			return (0);
	return (1);
}

/*
** mask_reset resets the mask to its initial position and puts x to 0.
*/

void	mask_reset(t_piece *piece, size_t i, size_t *y)
{
	piece[i].mask[0] <<= piece[i].x;
	piece[i].mask[1] <<= piece[i].x;
	piece[i].mask[2] <<= piece[i].x;
	piece[i].mask[3] <<= piece[i].x;
	piece[i].x = 0;
	*y += 1;
}

/*
** mask_shift_right pushes the mask to the right once and adjusts x.
*/

void	mask_shift_right(t_piece *piece, size_t i)
{
	piece[i].mask[0] >>= 1;
	piece[i].mask[1] >>= 1;
	piece[i].mask[2] >>= 1;
	piece[i].mask[3] >>= 1;
	piece[i].x += 1;
}

/*
** mask_shift_left pushes the mask to the left once and adjusts x.
*/

void	mask_shift_left(t_piece *piece, size_t i)
{
	piece[i].mask[0] <<= 1;
	piece[i].mask[1] <<= 1;
	piece[i].mask[2] <<= 1;
	piece[i].mask[3] <<= 1;
	piece[i].x -= 1;
}

/*
** mask_apply prints the mask onto the square at the provided x and y.
*/

void	mask_apply(unsigned int *square, t_piece *piece, size_t i, size_t y)
{
	size_t	j;

	j = 0;
	piece[i].y = y;
	piece[i].applied = 1;
	while (piece[i].mask[j] && j < 4)
	{
		square[y + j] |= piece[i].mask[j];
		j++;
	}/*
	for (int i = 0; i < 14; i++)
	{
		putbits(square[i]);
	}
	ft_putchar('\n');*/
}
