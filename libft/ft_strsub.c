/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:03:22 by atyczyns          #+#    #+#             */
/*   Updated: 2018/11/15 14:04:13 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	char	*result;

	count = 0;
	if (!(result = ft_strnew(len)) || !s)
		return (NULL);
	while (count++ < start)
		s++;
	result = ft_strncpy(result, s, len);
	return (result);
}
