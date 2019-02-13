/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:19:12 by fpayen            #+#    #+#             */
/*   Updated: 2018/12/12 15:58:08 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** ft_strnequ returns 1 if s1 and s2 are identical within n characters, and
** 0 if they are not.
*/

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!(s1) && !(s2))
		return (1);
	else if (!(s1) || !(s2))
		return (0);
	i = 0;
	while (s1[i] == s2[i] && i < n - 1 && s1[i])
		i++;
	if (s1[i] == s2[i] || (s1[i] == s2[i] && !(s1[i])))
		return (1);
	else
		return (0);
}
