/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:31:46 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/30 18:10:39 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstiter applies a given function to every link of a list passed as
** parameter.
*/

void	ft_lstiter(t_list *lst, void (*f) (t_list *elem))
{
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
