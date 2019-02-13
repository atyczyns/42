/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:43:49 by fpayen            #+#    #+#             */
/*   Updated: 2018/12/12 15:12:17 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_memswap swaps the values of two bytes of memory.
*/

void	ft_memswap(const void *a, const void *b)
{
	unsigned char	c;

	c = *(unsigned char *)a;
	*(unsigned char *)a = *(unsigned char *)b;
	*(unsigned char *)b = c;
}
