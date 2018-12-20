/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:30:51 by atyczyns          #+#    #+#             */
/*   Updated: 2018/11/15 19:36:36 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;

	i = 0;
	while (str[i] == to_find[i] && str[i] != '\0' && i < len)
		i++;
	if (to_find[i] == '\0')
		return ((char *)str);
	if (str[i] == '\0' || len == 0)
		return (NULL);
	return (ft_strnstr(str + 1, to_find, (len - 1)));
}
