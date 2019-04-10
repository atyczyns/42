/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:17:58 by atyczyns          #+#    #+#             */
/*   Updated: 2019/04/10 11:18:55 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_all	*glob;
	int		fd;

	fd = 0;
	if (argc != 2)
	{
		ft_putendl("Usage : ./fractol [map]");
		return (0);
	}
	if (ft_init_glob(&glob) == EXIT_FAILURE)
		return (0);
	if (ft_read(argv[1], &glob->map, fd) == EXIT_FAILURE
			|| (ft_init_t_mlx(&glob->mlx) == EXIT_FAILURE))
	{
		ft_putendl("Map Error");
		ft_free_glob(&glob);
		return (0);
	}
	ft_print_map(&glob->map, &(*glob).mlx);
	ctr(glob);
	mlx_loop(glob->mlx->init);
	return (0);
}
