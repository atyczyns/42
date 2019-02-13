/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:45:19 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/15 17:13:37 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	c_cpy;
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;

	i = 0;
	c_cpy = (unsigned char)c;
	dst_cpy = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	while (i < n)
	{
		dst_cpy[i] = src_cpy[i];
		if (c_cpy == dst_cpy[i])
			return (dst_cpy + i + 1);
		i++;
	}
	return (NULL);
}
