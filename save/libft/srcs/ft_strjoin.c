/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:58:08 by fpayen            #+#    #+#             */
/*   Updated: 2019/01/09 19:24:13 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

/*
** ft_strjoin creates a new string of sufficient space and fills it with s1
** and s2.
*/

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s_join;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!(s_join = (char *)ft_memalloc(sizeof(char) * (s1len + s2len + 1))))
		return (NULL);
	ft_memcpy(s_join, s1, s1len);
	ft_memcpy(s_join + s1len, s2, s2len);
	return (s_join);
}
