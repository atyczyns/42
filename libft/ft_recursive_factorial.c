/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 08:02:04 by atyczyns          #+#    #+#             */
/*   Updated: 2018/08/03 09:15:15 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb >= 1)
	{
		nb = nb * ft_recursive_factorial(nb - 1);
		return (nb);
	}
	if (nb == 0)
		return (1);
	else
		return (0);
}
