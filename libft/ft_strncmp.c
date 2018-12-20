/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:37:45 by atyczyns          #+#    #+#             */
/*   Updated: 2018/11/15 19:22:06 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		if ((unsigned char)s1[count] != (unsigned char)s2[count])
		{
			return ((int)(unsigned char)s1[count] - (unsigned char)s2[count]);
		}
		if (!s2[count])
			return ((int)(unsigned char)s1[count]);
		if (!s1[count])
			return ((int)-(unsigned char)s1[count]);
		count++;
	}
	return (0);
}
