/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:40:29 by fpayen            #+#    #+#             */
/*   Updated: 2018/12/18 16:13:12 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** ft_putendl_fd writes s to the file of file descriptor fd, then appends it
** with a newline.
*/

void	ft_putendl_fd(const char *s, int fd)
{
	char	*str;

	str = ft_strjoin(s, "\n");
	write(fd, str, ft_strlen(str));
}
