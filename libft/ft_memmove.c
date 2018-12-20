/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:04:07 by atyczyns          #+#    #+#             */
/*   Updated: 2018/11/15 19:04:41 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	count;

	count = 0;
	if (dest > src)
	{
		while (count < n)
		{
			((unsigned char*)dest)[n - 1] = ((unsigned char*)src)[n - 1];
			n--;
		}
	}
	else
	{
		while (count < n)
		{
			((unsigned char*)dest)[count] = ((unsigned char*)src)[count];
			count++;
		}
	}
	return ((unsigned char *)dest);
}
