/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:42:11 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/30 18:34:51 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putnbr_fd writes n to the file of file descriptor fd.
*/

void	ft_putnbr_fd(int n, int fd)
{
	char	*number;

	number = ft_itoa(n);
	ft_putstr_fd(number, fd);
}
