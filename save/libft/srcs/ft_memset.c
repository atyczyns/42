/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:12:58 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/09 14:31:18 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	c_cpy;
	unsigned char	*b_cpy;

	c_cpy = (unsigned char)c;
	b_cpy = (unsigned char *)b;
	while (len > 0)
	{
		*b_cpy = c_cpy;
		b_cpy++;
		len--;
	}
	return (b);
}
