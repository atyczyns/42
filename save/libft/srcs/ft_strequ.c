/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:13:22 by fpayen            #+#    #+#             */
/*   Updated: 2018/11/30 18:59:08 by fpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strequ returns 1 if s1 and s2 are identical, and 0 if they are not.
*/

int	ft_strequ(const char *s1, const char *s2)
{
	int		i;

	if (!(s1) && !(s2))
		return (1);
	else if (!(s1) || !(s2))
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	if (s1[i] == s2[i] && !(s1[i]))
		return (1);
	else
		return (0);
}
