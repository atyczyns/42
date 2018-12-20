/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:25:22 by atyczyns          #+#    #+#             */
/*   Updated: 2018/11/16 11:00:31 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			i;
	int			k;
	int			negatif;
	long int	result;

	i = 0;
	k = 0;
	negatif = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	negatif = (str[i] == '-') ? -1 : 1;
	(str[i] == '+' || str[i] == '-') ? i++ : 0;
	while (str[i] <= 57 && str[i] >= 48)
	{
		result = result * 10 + (str[i++] - 48);
		if (result < 0)
			return (negatif == -1 ? 0 : -1);
	}
	return ((int)result * negatif);
}
