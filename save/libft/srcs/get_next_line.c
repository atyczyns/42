/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:26:11 by fpayen            #+#    #+#             */
/*   Updated: 2019/01/09 19:23:41 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static char		*buff_save(int rd_value, const char *buffer, char *ln,
								t_list **lstat)
{
	char	*new;
	int		end;
	int		i;

	end = ft_strclen(ln, '\n');
	if (!(new = ft_strndup(ln, end + 1)))
		return (NULL);
	if (rd_value)
	{
		i = ft_strclen(buffer, '\n');
		ft_memdel(&((*lstat)->content));
		if (!((*lstat)->content = ft_strdup(buffer + (i + 1))))
			return (NULL);
	}
	return (new);
}

static int		buff_cpy(const int fd, char **ln, t_list **lstat)
{
	int		rd_value;
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;

	while ((rd_value = read(fd, buffer, BUFF_SIZE)) && rd_value != -1)
	{
		buffer[rd_value] = '\0';
		tmp = *ln;
		if (!(*ln = ft_strjoin(*ln, buffer)))
			return (-1);
		ft_memdel((void *)&tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	tmp = *ln;
	if (!(*ln = buff_save(rd_value, buffer, *ln, lstat)))
		return (-1);
	ft_memdel((void *)&tmp);
	return (rd_value);
}

static int		buff_restore(t_list **lstat, char **line)
{
	char	*tmp;
	int		i;

	i = ft_strclen((*lstat)->content, '\n');
	if (!(*line = ft_strndup((*lstat)->content, i + 1)))
		return (-1);
	tmp = (char *)(*lstat)->content;
	if (ft_strchr((*lstat)->content, '\n'))
	{
		if (!((*lstat)->content = ft_strdup((*lstat)->content + i + 1)))
			return (-1);
		ft_memdel((void *)&tmp);
		return (0);
	}
	else
	{
		if (!((*lstat)->content = ft_strdup((*lstat)->content + i)))
			return (-1);
		ft_memdel((void *)&tmp);
		return (1);
	}
}

static t_list	*fd_check(const size_t fd, t_list **fdstat)
{
	t_list	*check;

	if (*fdstat)
	{
		check = *fdstat;
		while (check->next && check->content_size != fd)
			check = check->next;
		if (check->content_size != fd)
		{
			if (!(check->next = ft_lstnew("", 1)))
				return (NULL);
			check = check->next;
			check->content_size = fd;
		}
		return (check);
	}
	else
	{
		if (!(*fdstat = ft_lstnew("", 1)))
			return (NULL);
		(*fdstat)->content_size = fd;
		return (*fdstat);
	}
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*fdstat = NULL;
	t_list			*lstat;
	int				rd_result;
	int				buff_check;

	if (fd < 0 || !line)
		return (-1);
	if (!(lstat = fd_check((size_t)fd, &fdstat)))
		return (-1);
	if ((buff_check = buff_restore(&lstat, line)) < 0)
		return (-1);
	if (!buff_check)
		return (1);
	if ((rd_result = buff_cpy(fd, line, &lstat)) == -1)
		return (-1);
	if (!rd_result && !(**line) && !(*(char *)(lstat->content)))
	{
		ft_lstpull_size(&fdstat, fd);
		return (0);
	}
	else
		return (1);
}
