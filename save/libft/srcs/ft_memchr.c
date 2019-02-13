/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:46:19 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/11 17:06:16 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_cpy;
	unsigned char	c_cpy;

	s_cpy = (unsigned char *)s;
	c_cpy = (unsigned char)c;
	while (n > 1 && c_cpy != *s_cpy)
	{
		s_cpy++;
		n--;
	}
	if (n == 1 && c_cpy != *s_cpy)
		s_cpy = NULL;
	return (s_cpy);
}
