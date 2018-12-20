/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:35:03 by atyczyns          #+#    #+#             */
/*   Updated: 2018/11/15 13:36:28 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int				i;
	unsigned int	count;

	i = 0;
	count = 0;
	if (!s || !f)
		return ;
	while (*s != '\0')
	{
		(f(count, s));
		count++;
		s++;
	}
}
