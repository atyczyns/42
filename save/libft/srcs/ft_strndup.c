/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:55:22 by fpayen            #+#    #+#             */
/*   Updated: 2018/12/12 15:57:37 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strndup(const char *s1, size_t max)
{
	char	*s2;
	size_t	cpylen;

	cpylen = ft_strnlen(s1, max);
	if (!(s2 = (char *)ft_memalloc(sizeof(char) * cpylen + 1)))
		return (NULL);
	ft_memcpy(s2, s1, cpylen);
	return (s2);
}
