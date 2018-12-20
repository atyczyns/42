/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:09:17 by atyczyns          #+#    #+#             */
/*   Updated: 2018/11/15 19:17:44 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;

	i = 0;
	while (str[i] == to_find[i] && str[i] != '\0')
		i++;
	if (to_find[i] == '\0')
		return ((char *)str);
	if (str[i] == '\0')
		return (NULL);
	return (ft_strstr(str + 1, to_find));
}
