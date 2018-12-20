/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 09:54:38 by atyczyns          #+#    #+#             */
/*   Updated: 2018/08/04 08:15:41 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power >= 0)
	{
		if (power == 0)
			return (1);
		else
		{
			nb = nb * ft_recursive_power(nb, power - 1);
			return (nb);
		}
	}
	else
		return (0);
}
