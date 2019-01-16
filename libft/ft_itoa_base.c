/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 09:29:17 by atyczyns          #+#    #+#             */
/*   Updated: 2019/01/16 13:46:22 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_itoa_base(int value, int base)
{
	int		i;
	int		neg;
	long	value2;
	char	*result;
	int		tmp;

	value2 = value;
	value2 = (value2 < 0) ? -(value2 * base) : (value2 * base);
	neg = (value < 0 && base == 10) ? -1 : 1;
	i = (value < 0 && base == 10) ? 2 : 1;
	while ((value2 /= base) >= base * base)
		++i;
	value2 = value;
	value2 = (value2 < 0) ? -(value2 * base) : (value2 * base);
	if (!(result = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	result[i + 1] = '\0';
	while (value2 >= base)
	{
		tmp = (value2 /= base) % base;
		result[i--] = (tmp <= 9) ? (tmp + '0') : (tmp + 'A' - 10);
	}
	result[i] = (value2 <= 9) ? (value2 + '0') : (value2 + 'A' - 10);
	result[0] = (neg == -1) ? '-' : result[0];
	return (result);
}
