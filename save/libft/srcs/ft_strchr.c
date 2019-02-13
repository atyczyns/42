/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:07:46 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/09 14:32:17 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*s_cpy;
	char	c_cpy;

	s_cpy = (char *)s;
	c_cpy = (char)c;
	while (*s_cpy && *s_cpy != c_cpy)
		s_cpy++;
	if (*s_cpy != c_cpy)
		s_cpy = NULL;
	return (s_cpy);
}
