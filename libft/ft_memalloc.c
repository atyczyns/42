/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:13:21 by atyczyns          #+#    #+#             */
/*   Updated: 2018/11/15 13:14:16 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;

	if (!(mem = (unsigned char *)malloc(sizeof(unsigned char) * size)))
		return (0);
	ft_bzero(mem, size);
	return ((void *)mem);
}
