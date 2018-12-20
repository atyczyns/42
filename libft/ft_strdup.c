/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:55:01 by atyczyns          #+#    #+#             */
/*   Updated: 2018/11/16 13:21:28 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	int		count;
	char	*result;

	count = 0;
	len = ft_strlen(s);
	if (!(result = (char *)malloc(sizeof(char) * len + 1)) || !(s))
		return (NULL);
	while (count < len)
	{
		result[count] = s[count];
		count++;
	}
	result[count] = '\0';
	return (result);
}
