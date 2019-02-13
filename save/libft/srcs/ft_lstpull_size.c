/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpull_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:50:44 by fpayen            #+#    #+#             */
/*   Updated: 2018/12/03 17:50:27 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static void	content_del(void *content, size_t content_size)
{
	if (content)
		ft_memdel(&content);
	content_size = 0;
}

void		ft_lstpull_size(t_list **lst, size_t data_ref)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		if (tmp2->content_size == data_ref)
		{
			tmp->next = tmp2->next;
			ft_lstdelone(&tmp2, &content_del);
		}
		if (tmp->next)
			tmp = tmp->next;
	}
	if ((*lst)->content_size == data_ref)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(&tmp, &content_del);
	}
}
