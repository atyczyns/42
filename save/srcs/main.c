/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 07:19:55 by fpayen            #+#    #+#             */
/*   Updated: 2019/01/30 15:04:24 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/includes/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
** error prints error on the standard output followed by a newline and returns
** the error value.
*/

static int	error(void)
{
	ft_putstr("error\n");
	return (1);
}

/*
** usage prints the usage of the program in case of wrong use.
*/

static int	usage(void)
{
	ft_putstr("usage:\t./fillit sample.fillit\n");
	return (0);
}

/*
** free_2darr deletes a two dimensional array passed as parameter.
*/

void		free_2darr(char **arr)
{
	while (*arr)
	{
		ft_memdel((void **)arr);
		arr++;
	}
}
/*static void putbits(unsigned int x)
{
	for (int i = (sizeof(int) * 8) - 1; i>= 0; i--)
		(x & (1U << i)) ? ft_putchar('1') : ft_putchar('0');
	ft_putchar('\n');
}*/
#include <stdio.h>
int			main(int ac, const char *av[])
{
	t_piece			*pieces;
	size_t			nb_pieces;
	int				fd;
	char			**array;
	unsigned int	*bitmap;

	nb_pieces = 1;
	if (ac != 2)
		return (usage());
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (error());
	if (!(array = get_tetris(fd, av[1], &nb_pieces)))
		return (error());
	if (close(fd) == -1 || !(pieces = char_to_bit(array, nb_pieces)))
		return (error());
	if (!(bitmap = biggest_square(pieces, nb_pieces)))
		return (error());
	free_2darr(array);
	size_t size = square_size(bitmap) - 1;
	while ((fd = final_square(bitmap, pieces, size, nb_pieces)) != 0)
	{
		if (fd == -1)
			return (error());
		size--;
	}
	if (!(array = bit_to_char(bitmap, pieces)))
		return (error());
	ft_putarr((const char **)array);
	free_2darr(array);
	free(bitmap);
	free(pieces);
	return (0);
}
