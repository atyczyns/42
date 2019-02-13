/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:50:44 by fpayen            #+#    #+#             */
/*   Updated: 2019/01/23 14:05:27 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

/*
** check_connections makes sure that all the blocks are connected.
*/

static int	check_connections(char **area, int x, int y)
{
	int		count;
	int		triple_check;

	count = 0;
	triple_check = 0;
	while (area[x] && area[x][0] != '\n')
	{
		y = 0;
		while (area[x][y])
		{
			if (area[x][y] == '#')
			{
				if (!triple_check && three_connected(area, x, y))
					triple_check = 1;
				if (two_connected(area, x, y))
					++count;
			}
			y++;
		}
		x++;
	}
	if (!triple_check)
		return (0);
	return (count);
}

/*
** check_blocks makes sure the number of blocks does not exceed the maximum.
*/

static int	check_blocks(char **area)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	while (area[x])
	{
		i = 0;
		while (area[x] && area[x][0] != '\n')
		{
			y = 0;
			while (area[x][y])
			{
				if (area[x][y] == '#')
					++i;
				++y;
			}
			++x;
		}
		if (i != 4 || (i = check_connections(area + (x / 5) * 5, 0, 0)) != 4)
			return (0);
		if (area[x])
			++x;
	}
	return (i != 4 ? 0 : 1);
}

/*
** check_format makes sure the grid has an appropriate format.
*/
#include <stdio.h>
static int	check_format(char **tetris)
{
	int		x;
	int		y;

	x = 0;
	while (tetris[x])
	{
		y = 0;
		while (tetris[x][y] && (x + 1) % 5)
		{
			if ((tetris[x][y] != '.' && tetris[x][y] != '#')
					|| ft_strlen(tetris[x]) != 4)
				return (0);
			y++;
		}
		if (tetris[x][y] && !((x + 1) % 5))
			if (!(ft_strlen(tetris[x]) == 1 && tetris[x][0] == '\n'))
				return (0);
		x++;
	}
	return (1);
}

/*
** file_to_arr reads the content of the sample file and puts them in an array.
*/

static char	**file_to_arr(const int fd, char *contents)
{
	char	**file;
	char	*tmp;
	char	*line;

	while (get_next_line(fd, &line))
	{
		tmp = contents;
		if (!(contents = ft_strjoin(contents, line)))
			return (NULL);
		ft_strdel(&tmp);
		tmp = contents;
		if (!(*line))
			if (!(contents = ft_strjoin(contents, "\n0")))
				return (NULL);
		if (*line && !(contents = ft_strjoin(contents, "0")))
			return (NULL);
		ft_strdel(&tmp);
		ft_strdel(&line);
	}
	if (!(file = ft_strsplit((const char *)contents, '0')))
		return (NULL);
	ft_strdel(&contents);
	return (file);
}

/*
** get_tetris converts the file into a grid that contains each separate piece
** or returns NULL if an error is encountered or the format is incorrect.
*/

char		**get_tetris(const int fd, const char *file_name, size_t *nb_pieces)
{
	char	**tetris;
	char	*contents;

	if (!(contents = (char *)ft_memalloc(sizeof(char))))
		return (NULL);
	if (!(tetris = file_to_arr(fd, contents)))
		return (NULL);
	while (tetris[*nb_pieces - 1])
		*nb_pieces += 1;
	if (!(tetris) || !(*tetris) || *nb_pieces > 130 || !check_format(tetris)
		|| !check_blocks(tetris) || !(check_last_character((int)fd, file_name)))
	{
		free_2darr(tetris);
		return (NULL);
	}
	*nb_pieces /= 5;
	return (tetris);
}
