/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:41:18 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/30 18:18:17 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
** ft_lstmap creates a list paralel that stores the result of the application
** of f to each element of lst. It returns the first element of the newly
** created list.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*new;
	t_list	*ret;
	t_list	*tmp;

	tmp = f(lst);
	if ((ret = ft_lstnew(tmp->content, tmp->content_size)))
	{
		new = ret;
		lst = lst->next;
		while (lst)
		{
			if (!(new->next = ft_lstnew(lst->content, lst->content_size)))
				return (NULL);
			tmp = f(lst);
			new->next = tmp;
			new = new->next;
			lst = lst->next;
		}
	}
	return (ret);
}
