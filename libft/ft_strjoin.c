/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:36:43 by atyczyns          #+#    #+#             */
/*   Updated: 2018/11/15 18:43:14 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;

	if (s1 && s2)
	{
		if (!(r = (char *)malloc(sizeof(char) * (ft_strlen(s1)
			+ ft_strlen(s2) + 1))))
			return (NULL);
		ft_strcpy(r, s1);
		ft_strcat(r, s2);
		return (r);
	}
	return (NULL);
}
