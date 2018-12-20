/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:15:28 by atyczyns          #+#    #+#             */
/*   Updated: 2018/11/15 19:10:31 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		if (((unsigned char *)s1)[count] != ((unsigned char *)s2)[count])
		{
			return (((unsigned char *)s1)[count] -
					((unsigned char *)s2)[count]);
		}
		count++;
	}
	return (0);
}
