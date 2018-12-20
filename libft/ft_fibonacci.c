/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:06:30 by atyczyns          #+#    #+#             */
/*   Updated: 2018/08/03 15:02:45 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	int rep;

	rep = 0;
	if (index >= 0)
	{
		if (index < 2)
			return (index);
		else
			return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
	}
	else
		return (-1);
}
