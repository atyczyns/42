/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:25:43 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/30 18:33:53 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putnbr writes n to the standard output.
*/

void	ft_putnbr(int n)
{
	char	*number;

	number = ft_itoa(n);
	ft_putstr(number);
}
