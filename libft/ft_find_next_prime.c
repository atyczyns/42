/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 14:29:55 by atyczyns          #+#    #+#             */
/*   Updated: 2018/11/22 13:36:19 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_is_prime(int nb)
{
	int		mult;
	int		i;

	i = 2;
	mult = 0;
	if (nb < 2)
		return (0);
	else
	{
		while (i < nb)
		{
			mult = nb % i;
			++i;
			if (mult == 0)
				return (0);
		}
		return (1);
	}
}

int				ft_find_next_prime(int nb)
{
	int prems;

	prems = ft_is_prime(nb);
	if (prems == 1)
		return (nb);
	else
	{
		while (prems != 1)
		{
			++nb;
			prems = ft_is_prime(nb);
		}
		return (nb);
	}
}
