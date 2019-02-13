/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:28:35 by fpayen            #+#    #+#             */
/*   Updated: 2018/12/12 14:34:40 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static int	nb_len(int n)
{
	int		i;

	if (!(n))
		return (1);
	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*s_nb;
	int		i;

	i = nb_len(n);
	if (!(s_nb = (char *)ft_memalloc(sizeof(char) * (i--) + 1)))
		return (NULL);
	if (!(n))
		s_nb[0] = '0';
	else if (n < 0)
		s_nb[0] = '-';
	while (n)
	{
		s_nb[i] = ft_abs(n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (s_nb);
}
