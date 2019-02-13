/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:07:30 by fpayen            #+#    #+#             */
/*   Updated: 2018/12/12 15:07:17 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;

	if (dst > src)
	{
		dst_cpy = (unsigned char *)dst;
		src_cpy = (unsigned char *)src;
		while (len-- > 0)
			dst_cpy[len - 1] = src_cpy[len - 1];
	}
	else if (dst < src)
		ft_memcpy(dst, src, len);
	return (dst);
}
