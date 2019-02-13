/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:24:19 by fpayen            #+#    #+#             */
/*   Updated: 2018/12/12 15:47:30 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

/*
** ft_strmapi creates a string parallel to s that stores the restults of the
** application of f to each character of s. It returns a pointer to the first
** character of the newly created string.
*/

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*f_res;
	unsigned int	i;

	if (!(f_res = (char *)ft_memalloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i++])
		f_res[i] = f(i, s[i]);
	return (f_res);
}
