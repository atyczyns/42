/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:00:27 by atyczyns          #+#    #+#             */
/*   Updated: 2019/02/07 14:54:07 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <dirent.h>

int		main(int ac, char **ag)
{
	struct dirent	*dos_dirent;
	DIR				*dos_dir;
	if (ac != 2)
		return (0);
	if (!(dos_dir = opendir(ag[1])))
		return (0);
	while ((dos_dirent = readdir(dos_dir)))
		ft_putendl(dos_dirent->d_name);
	closedir(dos_dir);
	return (1);
}