/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:09:20 by fpayen            #+#    #+#             */
/*   Updated: 2018/12/12 16:18:48 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

/*
** ft_strtrim creates and returns a string containing a copy of s trimmed from
** whitespaces at its beginning and end.
*/

static int	is_whitespace(const char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

static int	get_size(const char *s, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] && is_whitespace(s[i]))
		i++;
	while (len > 0 && is_whitespace(s[len]))
		len--;
	while (i < len)
	{
		i++;
		j++;
	}
	return (j);
}

char		*ft_strtrim(const char *s)
{
	char	*s_trim;
	int		trim_size;
	int		i;
	int		j;

	trim_size = get_size(s, ft_strlen(s));
	if (!(s_trim = (char *)ft_memalloc(sizeof(char) * trim_size + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (is_whitespace(s[i]))
		i++;
	ft_memcpy(s_trim, s + i, trim_size);
	return (s_trim);
}
