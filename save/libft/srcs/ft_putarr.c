/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:05:25 by fpayen            #+#    #+#             */
/*   Updated: 2019/01/09 19:49:57 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** ft_putarr writes arr to the standard output with a \n between each element.
*/

void	ft_putarr(const char **arr)
{
	while (*arr)
	{
		ft_putendl(*arr);
		arr++;
	}
}
