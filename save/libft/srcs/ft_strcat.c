/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:56:28 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/15 15:05:52 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(s1);
	srclen = ft_strlen(s2) + 1;
	ft_memcpy(s1 + dstlen, s2, srclen);
	return (s1);
}
