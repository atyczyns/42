/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:04:21 by atyczyns          #+#    #+#             */
/*   Updated: 2018/11/15 14:06:26 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_blank(char s)
{
	if (s == ' ' || s == ',' || s == '\n' || s == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*result;

	start = 0;
	if (!s)
		return (NULL);
	end = ft_strlen(s);
	while (ft_blank(s[start]) && start < end)
		start++;
	if (start == end)
	{
		if (!(result = ft_strsub(s, 0, 0)))
			return (NULL);
		return (result);
	}
	while (ft_blank(s[end - 1]) && end > 0)
		end--;
	result = ft_strsub(s, start, end - start);
	return (result);
}
