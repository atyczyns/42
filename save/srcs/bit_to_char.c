/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_to_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 09:25:20 by fpayen            #+#    #+#             */
/*   Updated: 2019/01/29 15:52:40 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <string.h>

/*
** fill_square fills in the spaces occupied by the pieces with appropriate
** characters.
*/

static void		fill_square(char **final_square, t_piece *pieces)
{
	unsigned int	buffer;
	size_t			i;
	size_t			buff_count;

	i = 0;
	while (pieces[i].profile)
	{
		buffer = 1U << (sizeof(int) * 8 - 1);
		buff_count = 0;
		while (buffer)
		{
			if (buffer & pieces[i].profile)
				final_square[pieces[i].y + (buff_count / 8)]
					[pieces[i].x + (buff_count % 8)] = 'A' + pieces[i].index;
			buffer >>= 1;
			buff_count++;
		}
		i++;
	}
}

/*
** square_size calculates the size of the array to generate.
*/

size_t			square_size(unsigned int *square)
{
	size_t			i;
	size_t			size;
	unsigned int	benchmark;

	size = 14;
	benchmark = 16383 << (sizeof(int) * 8 - (size - 1));
	while (!square[size - 1])
	{
		i = 0;
		while (i < size)
		{
			if ((benchmark | square[i]) != benchmark)
				return (size);
			i++;
		}
		size--;
		benchmark <<= 1;
	}
	return (size);
}

/*
** bit_to_char converts the provided bitmap into a two dimensional char array.
*/

char			**bit_to_char(unsigned int *square, t_piece *pieces)
{
	char	**final_square;
	size_t	dimensions;
	size_t	i;

	dimensions = square_size(square);
	i = 0;
	if (!(final_square = (char **)malloc(sizeof(char *) * (dimensions + 1))))
		return (NULL);
	final_square[dimensions] = NULL;
	while (i < dimensions)
	{
		if (!(final_square[i] = (char *)ft_memalloc(sizeof(char)
						* (dimensions + 1))))
			return (NULL);
		ft_memset((void *)final_square[i], '.', dimensions);
		i++;
	}
	fill_square(final_square, pieces);
	return (final_square);
}
