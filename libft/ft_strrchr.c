/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:33:26 by atyczyns          #+#    #+#             */
/*   Updated: 2018/11/15 19:16:57 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		count;

	i = ft_strlen(s);
	count = 0;
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			while (count < i)
			{
				s++;
				count++;
			}
			return ((char *)s);
		}
		else
			i--;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}
