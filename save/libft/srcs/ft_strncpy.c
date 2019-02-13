/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:46:41 by fpayen            #+#    #+#             */
/*   Updated: 2018/12/12 15:56:47 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = ft_strnlen(src, len);
	ft_memcpy(dst, src, i);
	if (i < len)
		ft_bzero(dst + i, len - i);
	return (dst);
}
