/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:06:04 by fpayen            #+#    #+#             */
/*   Updated: 2018/12/12 15:47:49 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

/*
** ft_strmap creates a parallel string to s that stores the result of the
** application of f to each character of s. It returns a pointer to the first
** character of the newly created string.
*/

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*f_res;
	int		i;

	if (!(f_res = (char *)ft_memalloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i++])
		f_res[i] = f(s[i]);
	return (f_res);
}