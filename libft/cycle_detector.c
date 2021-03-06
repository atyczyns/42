/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:33:10 by atyczyns          #+#    #+#             */
/*   Updated: 2019/04/10 12:03:24 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct     s_list
{
	int            data;
	struct s_list  *next;
}                  t_list;

int		cycle_detector(const t_list *list)
{
	const	t_list	*a;
	const	t_list	*b;

	a = list;
	b = list;
	while (a->next && b->next && b->next->next)
	{
		a = a->next;
		b = b->next->next;
		if (a == b)
			return (1);
	}
	return (0);
}
