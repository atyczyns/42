/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:59:24 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/30 18:37:04 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strclr sets every character of s to '\0'.
*/

void	ft_strclr(char *s)
{
	ft_bzero(s, ft_strlen(s));
}
