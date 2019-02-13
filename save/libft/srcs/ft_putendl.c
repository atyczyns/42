/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:21:24 by fpayen            #+#    #+#             */
/*   Updated: 2018/12/12 15:22:15 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** ft_putendl writes s to the standard output, then appends it with a newline.
*/

void	ft_putendl(const char *s)
{
	char	*str;

	str = ft_strjoin(s, "\n");
	write(1, str, ft_strlen(str));
}
