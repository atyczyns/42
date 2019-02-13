/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:35:03 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/30 18:46:23 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

/*
** ft_strnew creates and returns a new character string of size characters,
** terminating '\0' excluded.
*/

char	*ft_strnew(size_t size)
{
	char	*new;

	if (!(new = (char *)ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	return (new);
}
