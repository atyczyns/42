/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:39:09 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/30 18:20:04 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

/*
** ft_lstnew creates and returns an element of type t_list containting content
** and content_size. If content is null, content_size will always be 0.
*/

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list			*link;
	unsigned char	*data;

	if (!(link = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		data = (unsigned char *)content;
		if (!(link->content = malloc(sizeof(unsigned char) * content_size)))
			return (NULL);
		link->content = ft_memcpy(link->content, data, content_size);
		link->content_size = content_size;
	}
	else
	{
		link->content = NULL;
		link->content_size = 0;
	}
	link->next = NULL;
	return (link);
}
