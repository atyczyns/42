/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:51:39 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/30 19:04:13 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

/*
** ft_strsub returns a copy of a substring in s starting at index start and
** measuring len characters.
*/

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*s_sub;

	if (!(s_sub = (char *)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_memcpy(s_sub, s + start - 1, len);
	return (s_sub);
}
