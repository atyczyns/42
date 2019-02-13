/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:53:29 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/15 19:47:30 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strrdup(const char *s1)
{
	char	*s2;
	size_t	cpylen;

	cpylen = ft_strlen(s1) + 1;
	if (!(s2 = (char *)malloc(sizeof(char) * cpylen)))
		return (NULL);
	ft_strrcpy(s2, s1);
	return (s2);
}
