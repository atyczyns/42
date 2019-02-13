/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:50:55 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/30 18:47:01 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** ft_strnlen returns the number of characters in str up to max.
*/

size_t	ft_strnlen(const char *str, size_t max)
{
	size_t	i;

	i = 0;
	while (str[i] && i < max - 1)
		i++;
	return (i);
}
