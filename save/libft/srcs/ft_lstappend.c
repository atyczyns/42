/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:50:04 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/30 18:12:28 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstappend adds new to the end of lst.
*/

void	ft_lstappend(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	tmp = ft_lstend(tmp);
	tmp->next = new;
}
