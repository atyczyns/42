/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:37:34 by atyczyns          #+#    #+#             */
/*   Updated: 2018/11/15 13:38:43 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	if (!(result = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++i])
		result[i] = f(s[i]);
	return (result);
}
