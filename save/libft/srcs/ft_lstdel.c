/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:14:49 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/30 18:14:16 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

/*
** ft_lstdel applies del to every element of lst before deleting them.
*/

void	ft_lstdel(t_list **lst, void (*del) (void *, size_t))
{
	t_list	*temp;

	while (*lst)
	{
		temp = *lst;
		del((*lst)->content, (*lst)->content_size);
		*lst = (*lst)->next;
		free(temp);
	}
}
