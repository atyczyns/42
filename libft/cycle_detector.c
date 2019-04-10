/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:33:10 by atyczyns          #+#    #+#             */
/*   Updated: 2019/04/02 13:35:47 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le .h a pas oublier"

int		cycle_detector(const t_list *list)
{
	t_list	*a;
	t_list	*b;

	a = list;
	b = list;
	while (a->next && b->next && b->next->next)
	{
		a = a->next;
		b = b->next->next;
		if (a = b)
			return (1);
	}
	return (0);
}
