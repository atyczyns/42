/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:40:24 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/21 15:48:03 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccat(char *s1, const char *s2, const char c)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(s1);
	srclen = ft_strlen(s2);
	ft_memccpy(s1 + dstlen, s2, c, srclen);
	return (s1);
}
