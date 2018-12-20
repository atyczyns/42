/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 09:03:12 by atyczyns          #+#    #+#             */
/*   Updated: 2018/08/04 17:36:12 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		i;

	i = nb - 1;
	if (nb >= 1 && nb <= 12)
	{
		while (i >= 1)
		{
			nb = nb * i;
			--i;
		}
		return (nb);
	}
	else
	{
		if (nb == 0)
			return (1);
		else
			return (0);
	}
}
