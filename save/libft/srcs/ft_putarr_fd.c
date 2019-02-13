/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:04:59 by fpayen            #+#    #+#             */
/*   Updated: 2018/12/12 15:19:57 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** ft_putarr_fd prints arr to the file of file descriptor fd with a \n between
** each element.
*/

void	ft_putarr_fd(const char **arr, int fd)
{
	while (arr)
	{
		ft_putendl_fd(*arr, fd);
		arr++;
	}
}
