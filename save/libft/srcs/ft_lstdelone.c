/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:58:41 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/30 18:15:09 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

/*
** ft_lstdelone applies del to the first element of lst.
*/

void	ft_lstdelone(t_list **lst, void (*del) (void *, size_t))
{
	del((*lst)->content, (*lst)->content_size);
	free(*lst);
	*lst = NULL;
}
