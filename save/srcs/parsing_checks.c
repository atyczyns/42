/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:39:17 by fpayen            #+#    #+#             */
/*   Updated: 2019/01/25 14:22:09 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <fcntl.h>
#include <unistd.h>

int	two_connected(char **area, int x, int y)
{
	if (x + 1 < 4 && area[x + 1][y] == '#')
		return (1);
	else if (x - 1 > -1 && area[x - 1][y] == '#')
		return (1);
	else if (y < 4 && area[x][y + 1] == '#')
		return (1);
	else if (y > -1 && area[x][y - 1] == '#')
		return (1);
	return (0);
}

int	three_connected(char **area, int x, int y)
{
	if (x + 1 < 4 && area[x + 1][y] == '#'
			&& x - 1 > -1 && area[x - 1][y] == '#')
		return (1);
	else if (y + 1 < 4 && area[x][y + 1] == '#'
			&& y - 1 > -1 && area[x][y - 1] == '#')
		return (1);
	else if (x + 1 < 4 && area[x + 1][y] == '#'
			&& y + 1 < 4 && area[x][y + 1] == '#')
		return (1);
	else if (x - 1 > -1 && area[x - 1][y] == '#'
			&& y - 1 > -1 && area[x][y - 1] == '#')
		return (1);
	else if (x + 1 < 4 && area[x + 1][y] == '#'
			&& y - 1 > -1 && area[x][y - 1] == '#')
		return (1);
	else if (x - 1 > -1 && area[x - 1][y] == '#'
			&& y + 1 < 4 && area[x][y + 1] == '#')
		return (1);
	return (0);
}

int	check_last_character(int fd, const char *file_name)
{
	int		return_value;
	char	buffer[BUFF_SIZE + 1];
	char	*check;
	char	*tmp;

	if (!(check = (char *)ft_memalloc(sizeof(char) * 1)) || close(fd) == -1)
		return (0);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (0);
	while ((return_value = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[return_value] = '\0';
		tmp = check;
		if (!(check = ft_strjoin(check, buffer)))
			return (0);
		ft_strdel(&tmp);
	}
	if (return_value == -1 || check[ft_strlen(check) - 1] != '\n' ||
	(check[ft_strlen(check) - 2] != '.' && check[ft_strlen(check) - 2] != '#'))
	{
		ft_strdel(&check);
		return (0);
	}
	ft_strdel(&check);
	return (1);
}
