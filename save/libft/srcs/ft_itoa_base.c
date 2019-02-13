/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:51:11 by fpayen            #+#    #+#             */
/*   Updated: 2019/01/16 13:44:55 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

/*
** ft_itoa_base converts an integer passed as a parameter into a character
** string in a base between 2 and 16 passed as a parameter.
*/

static int	res_size(int value, int base)
{
	int i;

	if (!(value))
		return (1);
	i = 0;
	while (value)
	{
		value = value / base;
		i++;
	}
	if (value < 0)
		i++;
	return (i);
}

static char	*fill_base(int base)
{
	char	*base_arr;
	int		i;

	i = 0;
	if (!(base_arr = (char *)ft_memalloc(sizeof(char) * (base + 1))))
		return (NULL);
	while (i <= 9 && i < base)
	{
		base_arr[i] = i + '0';
		i++;
		while (i > 9 && i < base)
		{
			base_arr[i] = i - 10 + 'A';
			i++;
		}
	}
	return (base_arr);
}

char		*ft_itoa_base(int value, int base)
{
	char			*base_arr;
	char			*base_res;
	int				i;
	unsigned int	uns;

	uns = ft_abs(value);
	i = res_size(uns, base);
	if (!(base_arr = fill_base(base)))
		return (NULL);
	if (!(base_res = (char *)ft_memalloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (--i >= 0)
	{
		base_res[i] = base_arr[uns % (unsigned int)base];
		uns = uns / (unsigned int)base;
	}
	if (value < 0)
		base_res[0] = '-';
	free(base_arr);
	return (base_res);
}
