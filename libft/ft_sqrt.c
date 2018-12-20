/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 11:52:20 by atyczyns          #+#    #+#             */
/*   Updated: 2018/08/03 13:28:24 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int rep;
	int verif;

	rep = 0;
	verif = rep * rep;
	while (verif < nb)
	{
		++rep;
		verif = rep * rep;
		if (verif == nb)
			return (rep);
	}
	return (0);
}
