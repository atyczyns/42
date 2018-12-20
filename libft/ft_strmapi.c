/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:39:00 by atyczyns          #+#    #+#             */
/*   Updated: 2018/11/15 13:40:19 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = -1;
	if (!s)
		return (NULL);
	if (!(result = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (++i < ft_strlen(s))
		result[i] = f(i, s[i]);
	return (result);
}
