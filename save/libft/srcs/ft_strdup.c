/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:39:21 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/15 15:13:11 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	cpylen;

	cpylen = ft_strlen(s1) + 1;
	if (!(s2 = (char *)malloc(sizeof(char) * cpylen)))
		return (NULL);
	ft_memcpy(s2, s1, cpylen);
	return (s2);
}
