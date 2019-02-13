/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:27:04 by fpayen            #+#    #+#             */
/*   Updated: 2018/12/12 16:06:03 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

/*
** ft_strsplit creates and returns a two dimensional array containing separate
** sections of s split by c.
*/

static char	*get_word(const char *s, char c, int start)
{
	char	*word;
	int		i;

	i = 0;
	while (s[start] != c && s[start])
	{
		start++;
		i++;
	}
	if (!(word = (char *)ft_memalloc(sizeof(char) * (i + 1))))
		return (NULL);
	start = start - i;
	i = 0;
	while (s[start] != c && s[start])
	{
		word[i] = s[start];
		start++;
		i++;
	}
	return (word);
}

static int	get_word_nb(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			j++;
		i++;
	}
	if (*s != c && *s)
		j++;
	return (j);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**arr;
	int		w_nb;
	int		i;
	int		j;

	i = 0;
	j = 0;
	w_nb = get_word_nb(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (w_nb + 1))))
		return (NULL);
	arr[w_nb] = 0;
	while (s[i] && j < w_nb)
	{
		while (s[i] == c)
			i++;
		arr[j] = get_word(s, c, i);
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	return (arr);
}
