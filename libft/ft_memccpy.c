/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:45:09 by atyczyns          #+#    #+#             */
/*   Updated: 2018/11/15 19:14:15 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			count;
	unsigned char	*dest_;
	unsigned char	*src_;

	count = 0;
	dest_ = (unsigned char *)dest;
	src_ = (unsigned char *)src;
	while (count < n)
	{
		dest_[count] = src_[count];
		if (src_[count] == (unsigned char)c)
			return (dest + 1 + count);
		count++;
	}
	return (NULL);
}
