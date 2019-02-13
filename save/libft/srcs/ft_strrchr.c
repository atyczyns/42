/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:40:43 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/15 15:18:14 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*s_cpy;
	char	c_cpy;

	i = ft_strlen(s);
	s_cpy = (char *)s;
	c_cpy = (char)c;
	while (i > 0 && s_cpy[i] != c_cpy)
		i--;
	if (s_cpy[i] != c_cpy)
	{
		s_cpy = NULL;
		return (s_cpy);
	}
	return (&s_cpy[i]);
}
