/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 09:29:17 by atyczyns          #+#    #+#             */
/*   Updated: 2018/12/11 10:57:42 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*ft_result(int value, int base, int i, int neg)
{
	int		tmp;
	int		k;
	char	*result;

	result = (char *)malloc(sizeof(char) * (i + 1));
	result[i + 1] = '\0';
	while (value >= base)
	{
		tmp = value % base;
		if (tmp <= 9)
			k = '0';
		else
			tmp = 'A' - 10;
		result[i] = tmp + k;
		--i;
		value = value / base;
	}
	if (neg == -1)
		result[0] = '-';
	if (value <= 9)
		k = '0';
	else
		k = 'A' - 10;
	result[i] = value + k;
	return (result);
}

char			*ft_itoa_base(int value, int base)
{
	int		i;
	int		cpy;
	int		neg;

	neg = 1;
	i = 1;
	if (value < 0 && base != 10)
		value = -value;
	else if (value < 0)
	{
		value = -value;
		neg = -1;
		++i;
	}
	cpy = value;
	while (cpy / base > base - 1)
	{
		++i;
		cpy = cpy / base;
	}
	return (ft_result(value, base, i, neg));
}
