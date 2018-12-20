/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:42:11 by atyczyns          #+#    #+#             */
/*   Updated: 2018/12/18 09:46:05 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_itoa_base(int value, int base);

int		main(void)
{
	int		coucou;
	int		base;
	char	*rep;

	base = 10;
	coucou = 247483648;
	rep = ft_itoa_base(coucou, base);
	printf("resultat = %s\n", rep);
	return (0);
}
