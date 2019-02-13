/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:57:35 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/30 18:37:50 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** ft_strdel frees the string pointed by as then sets as to NULL.
*/

void	ft_strdel(char **as)
{
	free(*as);
	*as = NULL;
}
