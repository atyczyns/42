/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:54:36 by atyczyns          #+#    #+#             */
/*   Updated: 2019/02/07 17:08:50 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_list_dir/ft_printf_lite.c"

int		main(int ac, char **ag)
{
	struct stat		sb;
	struct dirent	*dos_dirent;
	DIR				*dos_dir;

	if (ac != 2)
		return (0);
	if (!(dos_dir = opendir(ag[1])))
		return (0);
	ft_printf_l("Nom : %s \n", ag[1]);
	if (stat(ag[1], &sb) == -1)
	{
		perror("stat");
		exit(EXIT_SUCCESS);
	}
	while ((dos_dirent = readdir(dos_dir)))
		ft_printf_l("%s, ", dos_dirent->d_name);
	ft_printf_l("\n");
	closedir(dos_dir);
	return (1);
}
