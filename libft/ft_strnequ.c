/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:40:40 by atyczyns          #+#    #+#             */
/*   Updated: 2018/11/15 13:53:29 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		if (ft_memcmp(s1, s2, count) == 0 && s1 != '\0' && s2 != '\0')
			count++;
		else
			return (0);
	}
	return (1);
}
